#pragma once

#include <rclcpp/rclcpp.hpp>

#include <std_msgs/msg/int32.hpp>

namespace ros2_tutorial
{
class NormalPublisher : public rclcpp::Node
{
public:
  NormalPublisher(
    const std::string& name_space = "",
    const rclcpp::NodeOptions& options = rclcpp::NodeOptions()
  );
  ~NormalPublisher();
  
private:
  void timerCallback();
  
  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
  
  int32_t count_;
};

} // namespace ros2_tutorial
