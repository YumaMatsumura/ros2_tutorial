#include "ros2_tutorial/normal_publisher.hpp"

int main(int argc, char **argv){
  rclcpp::init(argc, argv);
  
  rclcpp::executors::SingleThreadedExecutor exe;
  auto node = std::make_shared<ros2_tutorial::NormalPublisher>();
  exe.add_node(node->get_node_base_interface());
  exe.spin();
  rclcpp::shutdown();
  
  return 0;
}
