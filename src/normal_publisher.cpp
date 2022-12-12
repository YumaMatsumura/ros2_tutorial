#include "ros2_tutorial/normal_publisher.hpp"

using namespace std::chrono_literals;

namespace ros2_tutorial
{

NormalPublisher::NormalPublisher(
  const std::string& name_space,
  const rclcpp::NodeOptions& options)
: rclcpp::Node("normal_publisher", name_space, options),
  count_{0}
{
  pub_ = this->create_publisher<std_msgs::msg::Int32>("number", 1);
  timer_ = this->create_wall_timer(
    1s, std::bind(&NormalPublisher::timerCallback, this)
  );
}

NormalPublisher::~NormalPublisher()
{
}

void NormalPublisher::timerCallback()
{
  RCLCPP_INFO(this->get_logger(), "<Publisher Class> number: %d", count_);
  
  std_msgs::msg::Int32 msg;
      
  msg.data = count_;
  count_++;
      
  pub_->publish(msg);
}

} // namespace ros2_tutorial
