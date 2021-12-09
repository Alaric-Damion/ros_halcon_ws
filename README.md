# ros_halcon_ws
ROS与Halcon的联合使用，连接USB相机获取图像，并将ROS消息转换成halcon图像
##### 项目应该是三个功能包，因为文件太大无法上传，缺少了asr_halcon_bridge，需要下载代码来运行的小伙伴下面贴有百度网盘的链接，请自行下载！！！
##### 项目在CSDN发布了相关博客，博客中包含了更多详细内容，博客链接：[https://blog.csdn.net/m0_46991388/article/details/121822097](https://blog.csdn.net/m0_46991388/article/details/121822097)
# ROS与Halcon联合(halcon_bridge)
在网上搜索众多资料后，作者总结出了ROS与Halcon联合使用的方法。本篇文章将会罗列出以下几部分内容，方便读者能够复现和理解ROS与Halcon联合使用的过程。1、我的项目代码；2、功能包网址；3、参考文献地址；
#### 一、我的项目代码
我的项目实现的功能如下：1、USB相机采集图像并传递数据给ROS；2、编写订阅者从ROS端接收到图像数据，并使用halcon做图像处理。
项目名：ros_halcon_ws
功能包：asr_halcon_bridge、ros_and_halcon、usb_cam
##### ROS与Halcon联合主要代码

```cpp
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

```

##### 运行方法

```bash
1、cd 进入 ros_halcon_ws目录中，使用命令catkin_make，进行工作空间的编译；
```

```bash
2、在ros_halcon_ws目录中，source ./devel/setup.bash，进行工作空间的加载；
```

```bash
3、启动USB相机采集图像并传递数据给ROS，rosrun usb_cam usb_cam_node;
```

```bash
4、将sensor_msgs::Image转换成HalconCpp::HImage，rosrun ros_and_halcon halcon_read
```

##### 运行结果
![运行结果](https://img-blog.csdnimg.cn/370d68b5fbe14ba18314d33e1571e231.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA6buR6amsSmFjaw==,size_18,color_FFFFFF,t_70,g_se,x_16#pic_center)
#### 二、项目代码下载地址
我把项目代码上传至百度网盘和github上了，有需要的小伙伴自行下载哦！
百度网盘：链接：https://pan.baidu.com/s/15meBONPQVT_DBKqi0wcXXg 
提取码：r1tp
#### 三、功能包网址
**asr_halcon_bridge**：与cv_bridge功能类似，支持halcon与ROS进行图像数据交互。
网址：1、[http://wiki.ros.org/asr_halcon_bridge](http://wiki.ros.org/asr_halcon_bridge)；2、[https://github.com/asr-ros/asr_halcon_bridge](https://github.com/asr-ros/asr_halcon_bridge)
说明：主要文件位于include/halcon_image.h与src/halcon_image.cpp中
**usb_cam**：启动USB摄像头采集图像并传递数据给ROS。
网址：1、[https://github.com/ros-drivers/usb_cam](https://github.com/ros-drivers/usb_cam)；2、[http://wiki.ros.org/usb_cam](http://wiki.ros.org/usb_cam)
说明：主要文件位于nodes/usb_cam_node.cpp中
#### 四、总结
以上就是本篇文章的全部内容了，希望能对你解决ROS与Halcon联合使用的问题有所帮助，感谢你的阅读，能帮助到你一点点的话这篇文章它就是有意义的，希望你能快速解决这个问题，做出相应成果，有什么问题欢迎一起讨论和交流！

参考文献
【1】http://wiki.ros.org/asr_halcon_bridge（wiki教程）
【2】https://github.com/asr-ros/asr_halcon_bridge（github代码库）
【3】http://wiki.ros.org/usb_cam（wiki教程）
【4】https://github.com/ros-drivers/usb_cam（github代码库）
【5】https://github.com/yaoli1992/ros_and_halcon（github代码库）
【6】https://blog.csdn.net/spy14414/article/details/104945153（CSDN博客）
【7】https://www.cnblogs.com/li-yao7758258/p/7372495.html（博客园博客）
