/**
 *AddTwoInts Server
 */

#include "ros/ros.h"
#include "learning_communication/AddTwoInts.h"

//service????,????req,????res
bool add(learning_communication::AddTwoInts::Request &req,
learning_communication::AddTwoInts::Response &res)
{
	//?????????????,?????????
	res.sum = req.a + req.b;
	ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
	ROS_INFO("sending back response:[%ld]", (long int)res.sum);
	
	return true;
 } 
 
 int main(int argc, char**argv)
 {
 	//ROS?????
	 ros::init(argc,argv,"add_two_init_server");
	 
	 //??????
	 ros::NodeHandle n;
	 
	 //??????add_two_ints?server,??????add() 
	 ros::ServiceServer service = n.advertiseService("add_two_ints",add);
	 
	 //????????
	 ROS_INFO("Ready to add two ints.");
	 ros::spin();
	 
	 return 0; 
 }