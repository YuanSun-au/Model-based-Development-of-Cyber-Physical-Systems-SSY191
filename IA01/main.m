clear all; close all; clc;

%% Problem 1

% Rotation matrices (can be used with symbolic variables)
rotz = @(th) [cos(th) -sin(th) 0; sin(th) cos(th) 0; 0 0 1];
rotx = @(th) [1 0 0; 0 cos(th) -sin(th); 0 sin(th) cos(th)];
roty = @(th) [cos(th) 0 sin(th); 0 1 0; -sin(th) 0 cos(th)];

% The rotation YXZ is given by: