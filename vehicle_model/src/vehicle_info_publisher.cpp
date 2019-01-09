#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
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
    ros::Publisher vehicle_info_pub_;
    ;
    ros::Publisher steering_base_link_pub_;
    ros::Timer publish_timer_; // publish timer
    void publishTimerCallback(const ros::TimerEvent &e);

    double wheel_base_;
    double wheel_radius_;
    double wheel_tread_;

  public:
    VehicleInfoPublisher();
    ~VehicleInfoPublisher(){};
};

VehicleInfoPublisher::VehicleInfoPublisher() : nh_(""), pnh_("~")
{
    nh_.param("wheel_base", wheel_base_, 2.95);
    nh_.param("wheel_radius", wheel_radius_, 0.341);
    nh_.param("wheel_tread", wheel_tread_, 1.55);

    client_ = nh_.serviceClient<gazebo_msgs::GetLinkState>("/gazebo/get_link_state");
    vehicle_info_pub_ = nh_.advertise<gazebo_msgs::LinkState>("vehicle_info", 1, true);
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

    gazebo_msgs::LinkState output;
    output = base_link_srv.response.link_state;
    output.pose.orientation.w = wheel_angle;

    vehicle_info_pub_.publish(output);
}
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "vehicle_info_publisher");

    VehicleInfoPublisher node;
    ros::spin();

    return 0;
}