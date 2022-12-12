#pragma once

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_lifecycle/lifecycle_node.hpp>
#include <std_msgs/msg/int32.hpp>

namespace ros2_tutorial
{

class NumSubscriber
{
public:
  NumSubscriber(const rclcpp_lifecycle::LifecycleNode::WeakPtr & parent);
  ~NumSubscriber();
  
  int32_t num_;
  
private:
  void numCallback(const std_msgs::msg::Int32::SharedPtr msg);
  
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr sub_;
  
  rclcpp::Logger logger_{rclcpp::get_logger("NumScriber")};
};

} // namespace ros2_tutorial
