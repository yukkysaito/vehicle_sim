cmake_minimum_required(VERSION 2.8.3)
project(vehicle_model)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED
  controller_manager
  effort_controllers
  gazebo_ros_control
  geometry_msgs
  position_controllers
  roscpp
  sensor_msgs
  std_msgs
  tf
  transmission_interface
  velocity_controllers
  joint_state_controller
)


###################################
## catkin specific configuration ##
###################################
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES vehicle_sim
  CATKIN_DEPENDS
    controller_manager
    gazebo_ros_control
    geometry_msgs
    position_controllers
    roscpp
    sensor_msgs
    std_msgs
    tf
    transmission_interface
    velocity_controllers
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
# include
 ${catkin_INCLUDE_DIRS}
)

add_executable(twist2gazebo src/twist2gazebo.cpp)
add_dependencies(twist2gazebo ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(twist2gazebo ${catkin_LIBRARIES})

add_executable(twiststamped2gazebo src/twiststamped2gazebo.cpp)
add_dependencies(twiststamped2gazebo ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(twiststamped2gazebo ${catkin_LIBRARIES})

#############
## Install ##
#############

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(DIRECTORY dae
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(DIRECTORY urdf
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(DIRECTORY config
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(TARGETS twist2gazebo
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_vehicle_sim.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
