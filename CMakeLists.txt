cmake_minimum_required(VERSION 3.8)
project(ros2_tutorial)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(lifecycle_msgs REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(
  include
)

add_executable(normal_publisher
  src/normal_publisher_node.cpp
  src/normal_publisher.cpp
)
add_executable(split_subscriber
  src/split_main_subscriber_node.cpp
  src/split_main_subscriber.cpp
  src/split_sub_subscriber.cpp
  src/num_subscriber.cpp
)
ament_target_dependencies(normal_publisher 
  rclcpp 
  std_msgs
)
ament_target_dependencies(split_subscriber
  rclcpp 
  rclcpp_lifecycle
  std_msgs
)

install(TARGETS
  normal_publisher split_subscriber
  DESTINATION lib/${PROJECT_NAME}
)
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
