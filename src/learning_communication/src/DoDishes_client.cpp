#include <actionlib/client/simple_action_client.h>
#include "learning_communication/DoDishesAction.h"

typedef actionlib::SimpleActionClient<learning_communication::DoDishesAction> Client;

// ??ction????????????????????
void doneCb(const actionlib::SimpleClientGoalState& state,
        const learning_communication::DoDishesResultConstPtr& result)
{
    ROS_INFO("Yay! The dishes are now clean");
    ros::shutdown();
}

// ??ction?€????????????????€??
void activeCb()
{
    ROS_INFO("Goal just went active");
}

// ???feedback????????????
void feedbackCb(const learning_communication::DoDishesFeedbackConstPtr& feedback)
{
    ROS_INFO(" percent_complete : %f ", feedback->percent_complete);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "do_dishes_client");

    // ????€??????
    Client client("do_dishes", true);

    // ?????????
    ROS_INFO("Waiting for action server to start.");
    client.waitForServer();
    ROS_INFO("Action server started, sending goal.");

    // ????€??ction??oal
    learning_communication::DoDishesGoal goal;
    goal.dishwasher_id = 1;

    // ??€?ction??oal?????????????????????
    client.sendGoal(goal,  &doneCb, &activeCb, &feedbackCb);

    ros::spin();

    return 0;
}