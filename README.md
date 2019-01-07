# Overview
Autonomous driving car simulator based on gazebo.
The following sensors are simulated.
- velodyne (VLP-16, HDL-32E)
- camera
- imu
![github](https://user-images.githubusercontent.com/8327598/50725047-dc1a5780-113a-11e9-9487-ae0c6b67b47d.png)
(Banana and tire visualization models are not in the repository due to copyright relationship. Although it looks different, it does not affect the motion)


# Download
```shell
$ cd "your catkin workspace/src/"
$ git clone https://github.com/yukkysaito/vehicle_sim.git --recurse-submodules
```
or if you already have a copy of the repo, run `$ git submodule update --init --recursive`.

# How to use
1. build

```shell
$ cakin_make
$ source "your catkin workspace"/devel/setup.bash
```
1. upgrade gazebo version and download gazebo models
```
$ rosrun vehicle_sim setup.sh
```
1. launch gazebo

```shell
$ roslaunch vehicle_model gazebo_test.launch
```

If GPU is available

```shell
$ roslaunch vehicle_model gazebo_test.launch gpu:=true
```

**If you need pointcloud map, you can download following url**
https://drive.google.com/file/d/1F3Mf0EZsIB29FDeSqH71nEo_p37lKfrm/view?usp=sharing

# How to change config
- Change sensor position: *config/caibration.yaml*
- Change vehicle info: *config/vehicle_info.yaml*
