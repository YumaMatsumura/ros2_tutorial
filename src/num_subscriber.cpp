#include "ros2_tutorial/num_subscriber.hpp"

using namespace std::placeholders;

namespace ros2_tutorial
{

NumSubscriber::NumSubscriber(const rclcpp_lifecycle::LifecycleNode::WeakPtr & parent)
{
  num_ = 0;
  
  auto node = parent.lock();
  logger_ = node->get_logger();
  
  sub_ = node->create_subscription<std_msgs::msg::Int32>(
    "number", 10, std::bind(&NumSubscriber::numCallback, this, _1)
  );
}

NumSubscriber::~NumSubscriber()
{
}

void NumSubscriber::numCallback(const std_msgs::msg::Int32::SharedPtr msg)
{
  num_ = msg->data;
  RCLCPP_INFO(logger_, "<NumSubscriber Class> number: %d", num_);
}

} // namespace ros2_tutorial
