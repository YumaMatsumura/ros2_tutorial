from launch import LaunchDescription
from launch.actions import EmitEvent, RegisterEventHandler
from launch.event_handlers import OnProcessStart
from launch.events import matches_action
from launch_ros.actions import Node, LifecycleNode
from launch_ros.event_handlers import OnStateTransition
from launch_ros.events.lifecycle import ChangeState
from lifecycle_msgs.msg import Transition

def generate_launch_description():
    pub_node = Node(
        package='ros2_tutorial',
        executable='normal_publisher',
        name='normal_publisher',
        output='screen'
    )
    
    sub_node = LifecycleNode(
        package='ros2_tutorial',
        executable='split_subscriber',
        name='split_subscriber',
        namespace='',
        output='screen'
    )
    
    # Unconfigure状態からInactive状態への遷移
    sub_node_configure_event_handler = RegisterEventHandler(
        event_handler=OnProcessStart(
            target_action=sub_node,
            on_start=[
                EmitEvent(
                    event=ChangeState(
                        lifecycle_node_matcher=matches_action(sub_node),
                        transition_id=Transition.TRANSITION_CONFIGURE,
                    ),
                ),
            ],
        )
    )

    # Inactive状態からActive状態への遷移
    sub_node_activate_event_handler = RegisterEventHandler(
        event_handler=OnStateTransition(
            target_lifecycle_node=sub_node,
            start_state='configuring',
            goal_state='inactive',
            entities=[
                EmitEvent(
                    event=ChangeState(
                        lifecycle_node_matcher=matches_action(sub_node),
                        transition_id=Transition.TRANSITION_ACTIVATE,
                    ),
                ),
            ],
        )
    )
    
    return LaunchDescription([
        pub_node,
        sub_node,
        sub_node_configure_event_handler,
        sub_node_activate_event_handler
    ])
