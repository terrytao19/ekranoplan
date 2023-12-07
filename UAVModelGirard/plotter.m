hold off
hold on
waypoints = [0,0,5;501.717105508643,908.922660414421,5;3007.34596928847,2458.44221262396,5;5143.8601437273,2189.82336415166,5;4248.4135386412,823.96084565673,5;2381.03201490461,241.3162953267,5;0,0,5];
object_poses = [500 600; 2000 2000; 4000 2000; 5000 1500; 3000 650; 1000 350];
object_sizes = [200, 250, 500, 300, 200, 200];
circle(object_poses, object_sizes)
plot(object_poses(:,1), object_poses(:,2), "or")
plot(simout(8,:),simout(9,:))
plot(waypoints(:,1), waypoints(:,2), "og")
axis equal