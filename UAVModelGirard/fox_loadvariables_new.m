
%  Initial Conditions in ENU (all vector data is represented as a column vectors)
Pos_0   = [1500; 200; 100.]; 
Pos_0   = [0; 0; 5]; % Initial position vector (m)
Vb_0    = [65.; 0; 0]'*0.3048;        % Initial velocity vector (m/s)
Euler_0 = [0; 0; 0]'*pi/180;          % Initial Euler angles    (rad)
PQR_0   = [0; 0; 0]';                 % Initial Omega           (rad/s)

% Mass and Geometric Parameters
S     = 8.;                 % surface area of wing  (ft^2)
span  = 8.;                 % wingspan              (ft)
chord = 1.;                 % chord                 (ft)
mass  = 20;                 % gross weight          (lbs)
Ixx   = 0.268;              % main moment of inertia around axis Ox (slug*sq.ft)
Iyy   = 0.640;              % main moment of inertia around axis Oy (slug*sq.ft)
Izz   = 0.884;              % main moment of inertia around axis Oz (slug*sq.ft)

% Mass and Geometric Parameters recomputation
S     = S*0.3048^2;         % surface area of wing  (m2)
span  = span*0.3048;        % wingspan              (m)
chord = chord*0.3048;       % chord                 (m)
mass = mass*0.45359237;     % gross weight          (kg)
Ixx   = Ixx*1.355817949;    % main moment of inertia around axis Ox (kg*sq.m)
Iyy   = Iyy*1.355817949;    % main moment of inertia around axis Oy (kg*sq.m)
Izz   = Izz*1.355817949;    % main moment of inertia around axis Oz (kg*sq.m)

% Aerodynamic Derivatives (all per radian)
CL0     = 3*0.076;        % lift coefficient at a = 0
CLa     = 5.097;        % lift curve slope
CLa_dot = 1.93;         % lift due to angle of attack rate
CLq     = 6.03;         % lift due to pitch rate
CLDe    = 0.738;        % lift due to elevator
CD0     = 0.0191;       % drag coefficient at a = 0
Apolar  = 0.038;        % drag curve slope
CYb     = -0.204;       % side force due to sideslip
CYDr    = 0.112;        % sideforce due to rudder
Clb     = -0.0598;      % dihedral effect
Clp     = -0.363;       % roll damping
Clr     = 0.0886;       % roll due to yaw rate
ClDa    = 0.265;        % roll control power
ClDr    = 0.0064;       % roll due to rudder
Cm0     = 0.107;        % pitch moment at a = 0
Cma     = -2.051;       % pitch moment due to angle of attack
Cma_dot = -5.286;       % pitch moment due to angle of attack rate
Cmq     = -16.52;       % pitch moment due to pitch rate
CmDe    = -2.021;       % pitch control power
Cnb     = 0.0562;       % weathercock stability
Cnp     = -0.0407;      % adverse yaw
Cnr     = -0.0439;      % yaw damping
CnDa    = -0.0296;      % aileron adverse yaw
CnDr    = -0.0377;      % yaw control power

% Standartd Atmosphere
ISA_lapse = .0065;          % Lapse rate            (degC/m) 
ISA_hmax  = 2000;           % Altitude limit        (m)
ISA_R     = 287;            % Gas Constant          (degK*m*m/s/s)
ISA_g     = 9.815;          % Gravity               (m/s/s)
ISA_rho0  = 1.225;          % Density at sea level  (kg/m/m/m)
ISA_P0    = 101325;         % Sea-level Pressure    (N/m/m)
ISA_T0    = 289;            % Sea-level Temperature (degK)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Load Wind Profile
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
load YPGwind.mat;

T = 0.05;