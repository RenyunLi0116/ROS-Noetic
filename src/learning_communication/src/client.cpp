/**
 * AddTwoInts Client
 */
 
#include <cstdlib>
#include "ros/ros.h"
#include "learning_communication/AddTwoInts.h"

int main(int argc, char **argv)
{
  // ROS????????
  ros::init(argc, argv, "add_two_ints_client");
  
  // ??????????????????
  if (argc != 3)
  {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }

  // ?????????
  ros::NodeHandle n;
  
  // ????�??lient?????dd_two_int service??ervice????????earning_communication::AddTwoInts
  ros::ServiceClient client = n.serviceClient<learning_communication::AddTwoInts>("add_two_ints");
  
  // ???learning_communication::AddTwoInts?????ervice???
  learning_communication::AddTwoInts srv;
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
  
  // ???service?????????????????????
  if (client.call(srv))
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}