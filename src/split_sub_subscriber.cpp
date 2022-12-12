#include "ros2_tutorial/split_sub_subscriber.hpp"

using namespace std::placeholders;
using namespace std::chrono_literals;

namespace ros2_tutorial
{

SplitSubSubscriber::SplitSubSubscriber(
  const rclcpp_lifecycle::LifecycleNode::WeakPtr & parent,
  std::shared_ptr<ros2_tutorial::NumSubscriber> num_sub)
{
  node_ = parent;
  auto node = node_.lock();
  logger_ = node->get_logger();
  num_sub_ = num_sub;
}

SplitSubSubscriber::~SplitSubSubscriber()
{
}

void SplitSubSubscriber::checkNumData()
{
  RCLCPP_INFO(logger_, "<Sub Subscriber Class> number: %d", num_sub_->num_);
}

} // namespace ros2_tutorial
