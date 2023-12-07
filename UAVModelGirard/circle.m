function h = circle(object_poses, object_sizes)
for i = 1:size(object_poses,1)
    x = object_poses(i,1);
    y = object_poses(i,2);
    r = object_sizes(i);
    th = 0:pi/50:2*pi;
    xunit = r * cos(th) + x;
    yunit = r * sin(th) + y;
    h = plot(xunit, yunit, "k");
end