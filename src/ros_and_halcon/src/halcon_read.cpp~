#include "ros/ros.h"
#include "HalconCpp.h"


#include <ros/package.h>
#include <ros/console.h>
#include <halcon_image.h>

using namespace std;
using namespace ros;
using namespace HalconCpp;


int main(int argc, char **argv)
{
        ros::init(argc, argv, "halcon_read");
        ros::NodeHandle nh;

ros::Publisher halcon = nh.advertise<sensor_msgs::Image>("/yaoli_read_image",1);
//ros::Rate loop_rate(10);
	//using namespace HalconCpp;
	//HImage Mandrill("monkey");
/*
sensor_msgs::ImagePtr toImageMsg() const;
void toImageMsg(sensor_msgs::Image& ros_image) const;
*/
       //halcon_bridge::HalconImage ptr= boost::make_shared<halcon_bridge::HalconImage>();
      //  halcon_bridge::HalconImage ptr ;//=new <halcon_bridge::HalconImage>();
       //ptr.image = new HalconCpp::Image(); 
        // ptr = new halcon_bridge::HalconImage();
       // ptr.header = Mandrill->header;
        //ptr.encoding = Mandrill->encoding;  
          //sensor_msgs::ImagePtr& ros_image;
          //ptr=halcon_bridge::toImageMsg(ros_image);  
	//*ptr.image = Mandrill;
       // sensor_msgs::Image result = ptr.toImageMsg();
         //sensor_msgs::Image ros_image;
         //ptr.toImageMsg(ros_image);


	// wait for mouse click
/*
	HRegion Bright = Mandrill >= 128;
	HRegion Conn = Bright.Connection(); // select all bright pixels
	// get connected components
	// select regions with a size of at least 500 pixels
	HRegion Large = Conn.SelectShape("area","and",500,90000);
	// select the eyes out of the instance variable Large by using
	// the anisometry as region feature:
	HRegion Eyes = Large.SelectShape("anisometry","and",1,1.7);
	Eyes.DispRegion(w);   // display result image in window
	w.Click();            // wait for mouse click

*/



while(ros::ok())
{ 
   HImage Mandrill("/home/yaoli/opencv-3.2.0/samples/data/baboon.jpg");

	Hlong width,height;
	Mandrill.GetImageSize(&width,&height); // read image from file "monkey"
/*
	HWindow w(0,0,width,height); // window with size equal to image
	Mandrill.DispImage(w);
	

        w.Click();
	w.ClearWindow(); // display image in window
*/
halcon_bridge::HalconImage ptr ;

       // ptr.header = Mandrill->header;
        ptr.encoding = "bgr8"; 

*ptr.image = Mandrill;
//ptr.getHalconEncoding
 halcon.publish(ptr.toImageMsg());

	
  ros::spin();
ros::Rate loop_rate(10);
 //loop_rate.sleep(10);
}
 
   return 0;
}






























