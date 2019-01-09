#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/PoseStamped.h>
#include <gazebo_msgs/LinkState.h>
#include <gazebo_msgs/GetLinkState.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/utils.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

class VehicleInfoPublisher
{
  private:
    ros::NodeHandle nh_;
    ros::NodeHandle pnh_;
    ros::ServiceClient client_;
    ros::Publisher vehicle_pose_pub_;
    ros::Publisher vehicle_twist_pub_;
    ros::Publisher steering_angle_pub_;
    ros::Timer publish_timer_; // publish timer
    void publishTimerCallback(const ros::TimerEvent &e);

  public:
    VehicleInfoPublisher();
    ~VehicleInfoPublisher(){};
};

VehicleInfoPublisher::VehicleInfoPublisher() : nh_(""), pnh_("~")
{
    client_ = nh_.serviceClient<gazebo_msgs::GetLinkState>("/gazebo/get_link_state");
    vehicle_pose_pub_ = nh_.advertise<geometry_msgs::PoseStamped>("/vehicle_info/pose", 1, true);
    vehicle_twist_pub_ = nh_.advertise<geometry_msgs::TwistStamped>("/vehicle_info/twist", 1, true);
    steering_angle_pub_ = nh_.advertise<std_msgs::Float64>("/vehicle_info/steering_angle", 1, true);
    double publish_rate;
    pnh_.param<double>("publish_rate", publish_rate, double(100.0));
    publish_timer_ = nh_.createTimer(ros::Duration(1.0 / publish_rate), &VehicleInfoPublisher::publishTimerCallback, this);
}
void VehicleInfoPublisher::publishTimerCallback(const ros::TimerEvent &e)
{
    gazebo_msgs::GetLinkState wheel_right_front_link_srv;
    wheel_right_front_link_srv.request.link_name = "autoware::steering_right_front_link";
    wheel_right_front_link_srv.request.reference_frame = "autoware::base_link";
    client_.call(wheel_right_front_link_srv);

    gazebo_msgs::GetLinkState wheel_left_front_link_srv;
    wheel_left_front_link_srv.request.link_name = "autoware::steering_left_front_link";
    wheel_left_front_link_srv.request.reference_frame = "autoware::base_link";
    client_.call(wheel_left_front_link_srv);

    gazebo_msgs::GetLinkState base_link_srv;
    base_link_srv.request.link_name = "autoware::base_link";
    base_link_srv.request.reference_frame = "";
    client_.call(base_link_srv);

    double wheel_left_front_angle;
    wheel_left_front_angle = tf2::getYaw(wheel_left_front_link_srv.response.link_state.pose.orientation);
    double wheel_right_front_angle;
    wheel_right_front_angle = tf2::getYaw(wheel_left_front_link_srv.response.link_state.pose.orientation);

    double wheel_angle = (wheel_left_front_angle + wheel_right_front_angle) / 2;

    ros::Time current_time = ros::Time::now();
    geometry_msgs::TwistStamped output_twist;
    geometry_msgs::PoseStamped output_pose;
    std_msgs::Float64 output_steering_angle;
    output_twist.header.frame_id = "base_link";
    output_twist.header.stamp = current_time;
    output_twist.twist = base_link_srv.response.link_state.twist;
    output_pose.header.frame_id = "base_link";
    output_pose.header.stamp = current_time;
    output_pose.pose = base_link_srv.response.link_state.pose;
    output_steering_angle.data = wheel_angle;

    vehicle_twist_pub_.publish(output_twist);
    vehicle_pose_pub_.publish(output_pose);
    steering_angle_pub_.publish(output_steering_angle);
}
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "vehicle_info_publisher");

    VehicleInfoPublisher node;
    ros::spin();

    return 0;
}