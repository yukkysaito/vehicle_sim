# Install script for directory: /home/yukihiro/workspace/catkin_ws/src/vehicle_model/osrf_citysim/media/materials/programs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/citysim-0/media/materials/programs/Blur_vs.glsl;/usr/local/share/citysim-0/media/materials/programs/BlurH_ps20.glsl;/usr/local/share/citysim-0/media/materials/programs/StdQuad_vp.glsl;/usr/local/share/citysim-0/media/materials/programs/BrightBloom2_ps20.glsl;/usr/local/share/citysim-0/media/materials/programs/BlurV_ps20.glsl;/usr/local/share/citysim-0/media/materials/programs/StdQuad_Tex2a_vp.glsl;/usr/local/share/citysim-0/media/materials/programs/Bloom2_ps20.glsl")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/share/citysim-0/media/materials/programs" TYPE FILE FILES
    "/home/yukihiro/workspace/catkin_ws/src/vehicle_model/osrf_citysim/media/materials/programs/Blur_vs.glsl"
    "/home/yukihiro/workspace/catkin_ws/src/vehicle_model/osrf_citysim/media/materials/programs/BlurH_ps20.glsl"
    "/home/yukihiro/workspace/catkin_ws/src/vehicle_model/osrf_citysim/media/materials/programs/StdQuad_vp.glsl"
    "/home/yukihiro/workspace/catkin_ws/src/vehicle_model/osrf_citysim/media/materials/programs/BrightBloom2_ps20.glsl"
    "/home/yukihiro/workspace/catkin_ws/src/vehicle_model/osrf_citysim/media/materials/programs/BlurV_ps20.glsl"
    "/home/yukihiro/workspace/catkin_ws/src/vehicle_model/osrf_citysim/media/materials/programs/StdQuad_Tex2a_vp.glsl"
    "/home/yukihiro/workspace/catkin_ws/src/vehicle_model/osrf_citysim/media/materials/programs/Bloom2_ps20.glsl"
    )
endif()

