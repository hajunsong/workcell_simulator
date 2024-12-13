#include <ros/ros.h>
#include <sensor_msgs/JointState.h>

#include <iostream>
#include <vector>

class RobotControl{
public:
    RobotControl(ros::NodeHandle nh);
    ~RobotControl();

    void start();

    void cbJointStateUR(const sensor_msgs::JointStatePtr &msg);
    void cbJointStateARF(const sensor_msgs::JointStatePtr &msg);
    void cbJointStateDENSO(const sensor_msgs::JointStatePtr &msg);

    void setValue1(std::vector<double> value);
    void setValue2(std::vector<double> value);
    void setValue3(std::vector<double> value);
    void setValue4(std::vector<double> value);
    
private:
    ros::Subscriber subUR, subARF, subDENSO;
    ros::Publisher pubUR, pubARF, pubDENSO;
    sensor_msgs::JointState msgUR, msgARF, msgDENSO;
};