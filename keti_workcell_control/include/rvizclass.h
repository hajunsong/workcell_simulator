#pragma once

#include <ros/ros.h>
#include <rviz/visualization_manager.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>
#include <rviz/tool_manager.h>

class RvizClass{

public:
    RvizClass();
    ~RvizClass();

    void initRvizRobotModel(void *_ui);

private:
    rviz::VisualizationManager  *m_RvizManager;
    rviz::RenderPanel           *m_RvizRenderPanel;

    rviz::Display               *m_RvizGrid;
    rviz::Display               *m_RvizSetFixedFrame;
    rviz::Display               *m_RvizRobotModel1;
    rviz::Display               *m_RvizRobotModel2;
    rviz::Display               *m_RvizRobotModel3;
    rviz::Display               *m_RvizRobotModel4;

    void setTopicRobot();
};

