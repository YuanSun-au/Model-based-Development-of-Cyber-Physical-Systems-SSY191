close all; clc; clear all;


%% User input

scenario    = 1;     % 1, 2 or 3

plotresults = true; % true/false
plotLinear  = false;
animate     = false;  % true/false
fps         = 30;    % frames per simulation time





%% Parameter values

% run('params.m')
m = 0.027;                  % Mass
g = 9.81;                   % Gravitational acceleration
d = 0.046;                  % Distance from center of mass to rotor axis
k = 1E-9;                   % Lift constant
b = 2.75E-11;               % Drag constant
Jx = 1.395e-5;
Jy = 1.436e-5;
Jz = 2.173e-5;
J_b = [Jx,0,0;0,Jy,0;0,0,Jz];

% Init state
%init_pos = [0;0;0];         % Position
%init_v = [0;0;0];           % Velocity
%init_a = [0;0;0];           % Acceleration
%init_angle = [0;0;0];       % Angle
%init_w = [0;0;0];           % Angular velocity



%% Linearization script

% x_states = [ p_1, p_2, p_3, v_1, v_2, v_3, phi, theta, psi, wb_1, wb_2, wb_3].';
x_lin = zeros(12,1);

% inputs = [ ctrl_1, ctrl_2, ctrl_3, ctrl_4].';
u_lin = repmat(0.027*g/4, [4 1]);

% Set following matrices in workspace: An, Bn, Cn, Dn
run('linearization.m')

fprintf('Linear state space matrices: ')
An, Bn
fprintf('States: ')
x.'
fprintf('Inputs: ')
u.'


%% Create Estimated State Feedback Controller Data

% % % % % % % % % % % DISCRETIZING MODEL

Ts = 0.01;
sysd = c2d( ss(An,Bn,Cn,0), Ts, 'zoh' );
Ad = sysd.A;
Bd = sysd.B;

% reduce state space model to [roll, pitch, w_b]
idx = [7,8,  10,11,12];
Ar = Ad(idx,idx);
Br = Bd(idx,:);
H = zeros(3,length(idx));  H(1,1) = 1; H(2,2) = 1; H(3,5) = 1;

svd(ctrb(Ar,Br));

%% % % % % % % % % % % LQR DESIGN WITH REFERENCE

Q_lqr = diag([1e1*[1e1 1e1], 1e3*[1 1 1e-2]]);
R_lqr = 1e3*eye(size(ctrl,1));

[X,K,L,info] = idare(Ar,Br,Q_lqr,R_lqr);

K_fb_ref = K

Kr = pinv( H * inv(eye(size(Ar)) + Br*K_fb_ref - Ar) * Br );


%% % % % % % % % % % % LQR DESIGN WITH INTEGRAL ACTION

Ae = [ Ar   0*H'; 
      -H    eye(size(H*H'))];
Be = [Br; 0*H*Br];

Q_lqr = diag([1e6*[1e1 1e1], 1e4*[1e1 1e1 1],1e3*[1 1 1e-2]]);
R_lqr = 1e3*eye(size(ctrl,1));

svd(ctrb(Ae,Be));
[X,K,L,info] = idare(Ae,Be,Q_lqr,R_lqr)

K_fb_int = K;

% K_fb_int(:,[1,3,6])=0;


%% simulate


% state variables initial conditions
x0 = [0 0 0  0 0 0  deg2rad(0) deg2rad(0) deg2rad(0) 0 0 0]';
ref_roll_pitch_yawrate  = [30 30 0]';

% state variables initial conditions
x0 = [0 0 0  0 0 0  deg2rad(20) deg2rad(20) deg2rad(0) 0 0 0]';
ref_roll_pitch_yawrate  = [0 0 0]';

ref_base_thrust         = 0;
sim('closed_loop')


%% Plot

if plotresults

    NUMCOLUMNS = 3;
    
    figure('Color','white','Position',[235  372  856  507]);

%                Signal Name       Title            Unit    Legend for each element in the array
%     vars2plot = {'motor_signals', 'Motor inputs',   '',     {'Motor 1','Motor 2','Motor 3','Motor 4'};
%                   'pos',          'Position',       'm',    {'x','y','z'} ;
%                   'eul_angle',    'Angle',          'deg',  {'roll','pitch','yaw'};
%                   'acc',          'Accelerometer',  'm/s^2',{'x','y','z'}};
    vars2plot = {'eul_angle',    'Euler angle',             'deg',  {'roll','pitch','yaw'};
                 'gyro_data',    'Angular velocity',  'deg/s',{'w_b_x','w_b_y','w_b_z'}};

    for i=1:size(vars2plot,1)  %logsout.numElements

        log2plot = logsout.find( vars2plot{i,1} );

        for j=1:size(log2plot.Values.Data,2)
            subplot( size(vars2plot,1) , NUMCOLUMNS, (i-1)*NUMCOLUMNS+j )
            hold on, grid on;
            plot( log2plot.Values.Time,  log2plot.Values.Data(:,j), '-', 'LineWidth',2, 'DisplayName', vars2plot{i,4}{j} )
            title(sprintf('%s - %s', vars2plot{i,2}, vars2plot{i,4}{j} ), 'Interpreter','none')
            xlabel('time [s]');
            ylabel(sprintf('%s [%s]', vars2plot{i,2}, vars2plot{i,3}), 'Interpreter','none');
            legend
        end
    end
    sgtitle('Simulation non-linear model');
end

% fp.savefig('sim-stab')
% fp.savefig('sim-ref')


%% Plot linearized trajectories

if plotresults && plotLinear
    
    NUMCOLUMNS = 3;

    figure('Color','white','Position',[1025   387   854   505]);

    %             Signal Name       Title            Unit    Legend for each element in the array
%     vars2plotL = {'motor_signals',  'Motor inputs',       '',       {'Motor 1','Motor 2','Motor 3','Motor 4'};
%                   'Pos_L',          'Position',       'm',      {'x','y','z'} ;
%                   'Vel_L',          'Velocity',       'm/s',    {'x','y','z'} ;
%                   'Ang_L',          'Angle',          'deg',    {'roll','pitch','yaw'};
%                   'Ang_Vel_L',      'Angle Velocity', 'rad/s',  {'roll','pitch','yaw'};
%                   };
    vars2plotL = {'Ang_L',          'Euler angle',          'deg',  {'roll','pitch','yaw'};
                  'Ang_Vel_L',      'Angular Velocity', 'deg/s',{'w_b_x','w_b_y','w_b_z'}};

    for i=1:size(vars2plotL,1)  %logsout.numElements

        log2plot = logsout.find( vars2plotL{i,1} );

        for j=1:size(log2plot.Values.Data,2)
            subplot( size(vars2plotL,1) , NUMCOLUMNS, (i-1)*NUMCOLUMNS+j )
            hold on, grid on;
            plot( log2plot.Values.Time,  log2plot.Values.Data(:,j), '-', 'LineWidth',2, 'DisplayName', vars2plotL{i,4}{j} )
            title(sprintf('%s - %s', vars2plotL{i,2}, vars2plotL{i,4}{j} ), 'Interpreter','none')
            xlabel('time [s]');
            ylabel(sprintf('%s [%s]', vars2plotL{i,2}, vars2plotL{i,3}), 'Interpreter','none');
            legend
        end
    end
    sgtitle('Simulation linear model');
end



%%



if plotresults && plotLinear
    
    NUMCOLUMNS = 3;

    figure('Color','white','Position',[1025   387   854   505]);

    vars2plot = {'eul_angle',    'Euler angle',             'deg',  {'roll','pitch','yaw'};
                 'gyro_data',    'Angular velocity',  'deg/s',{'w_b_x','w_b_y','w_b_z'}};
             
    vars2plotL = {'Ang_L',          'Euler angle',          'deg',  {'roll','pitch','yaw'};
                  'Ang_Vel_L',      'Angular Velocity', 'deg/s',{'w_b_x','w_b_y','w_b_z'}};

    for i=1:size(vars2plotL,1)  %logsout.numElements

        log2plot  = logsout.find( vars2plot{i,1} );
        log2plotL = logsout.find( vars2plotL{i,1} );

        for j=1:size(log2plot.Values.Data,2)
            subplot( size(vars2plotL,1) , NUMCOLUMNS, (i-1)*NUMCOLUMNS+j )
            hold on, grid on;
            plot( log2plot.Values.Time,  log2plot.Values.Data(:,j), '-',  'LineWidth',2, 'DisplayName', 'non-linear' )
            plot( log2plotL.Values.Time,  log2plotL.Values.Data(:,j), '--', 'LineWidth',2, 'DisplayName', 'linear' )
            title(sprintf('%s - %s', vars2plotL{i,2}, vars2plotL{i,4}{j} ), 'Interpreter','none')
            xlabel('time [s]');
            ylabel(sprintf('%s [%s]', vars2plotL{i,2}, vars2plotL{i,3}), 'Interpreter','none');
            legend
        end
    end
    sgtitle('Simulation linear model');
end

fp.savefig('diff-lin-nonlin-WORKS')

%%

figure('Color','white','Position',[507  575  690  271]);

pln = {logsout.find('eul_angle'), logsout.find('Ang_L'), logsout.find('gyro_data'), logsout.find('Ang_Vel_L')}

subplot(1,2,1)
hold on, grid on;
plot( pln{1}.Values.Time,  pln{1}.Values.Data(:,1), '-', 'LineWidth',3, 'DisplayName', 'nonlinear' )
plot( pln{1}.Values.Time,  pln{2}.Values.Data(:,1), '--', 'LineWidth',3, 'DisplayName', 'linear' )
title('Roll angle', 'Interpreter','none')
xlabel('time [s]');
ylabel('roll angle [deg]', 'Interpreter','none');
legend

subplot(1,2,2)
hold on, grid on;
plot( pln{1}.Values.Time,  pln{3}.Values.Data(:,1), '-', 'LineWidth',3, 'DisplayName', 'nonlinear' )
plot( pln{1}.Values.Time,  pln{4}.Values.Data(:,1), '--', 'LineWidth',3, 'DisplayName', 'linear' )
title('angular velocity x', 'Interpreter','none')
xlabel('time [s]');
ylabel('w_b_x [deg/s]', 'Interpreter','none');
legend

% fp.savefig('sim-lin-nonlin')

%% Animate

if animate

    anim = bitcrazy_animation();
    anim.play( fps,...
               logsout.find('pos').Values.Time,...  
               logsout.find('pos').Values.Data,...
               logsout.find('eul_angle').Values.Data, ...
               logsout.find('motor_signals').Values.Data);
end

