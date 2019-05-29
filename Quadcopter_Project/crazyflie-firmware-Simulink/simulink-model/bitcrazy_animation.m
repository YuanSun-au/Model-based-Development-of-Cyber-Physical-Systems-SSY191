classdef bitcrazy_animation
    %UNTITLED2 Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        figh
        ax_position
        ax_orientation
        
        frame
        frameh
        axes
        axesh
        thrust
        thrusth
        flighttracker
        flighttrackerh
        flighttrackerposh
        d
    end
    
    methods
        function obj = bitcrazy_animation()
            figh = figure('Color','white','Position',[140   144  1394   565]);
            
            ax_position = subplot(1,2,2);
            hold on, grid on, axis equal;
            view(90+30,30)
            title('Position Tracking');
            xlabel 'x [m]', ylabel 'y [m]', zlabel 'z [m]'
            
            ax_orientation = subplot(1,2,1);
            hold on, grid on, axis equal;
            view(90+30,30)
            title('Orientation');
            xlabel 'x [m]', ylabel 'y [m]', zlabel 'z [m]'
            
            % distance drone center to propeler center
            d = 0.046;
            
            xlim(d*1.5*[-1 1]); ylim(d*1.5*[-1 1]); zlim(d*1.5*[-1 1]); 
            
            % coordinate of propeler centers (motor 1, 2, 3, 4)
            motc = [ d*cos(pi/4) -d*cos(pi/4) 0
                    -d*cos(pi/4) -d*cos(pi/4) 0
                    -d*cos(pi/4)  d*cos(pi/4) 0
                     d*cos(pi/4)  d*cos(pi/4) 0];
            center = [0 0 0];
            
            % radius of propeler
            radius = 0.4*d;
            ang = linspace(0,2*pi,20).';
            circframebase = [cos(ang)*radius, sin(ang)*radius, ang.*0];
            
            % add frame and propeler lines
            frame = {[motc(1,:);center];
                      [motc(2,:);center];
                      [motc(3,:);center];
                      [motc(4,:);center];
                      circframebase + motc(1,:);
                      circframebase + motc(2,:);
                      circframebase + motc(3,:);
                      circframebase + motc(4,:)};
            for i=1:numel(frame)
                frameh(i) = plot3( frame{i}(:,1), frame{i}(:,2), frame{i}(:,3) ,'LineWidth',2, 'Color','b');
            end
            
            % add axis quiver lines
            axes = d/3*eye(3);
            axesc = {'r','g','b'};
            for i=1:size(axes,1)
                axesh(i) = quiver3(center(1),center(2),center(3),axes(i,1),axes(i,2),axes(i,3),'LineWidth',3, 'Color',axesc{i});
            end
            
            % add thrust animation
            thrustmaxsize = d/1;
            thrust = {[motc(1,:);[0,0,thrustmaxsize]];
                      [motc(2,:);[0,0,thrustmaxsize]];
                      [motc(3,:);[0,0,thrustmaxsize]];
                      [motc(4,:);[0,0,thrustmaxsize]]};
            for i=1:numel(thrust)
                thrusth(i) = quiver3(thrust{i}(1,1),thrust{i}(1,2),thrust{i}(1,3),...
                                     thrust{i}(2,1),thrust{i}(2,2),thrust{i}(2,3),'LineWidth',3, 'Color','r');
            end
            
            % add flight tracker animation
            n = 100;
            flighttracker = nan(n,3);
            % flighttracker = rand(n,3);
            flighttrackerh = plot3(ax_position, flighttracker(:,1),flighttracker(:,2),flighttracker(:,3),...
                                   '-','LineWidth',2, 'Color',0.5*[1 1 1]);
            % set flight tracker color gradient
            cd = [uint8(hot(n)*255) uint8(ones(n,1))].';
            set(flighttrackerh.Edge, 'ColorBinding','interpolated', 'ColorData',cd)
            
            flighttrackerposh = scatter3(ax_position,0,0,0,70,'filled','o','MarkerFaceColor','k');
            
            
            % save object properties
            obj.ax_position = ax_position;
            obj.ax_orientation = ax_orientation;
            
            obj.d = d;
            obj.figh = figh;
            obj.frame  = frame;
            obj.frameh = frameh;
            obj.axes  = axes;
            obj.axesh = axesh;
            obj.thrust  = thrust;
            obj.thrusth = thrusth;
            obj.flighttracker  = flighttracker;
            obj.flighttrackerh = flighttrackerh;
            obj.flighttrackerposh = flighttrackerposh;
        end
        
        function play(obj, fps, timev, pos, eul, motor)
            figure(obj.figh)
            % Rotation matrices (can be used with symbolic variables)
            rotx = @(th) [1 0 0; 0 cos(th) -sin(th); 0 sin(th) cos(th)];
            roty = @(th) [cos(th) 0 sin(th); 0 1 0; -sin(th) 0 cos(th)];
            rotz = @(th) [cos(th) -sin(th) 0; sin(th) cos(th) 0; 0 0 1];
            R_b2w = @(eul) rotx(eul(1))*roty(eul(2))*rotz(eul(3));
            
            % convert radians to degrees
            eul = deg2rad(eul);
            
            % interpole data to be equally time-spaced
            timed = (timev(1):1/fps:timev(end))';
            pos = interp1(timev, pos, timed);
            eul = interp1(timev, eul, timed);
            motor = interp1(timev, motor, timed);
            
            for t=1:numel(timed)
                % print simulation time
                % timed(t)
                % update frame and propeler lines
                newframe = obj.frame;
                for i=1:size(obj.frame,1)
                    newframe{i} = (R_b2w(eul(t,:)) * obj.frame{i}')';% + pos(t,:);
                    obj.frameh(i).XData = newframe{i}(:,1);
                    obj.frameh(i).YData = newframe{i}(:,2);
                    obj.frameh(i).ZData = newframe{i}(:,3);
                end
                % update axis quiver lines
                newaxes = (R_b2w(eul(t,:)) * obj.axes')';
                for i=1:size(obj.axes,1)
                    % obj.axesh(i).XData = pos(t,1);
                    % obj.axesh(i).YData = pos(t,2);
                    % obj.axesh(i).ZData = pos(t,3);
                    obj.axesh(i).UData = newaxes(i,1);
                    obj.axesh(i).VData = newaxes(i,2);
                    obj.axesh(i).WData = newaxes(i,3);
                end
                % update thrust animation
                for i=1:numel(obj.thrust)
                    newthrust{i} = (R_b2w(eul(t,:)) * obj.thrust{i}')';
                    obj.thrusth(i).XData = newthrust{i}(1,1);% + pos(t,1);
                    obj.thrusth(i).YData = newthrust{i}(1,2);% + pos(t,2);
                    obj.thrusth(i).ZData = newthrust{i}(1,3);% + pos(t,3);
                    obj.thrusth(i).UData = newthrust{i}(2,1) * (motor(t,i)/65536*4);
                    obj.thrusth(i).VData = newthrust{i}(2,2) * (motor(t,i)/65536*4);
                    obj.thrusth(i).WData = newthrust{i}(2,3) * (motor(t,i)/65536*4);
                end
                % update flight tracker
                for i=size(obj.flighttracker,1):-1:2
                    obj.flighttracker(i,:) = obj.flighttracker(i-1,:);
                end
                obj.flighttracker(1,:) = pos(t,:);
                obj.flighttrackerh.XData = obj.flighttracker(:,1);
                obj.flighttrackerh.YData = obj.flighttracker(:,2);
                obj.flighttrackerh.ZData = obj.flighttracker(:,3);
                
                dim = sum( ~isnan(obj.flighttrackerh.XData) );
                cd = [uint8(hot(dim)*255) uint8(ones(dim,1))].';
                set(obj.flighttrackerh.Edge, 'ColorBinding','interpolated', 'ColorData',cd)
                
                obj.flighttrackerposh.XData = pos(t,1);
                obj.flighttrackerposh.YData = pos(t,2);
                obj.flighttrackerposh.ZData = pos(t,3);
                
                sgtitle(sprintf('Simulation time: %.3f seconds',timed(t)))
                
                % update drawing
                drawnow();
            end
        end
    end
end

% anim = bitcrazy_animation()
% anim.play( logsout.find('pos').Values.Time, logsout.find('pos').Values.Data, logsout.find('eul_angle').Values.Data, logsout.find('motor_signals').Values.Data);

% timev = logsout.find('pos').Values.Time;
% pos = logsout.find('pos').Values.Data;
% eul=logsout.find('eul_angle').Values.Data;
% motor = logsout.find('motor_signals').Values.Data;

