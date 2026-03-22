import rclpy #import the library 
from rclpy.node import Node #import the base class
from std_msgs.msg import Int32 #message type integer
class publish(Node): #inheriting node
def __init__(self):
        super().__init__('publish') #to call the base class
self.publisher_=self.create_publisher(Int32,'topic_name',10)
self.timer = self.create_timer(1.0, self.send_data)
def send_data(self): #defining the function
msg=Int32()
msg.data=10
self.publisher_.publish(msg)
def main(args=None):
rclpy.init(args=args)
node=publish()
rcply.spin(node)
rclpy.shutdown()

