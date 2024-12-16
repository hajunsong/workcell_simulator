cmake_minimum_required(VERSION 3.0.2)
project(keti_workcell_urdf_translator)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    std_msgs
    roslib
)

catkin_package(
    INCLUDE_DIRS include
    LIBRARIES
    CATKIN_DEPENDS roscpp std_msgs roslib
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets)

set(QT_LIBRIES Qt5::Core Qt5::Gui Qt5::Widgets)

file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS include/*.h include/*.hpp)

QT5_WRAP_UI(QT_FORMS_HPP ${QT_FORMS})
QT5_WRAP_CPP(QT_MOC_HPP ${QT_MOC})

include_directories(
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Gui_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
)

set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
)

set(LIBS pugixml)

set(TARGET_NAME urdf_translator_node)

add_executable(${TARGET_NAME} ${SOURCES} ${QT_FORMS_HPP} ${QT_MOC_HPP})
add_dependencies(${TARGET_NAME} ${${TARGET_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${TARGET_NAME} ${catkin_LIBRARIES} ${QT_LIBRIES} ${LIBS})
target_link_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)