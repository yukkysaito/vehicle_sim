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
$ rosdep install --from-paths <vehicle_sim/vehicle_model path> -y
$ cakin_make
$ source "your catkin workspace"/devel/setup.bash
```

2. upgrade gazebo version and download gazebo models(**only once**)
   -  reason : https://bitbucket.org/DataspeedInc/velodyne_simulator/src/56d11e899ce0a198e7206298b3aaaf8004f3a2c6/gazebo_upgrade.md?fileviewer=file-view-default
```
$ rosrun vehicle_model setup.sh
```

3. launch gazebo

```shell
$ roslaunch vehicle_model world_test.launch
```

If GPU is available

```shell
$ roslaunch vehicle_model world_test.launch gpu:=true
```

**If you need pointcloud map and path files for Autoware, you can download following url**
https://drive.google.com/drive/folders/1yu8s885HDkJp3IbMV06KWim2ZdUxIoIF?usp=sharing

# How to change config
- Change sensor position: *config/caibration.yaml*
- Change vehicle info: *config/vehicle_info.yaml*
