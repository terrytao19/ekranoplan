clear; clf; clc;

load wave_param_fits.mat

windspeed = 70; % km / hr

A = wind_speed_amp_fit(windspeed);

T_x1 = wind_speed_period_fit(windspeed);
L_x1 = wind_speed_wavelength_fit(windspeed);
k_x1 = (2 * pi) / L_x1;
w_x1 = (2 * pi) / T_x1;
c_x1 = w_x1 / k_x1;

T_y1 = wind_speed_period_fit(windspeed) * 150; % Make wave slower in y direction
L_y1 = wind_speed_wavelength_fit(windspeed) * 15; % Make wave wider in y direction to better represent an ocean
k_y1 = (2 * pi) / L_y1;
w_y1 = (2 * pi) / T_y1;
c_y1 = w_y1 / k_y1;


% Add a little messiness to the wave field to better represent an ocean
T_x2 = wind_speed_period_fit(windspeed) * 5;
L_x2 = wind_speed_wavelength_fit(windspeed) * 5;
k_x2 = (2 * pi) / L_x2;
w_x2 = (2 * pi) / T_x2;
c_x2 = w_x2 / k_x2;

T_y2 = wind_speed_period_fit(windspeed);
L_y2 = wind_speed_wavelength_fit(windspeed);
k_y2 = (2 * pi) / L_y2;
w_y2 = (2 * pi) / T_y2;
c_y2 = w_y2 / k_y2;

t = 0:1:4;

x_max = 10000;
y_max = 10000;
z_max = 20;

[X, Y] = meshgrid(linspace(0, x_max, 2000));
Z = A * (cos(k_x1 * (X + c_x1 * t(1))) .* cos(k_y1 * (Y + c_y1 * t(1)))) + ...
(cos(k_x2 * (X + c_x2 * t(1))) .* cos(k_y2 * (Y + c_y2 * t(1))));
p = surf(X,Y,Z);
set(p,'LineStyle','none');
title("Modeled Wave Field")
xlim([0, 10000]);
ylim([0, 10000]);
zlim([-z_max, z_max]);
saveas(gcf, "WaveField.png")