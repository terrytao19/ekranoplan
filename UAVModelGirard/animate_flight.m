load('simout.mat')

[lat, lon, alt] = local2latlon(simout(9,:),simout(8,:),simout(10,:),[42.3311992723208, -83.0094379267925, 5]);
ts = timeseries([convang(transpose([lat; lon]),'deg','rad') ...
                 transpose(alt) convang(transpose([simout(17,:); simout(18,:); simout(19,:)]),'deg','rad')],simout(1,:));

h = Aero.FlightGearAnimation;
h.TimeseriesSourceType = 'Timeseries';
h.TimeseriesSource = ts;
h.FlightGearBaseDirectory = 'C:\Program Files\FlightGear';
h.GeometryModelName = 'c172p';
h.DestinationIpAddress = '127.0.0.1';
h.DestinationPort = '5502';
h.AirportId = 'KSFO';
h.RunwayId = '10L';
h.InitialAltitude = 0;
h.InitialHeading = 0;
h.OffsetDistance = 4.72;
h.OffsetAzimuth = 0;
h.InstallScenery = true;
h.DisableShaders = true;
h.TimeScaling = 5;
get(h)
GenerateRunScript(h)
system('runfg.bat &');
% play(h)