rotx = @(th) [1 0 0; 0 cos(th) -sin(th); 0 sin(th) cos(th)];
roty = @(th) [cos(th) 0 sin(th); 0 1 0; -sin(th) 0 cos(th)];
rotz = @(th) [cos(th) -sin(th) 0; sin(th) cos(th) 0; 0 0 1];

eul = sym('eul_',[3 1])
deul = sym('deul_',[3 1])
w = sym('w_',[3 1])


%% XYZ

w =   deul(1) * [1 0 0]' ...
    + deul(2) * rotx(eul(1))*[0 1 0]' ...
    + deul(3) * rotx(eul(1))*roty(eul(2))*[0 0 1]';
Txyz = equationsToMatrix(w,deul)

% Txyz =
%  
% [ 1,          0,             sin(eul_2)]
% [ 0, cos(eul_1), -cos(eul_2)*sin(eul_1)]
% [ 0, sin(eul_1),  cos(eul_1)*cos(eul_2)]


%% ZYZ

w =   deul(1) * [0 0 1]' + ...
      deul(2) * rotz(eul(1))*[0 1 0]' + ...
      deul(3) * rotz(eul(1))*roty(eul(2))*[0 0 1]';
Tzyz = equationsToMatrix(w,deul)

% Tzyz =
%  
% [ 0, -sin(eul_1), cos(eul_1)*sin(eul_2)]
% [ 0,  cos(eul_1), sin(eul_1)*sin(eul_2)]
% [ 1,           0,            cos(eul_2)]