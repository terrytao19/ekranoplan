clear; close all; clc;

wind_speed = [0, 19, 37, 56, 74, 92]; % km /hr

fetch = [0, 19, 139, 518, 1313, 2627]; % km
duration = [0, 2, 10, 23, 42, 69]; % hr
amplitude = [0, 0.27, 1.5, 4.1, 8.5, 14.8]; % m
wavelength = [0, 8.5, 33.8, 76.5, 136, 212]; % m
wave_period = [0, 3, 5.7, 8.6, 11.4, 14.3]; % s
wave_velocity = [0, 2.8, 5.9, 8.9, 11.9, 14.8]; % m/s

wind_speed_amp_fit = fit(wind_speed.', amplitude.', 'poly3');
wind_speed_wavelength_fit = fit(wind_speed.', wavelength.', 'poly2');
wind_speed_period_fit = fit(wind_speed.', wave_period.', 'poly1');


figure('Name','Wave Amplitude','NumberTitle','off');
eq = formula(wind_speed_amp_fit); %Formula of fitted equation
parameters = coeffnames(wind_speed_amp_fit); %All the parameter names
values = coeffvalues(wind_speed_amp_fit); %All the parameter values
for idx = 1:numel(parameters)
      param = parameters{idx};
      l = length(param);
      loc = regexp(eq, param); %Location of the parameter within the string
      while ~isempty(loc)     
          %Substitute parameter value
          eq = [eq(1:loc-1) num2str(values(idx)) eq(loc+l:end)];
          loc = regexp(eq, param);
      end
end
h = plot(wind_speed_amp_fit,wind_speed,amplitude) ;
legendinfo = legend(h, 'Location', 'northwest') ;
legendinfo.String{1} = "Measured Data";
legendinfo.String{2} = eq;
title("Wind Speed vs Wave Amplitude")
xlabel("Wind Speed km/hr")
ylabel("Wave Amplitude m")

saveas(gcf, "wind_speed_amplitude_fit.png")

figure('Name','Wave Length','NumberTitle','off');
eq = formula(wind_speed_wavelength_fit); %Formula of fitted equation
parameters = coeffnames(wind_speed_wavelength_fit); %All the parameter names
values = coeffvalues(wind_speed_wavelength_fit); %All the parameter values
for idx = 1:numel(parameters)
      param = parameters{idx};
      l = length(param);
      loc = regexp(eq, param); %Location of the parameter within the string
      while ~isempty(loc)     
          %Substitute parameter value
          eq = [eq(1:loc-1) num2str(values(idx)) eq(loc+l:end)];
          loc = regexp(eq, param);
      end
end
h = plot(wind_speed_wavelength_fit,wind_speed,wavelength) ;
legendinfo = legend(h, 'Location', 'northwest') ;
legendinfo.String{1} = "Measured Data";
legendinfo.String{2} = eq;
title("Wind Speed vs Wave Length")
xlabel("Wind Speed km/hr")
ylabel("Wave Length m")

saveas(gcf, "wind_speed_wavelength_fit.png")

figure('Name','Wave Period','NumberTitle','off');
eq = formula(wind_speed_period_fit); %Formula of fitted equation
parameters = coeffnames(wind_speed_period_fit); %All the parameter names
values = coeffvalues(wind_speed_period_fit); %All the parameter values
for idx = 1:numel(parameters)
      param = parameters{idx};
      l = length(param);
      loc = regexp(eq, param); %Location of the parameter within the string
      while ~isempty(loc)     
          %Substitute parameter value
          eq = [eq(1:loc-1) num2str(values(idx)) eq(loc+l:end)];
          loc = regexp(eq, param);
      end
end
h = plot(wind_speed_period_fit,wind_speed,wave_period) ;
legendinfo = legend(h, 'Location', 'northwest') ;
legendinfo.String{1} = "Measured Data";
legendinfo.String{2} = eq;
title("Wind Speed vs Wave Period")
xlabel("Wind Speed km/hr")
ylabel("Wave Period s")

saveas(gcf, "wind_speed_waveperiod_fit.png")