
%% variables

m = 0.027;                  % Mass
g = 9.81;                   % Gravitational acceleration
d = 0.046;                  % Distance from center of mass to rotor axis
k = 1E-9;                   % Lift constant
b = 2.75E-11;               % Drag constant
Jx = 1.395e-5;
Jy = 1.436e-5;
Jz = 2.173e-5;
J_b = [Jx,0,0;0,Jy,0;0,0,Jz];


pos= sym('p_',[3,1]);
d_pos= sym('d_p_',[3,1]);

v = sym('v_',[3,1]);
d_v = sym('d_v_',[3,1]);

% a = sym('a_',[3,1]);

syms phi theta psi
syms d_phi d_theta d_psi

angle   = [phi theta psi].';
d_angle = [d_phi d_theta d_psi].';


syms dphi dtheta dpsi
syms d_dphi d_dtheta d_dpsi

dangle   = [dphi dtheta dpsi].';
d_dangle = [d_dphi d_dtheta d_dpsi].';

% w= sym('w_',[3,1]);
w_b= sym('wb_',[3,1]);
d_w_b= sym('dwb_',[3,1]);

ctrl = sym('ctrl_',[4,1]);

%% Set equations

rotx  = [1 0        0; 
          0 cos(phi) -sin(phi);
          0 sin(phi) cos(phi)];
roty  = [cos(theta)  0 sin(theta); 
          0           1 0; 
          -sin(theta) 0 cos(theta)];
rotz  = [cos(psi) -sin(psi) 0; 
          sin(psi)  cos(psi) 0; 
          0         0        1];
R_b2w = (rotx * roty * rotz);

rotorspeed = sqrt(abs(ctrl)/k);
Tz_aer_drag = b * (rotorspeed).^2;

Tx = d*cos(pi/4) * (ctrl(3) + ctrl(4) - ctrl(1) - ctrl(2));
Ty = d*cos(pi/4) * (ctrl(2) + ctrl(3) - ctrl(1) - ctrl(4));
Tz = - Tz_aer_drag(1) - Tz_aer_drag(3) + Tz_aer_drag(2) + Tz_aer_drag(4) ;
T_b = [Tx Ty Tz].';


% transformation matrix from euler angles velocity to angular velocity
T_angleder2w = [ 1,        0,            sin(theta)
                  0, cos(phi),  -cos(theta)*sin(phi)
                  0, sin(phi),   cos(phi)*cos(theta)];

% w == R_b2w * w_b;
% w == T_angleder2w * dangle;

% w_b = R_b2w.' * T_angleder2w * dangle;
% dw_b = jacobian(w_b,angle)*dangle + jacobian(w_b,dangle)*d_dangle;
              

eqs = [ m * d_v   == -[0 0 m*g].' + R_b2w * [0 0 sum(ctrl)].';
            d_pos == v;
        
       J_b * d_w_b == cross( -w_b, J_b * w_b ) + T_b;      
           d_angle == T_angleder2w \ R_b2w * w_b;
        ];
    
%% Linearize model 

x    = [pos;   v;     angle;   w_b];
xdot = [d_pos; d_v; d_angle; d_w_b];
u    = ctrl;
    
eqs = lhs(eqs) - rhs(eqs);
A = -jacobian(eqs, xdot) \ jacobian(eqs, x);
B = -jacobian(eqs, xdot) \ jacobian(eqs, u);

% for i=1:size(A,1)
%     sum(sum(jacobian(A(i,:),xdot)))
%     sum(sum(jacobian(b(i,:),xdot)))
% end

An = double(subs(A, [x;ctrl] , [x_lin; u_lin] ));
Bn = double(subs(B, [x;ctrl] , [x_lin; u_lin] ));
Cn = eye(size(x,1));
Dn = zeros(size(x,1),4);
