#include "ros2_tutorial/split_main_subscriber.hpp"

using namespace std::chrono_literals;
using namespace std::placeholders;

namespace ros2_tutorial
{

SplitMainSubscriber::SplitMainSubscriber(
  const std::string& name_space,
  const rclcpp::NodeOptions& options) 
: rclcpp_lifecycle::LifecycleNode("normal_publisher", name_space, options)
{
  
}

SplitMainSubscriber::~SplitMainSubscriber()
{
}

CallbackReturn SplitMainSubscriber::on_configure(const rclcpp_lifecycle::State &){
  RCLCPP_INFO(this->get_logger(), "on_configure() is called");
  
  auto node = shared_from_this();
  
  num_sub_ = std::make_shared<ros2_tutorial::NumSubscriber>(node);
  split_sub_ = std::make_shared<ros2_tutorial::SplitSubSubscriber>(node, num_sub_);
  
  timer_ = this->create_wall_timer(
    1s, std::bind(&SplitMainSubscriber::timerCallback, this)
  );
  
  return CallbackReturn::SUCCESS;
}

CallbackReturn SplitMainSubscriber::on_activate(const rclcpp_lifecycle::State &){
  RCLCPP_INFO(this->get_logger(), "on_activate() is called");
  
  return CallbackReturn::SUCCESS;
}

CallbackReturn SplitMainSubscriber::on_deactivate(const rclcpp_lifecycle::State &){
  RCLCPP_INFO(this->get_logger(), "on_deactivate() is called");
  return CallbackReturn::SUCCESS;
}

CallbackReturn SplitMainSubscriber::on_cleanup(const rclcpp_lifecycle::State &){
  RCLCPP_INFO(this->get_logger(), "on_cleanup() is called");
  
  timer_.reset();
  num_sub_.reset();
  
  return CallbackReturn::SUCCESS;
}

CallbackReturn SplitMainSubscriber::on_shutdown(const rclcpp_lifecycle::State &){
  RCLCPP_INFO(this->get_logger(), "on_configure() is called");
  
  timer_.reset();
  num_sub_.reset();
  
  return CallbackReturn::SUCCESS;
}

void SplitMainSubscriber::timerCallback()
{
  RCLCPP_INFO(this->get_logger(), "<Main Subscriber Class> number: %d", num_sub_->num_);
  split_sub_->checkNumData();
}

} // namespace ros2_tutorial
