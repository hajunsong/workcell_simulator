#include "robotcontrol.h"

RobotControl::RobotControl(ros::NodeHandle nh){
    pubUR = nh.advertise<sensor_msgs::JointState>("/base_UR/joint_states", 1);
    pubARF = nh.advertise<sensor_msgs::JointState>("/base_ARF/joint_states", 1);
    pubDENSO = nh.advertise<sensor_msgs::JointState>("/base_DENSO/joint_states", 1);
    subUR = nh.subscribe("/base_UR/joint_states", 1, &RobotControl::cbJointStateUR, this);
    subARF = nh.subscribe("/base_UR/joint_states", 1, &RobotControl::cbJointStateARF, this);
    subDENSO = nh.subscribe("/base_UR/joint_states", 1, &RobotControl::cbJointStateDENSO, this);

    msgUR.name.push_back("q1");
    msgUR.name.push_back("q2");
    msgUR.name.push_back("q3");
    msgUR.name.push_back("q4");
    msgUR.name.push_back("q5");
    msgUR.name.push_back("q6");
    msgUR.position.assign(6, 0);
    msgUR.velocity.assign(6, 0);
    msgUR.effort.assign(6, 0);
    
    msgARF.name.push_back("s3");
    msgARF.name.push_back("s4");
    msgARF.name.push_back("s5");
    msgARF.name.push_back("s6");
    msgARF.name.push_back("s7");
    msgARF.name.push_back("s8");
    msgARF.position.assign(6, 0);
    msgARF.velocity.assign(6, 0);
    msgARF.effort.assign(6, 0);
    
    msgDENSO.name.push_back("s1");
    msgDENSO.name.push_back("s2");
    msgDENSO.name.push_back("d_q1");
    msgDENSO.name.push_back("d_q2");
    msgDENSO.name.push_back("d_q3");
    msgDENSO.name.push_back("d_q4");
    msgDENSO.position.assign(6, 0);
    msgDENSO.velocity.assign(6, 0);
    msgDENSO.effort.assign(6, 0);
}

RobotControl::~RobotControl(){

}

void RobotControl::start(){
    ros::Rate loop_rate(10); // Hz
    // while(ros::ok()){
        ros::spinOnce();
        loop_rate.sleep();

        msgUR.header.stamp = ros::Time::now();
        msgARF.header.stamp = ros::Time::now();
        msgDENSO.header.stamp = ros::Time::now();
    
    pubUR.publish(msgUR);
    pubARF.publish(msgARF);
    pubDENSO.publish(msgDENSO);
    // }
}

void RobotControl::cbJointStateUR(const sensor_msgs::JointStatePtr &msg){
    ROS_INFO("[UR] current joint position : %f, %f, %f, %f, %f, %f", 
        msg->position[0], msg->position[1], msg->position[2], msg->position[3], msg->position[4], msg->position[5]);
}

void RobotControl::cbJointStateARF(const sensor_msgs::JointStatePtr &msg){
    ROS_INFO("[ARF] current joint position : %f, %f, %f, %f, %f, %f", 
        msg->position[0], msg->position[1], msg->position[2], msg->position[3], msg->position[4], msg->position[5]);
}

void RobotControl::cbJointStateDENSO(const sensor_msgs::JointStatePtr &msg){
    ROS_INFO("[DENSO] current joint position : %f, %f, %f, %f, %f, %f", 
        msg->position[0], msg->position[1], msg->position[2], msg->position[3], msg->position[4], msg->position[5]);
}

void RobotControl::setValue1(std::vector<double> value){
    msgUR.header.stamp = ros::Time::now();
    std::copy(value.begin(), value.end(), msgUR.position.begin());
    pubUR.publish(msgUR);
}

void RobotControl::setValue2(std::vector<double> value){
    msgARF.header.stamp = ros::Time::now();
    memcpy(msgARF.position.data(), value.data(), sizeof(double)*6);
    pubARF.publish(msgARF);
}

void RobotControl::setValue3(std::vector<double> value){
    msgDENSO.header.stamp = ros::Time::now();
    memcpy(msgDENSO.position.data(), value.data(), sizeof(double)*6);
    pubDENSO.publish(msgDENSO);
}

void RobotControl::setValue4(std::vector<double> value){

}