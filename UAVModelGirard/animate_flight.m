load('simout.mat')
ts = timeseries([convang(tdata(:,[3 2]),'deg','rad') ...
                 tdata(:,4) convang(tdata(:,5:7),'deg','rad')],tdata(:,1));

[lat, lon, alt] = local2latlon(simout(9,:),simout(8,:),simout(10,:),[26.704225, 128.015727, -25]);
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
h.InitialHeading = 113;
h.OffsetDistance = 4.72;
h.OffsetAzimuth = 0;
h.InstallScenery = true;
h.DisableShaders = true;
h.TimeScaling = 5;
get(h)
GenerateRunScript(h)
system('runfg.bat &');