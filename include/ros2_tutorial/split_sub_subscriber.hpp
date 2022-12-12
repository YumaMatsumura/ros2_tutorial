#pragma once

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_lifecycle/lifecycle_node.hpp>

#include "ros2_tutorial/num_subscriber.hpp"

namespace ros2_tutorial
{
class SplitSubSubscriber
{
public:
  SplitSubSubscriber(
    const rclcpp_lifecycle::LifecycleNode::WeakPtr & parent,
    std::shared_ptr<ros2_tutorial::NumSubscriber> num_sub
  );
  ~SplitSubSubscriber();
  void checkNumData();
  
private:
  rclcpp_lifecycle::LifecycleNode::WeakPtr node_;
  std::shared_ptr<ros2_tutorial::NumSubscriber> num_sub_;
  
  rclcpp::Logger logger_{rclcpp::get_logger("SplitSubScriber")};
};
} // namespace ros2_tutorial
