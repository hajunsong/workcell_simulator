#include "rvizclass.h"
#include "ui_mainwindow.h"

RvizClass::RvizClass(void *_layout)
{
	QVBoxLayout *layout = static_cast<QVBoxLayout *>(_layout);

	m_RvizRenderPanel = new rviz::RenderPanel();

	layout->addWidget(m_RvizRenderPanel);

	enableM1 = false;
}

RvizClass::~RvizClass(){

}

void RvizClass::initRvizRobotModel()
{
	m_RvizManager = new rviz::VisualizationManager(m_RvizRenderPanel);

	m_RvizRenderPanel->initialize(m_RvizManager->getSceneManager(), m_RvizManager);
	m_RvizManager->initialize();
	m_RvizManager->startUpdate();

	setTopicRobot();
}

void RvizClass::setTopicRobot()
{
	m_RvizManager->setFixedFrame("world");

	m_RvizGrid = m_RvizManager->createDisplay("rviz/Grid", "adjustable grid", true);
	m_RvizGrid->subProp("Line Style")->setValue("Billboards");

	if(enableM1){
		m_RvizRobotModel1 = m_RvizManager->createDisplay("rviz/RobotModel", "robotmodel", true);
		m_RvizRobotModel1->subProp("Robot Description")->setValue("/base_UR/robot_description");
	}

	m_RvizRobotModel2 = m_RvizManager->createDisplay("rviz/RobotModel", "robotmodel", true);
  	m_RvizRobotModel2->subProp("Robot Description")->setValue("/base_ARF/robot_description");

	m_RvizRobotModel3 = m_RvizManager->createDisplay("rviz/RobotModel", "robotmodel", true);
	m_RvizRobotModel3->subProp("Robot Description")->setValue("/base_DENSO/robot_description");

	m_RvizRobotModel4 = m_RvizManager->createDisplay("rviz/RobotModel", "robotmodel", true);
	m_RvizRobotModel4->subProp("Robot Description")->setValue("/base_ETC/robot_description");

	m_RvizRobotModel5 = m_RvizManager->createDisplay("rviz/RobotModel", "robotmodel", true);
	m_RvizRobotModel5->subProp("Robot Description")->setValue("/base_VISION/robot_description");
}

void RvizClass::stop(){
	m_RvizManager->removeAllDisplays();
}

void RvizClass::enableModule1(){
	enableM1 = true;
}

void RvizClass::disableModule1(){
	enableM1 = false;
}
