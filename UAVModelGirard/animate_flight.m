fullfile(matlabroot, "toolbox", "aero", "animation")

ts = timeseries([convang(tdata(:,[3 2]),'deg','rad') ...
                 tdata(:,4) convang(tdata(:,5:7),'deg','rad')],tdata(:,1));