#pragma once

#include <memory>
#include <utility>

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_lifecycle/lifecycle_node.hpp>
#include <std_msgs/msg/int32.hpp>

#include "ros2_tutorial/num_subscriber.hpp"
#include "ros2_tutorial/split_sub_subscriber.hpp"

using CallbackReturn = rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;

namespace ros2_tutorial
{
class SplitMainSubscriber : public rclcpp_lifecycle::LifecycleNode
{
public:
  SplitMainSubscriber(
    const std::string& name_space = "",
    const rclcpp::NodeOptions& options = rclcpp::NodeOptions()
  );
  ~SplitMainSubscriber();
  
  CallbackReturn on_configure(const rclcpp_lifecycle::State &);
  CallbackReturn on_activate(const rclcpp_lifecycle::State &);
  CallbackReturn on_deactivate(const rclcpp_lifecycle::State &);
  CallbackReturn on_cleanup(const rclcpp_lifecycle::State &);
  CallbackReturn on_shutdown(const rclcpp_lifecycle::State &);
  
  void timerCallback();
  
  std::shared_ptr<ros2_tutorial::SplitMainSubscriber> shared_from_this()
  {
    return std::static_pointer_cast<ros2_tutorial::SplitMainSubscriber>(
      rclcpp_lifecycle::LifecycleNode::shared_from_this());
  }
  
  std::shared_ptr<rclcpp::TimerBase> timer_;
  std::shared_ptr<ros2_tutorial::NumSubscriber> num_sub_;
  std::shared_ptr<ros2_tutorial::SplitSubSubscriber> split_sub_;
  
};
} // namespace ros2_tutorial
