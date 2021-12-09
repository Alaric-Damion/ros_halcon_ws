#include "ros/ros.h"
#include "HalconCpp.h"


#include <ros/package.h>
#include <ros/console.h>
//#include <asr_halcon_bridge/halcon_image.h>

// 路径修改为asr_halcon_bridge功能包所在路径
#include "/home/xirui/lyj/ROS/ros_halcon_ws/src/asr_halcon_bridge/src/asr_halcon_bridge/halcon_image.cpp"

using namespace std;
using namespace ros;
using namespace HalconCpp;

void chatterCallback(const sensor_msgs::Image& source)
{
    ROS_INFO("I heard !");
    
    halcon_bridge::HalconImagePtr ptr = halcon_bridge::toHalconCopy(source);

    /*
        把image对象从ptr中取出来
    */
    HObject image;
    
    image = *ptr->image;

    HTuple  hv_WindowHandle;

    if (HDevWindowStack::IsOpen())
        CloseWindow(HDevWindowStack::Pop());
    SetWindowAttr("background_color","black");
    OpenWindow(20,0,512,512,0,"visible","",&hv_WindowHandle);
    HDevWindowStack::Push(hv_WindowHandle);

    if (HDevWindowStack::IsOpen())
        DispObj(image, HDevWindowStack::GetActive());
    
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "halcon_read");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/usb_cam/image_raw", 1000, chatterCallback);

    ros::spin();

   return 0;
}
