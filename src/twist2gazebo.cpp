#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float64.h>

class Twist2GazeboController
{
  private:
    ros::NodeHandle nh_;
    ros::NodeHandle pnh_;
    ros::Publisher wheel_right_rear_pub_;
    ros::Publisher wheel_left_rear_pub_;
    ros::Publisher steering_right_front_pub_;
    ros::Publisher steering_left_front_pub_;
    ros::Subscriber sub_;
    void callback(const geometry_msgs::Twist::ConstPtr &input_twist_msg);

  public:
    Twist2GazeboController();
    ~Twist2GazeboController(){};
};

Twist2GazeboController::Twist2GazeboController() : nh_(""), pnh_("~")
{
    wheel_right_rear_pub_ = nh_.advertise<std_msgs::Float64>("wheel_right_rear_velocity_controller/command", 1, true);
    wheel_left_rear_pub_ = nh_.advertise<std_msgs::Float64>("wheel_left_rear_velocity_controller/command", 1, true);
    steering_right_front_pub_ = nh_.advertise<std_msgs::Float64>("steering_right_front_position_controller/command", 1, true);
    steering_left_front_pub_ = nh_.advertise<std_msgs::Float64>("steering_left_front_position_controller/command", 1, true);
    sub_ = nh_.subscribe("cmd_vel", 1, &Twist2GazeboController::callback, this);
}
void Twist2GazeboController::callback(const geometry_msgs::Twist::ConstPtr &input_twist_msg)
{
    std_msgs::Float64 output_wheel_right_rear, output_wheel_left_rear, output_steering_right_front, output_steering_left_front;
    output_wheel_right_rear.data = input_twist_msg->linear.x;
    output_wheel_left_rear.data = input_twist_msg->linear.x;
    output_steering_right_front.data = input_twist_msg->angular.z;
    output_steering_left_front.data = input_twist_msg->angular.z;
    wheel_right_rear_pub_.publish(output_wheel_right_rear);
    wheel_left_rear_pub_.publish(output_wheel_left_rear);
    steering_right_front_pub_.publish(output_steering_right_front);
    steering_left_front_pub_.publish(output_steering_left_front);
}
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "twist2gazebo");

    Twist2GazeboController node;
    ros::spin();

    return 0;
}