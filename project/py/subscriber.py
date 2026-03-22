import rclpy #import the library 
from rclpy.node import Node #import baseclass
from std_msgs.msg import Int32 #declared as integer

class subscribe(Node): #inheriting
    def __init__(self):
super().__init__('subscribe') #calling base class
 self.subscription = self.create_subscription(Int32,'distance',self.listener_callback,1>
def listener_callback(self, msg): #function
self.get_logger().info(f'Received distance: {msg.data}') #displayed
def main(args=None):
    rclpy.init(args=args)
    node = DistanceSubscriber()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
