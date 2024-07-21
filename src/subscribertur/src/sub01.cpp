#include "ros/ros.h"
#include "turtlesim/Pose.h"

using namespace ros;
using namespace turtlesim;

void doPose(const Pose::ConstPtr& p){
    ROS_INFO("乌龟位姿信息:x=%.2f,y=%.2f,theta=%.2f,lv=%.2f,av=%.2f",
        p->x,p->y,p->theta,p->linear_velocity,p->angular_velocity
    );
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    init(argc,argv,"sub01");
    NodeHandle nh;
    Subscriber sub=nh.subscribe<Pose>("turtle1/pose",1000,doPose);
    spin();
    /* code */
    return 0;
}
