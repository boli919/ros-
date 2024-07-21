#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

using namespace ros;
using namespace geometry_msgs;
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    init(argc,argv,"turtletest");
    NodeHandle nh;
    Publisher pub=nh.advertise<Twist>("turtle1/cmd_vel",10);
    Twist msg;
    msg.angular.x=0;
    msg.angular.y=0;
    msg.angular.z=1;

    msg.linear.x=1;
    msg.linear.y=0;
    msg.linear.z=0;
    Rate r(10);
    while(ok()){
        pub.publish(msg);
        spinOnce();
        r.sleep();
    }
    /* code */
    return 0;
}
