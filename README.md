# Download
```shell
$ git clone https://github.com/yukkysaito/vehicle_model.git --recurse-submodules
```
or if you already have a copy of the repo, run `$ git submodule update --init --recursive`.
# Requirements
1. download gazebo models
https://gist.github.com/awesomebytes/982166e825aa23ecdaf9acf34fa0a330
2. upgrade gazebo
   -  reason : https://bitbucket.org/DataspeedInc/velodyne_simulator/src/56d11e899ce0a198e7206298b3aaaf8004f3a2c6/gazebo_upgrade.md?fileviewer=file-view-default

```shell
$ sudo sh -c 'echo "deb http://packages.osrfoundation.org/gazebo/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/gazebo-stable.list'
$ sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys D2486D2DD83DB69272AFE98867170598AF249743
$ sudo apt update
$ sudo apt upgrade
```

# How to use
1. launch gazebo

```shell
$ roslaunch vehicle_model gazebo_test.launch
```