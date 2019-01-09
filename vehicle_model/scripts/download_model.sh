#!/bin/sh

mkdir -p ~/.gazebo
echo "Download generic gazebo models"
if [ -e /tmp/gazebo_models ]; then
  echo "Already exist /tmp/gazebo_models"
  echo "removing /tmp/gazebo_models"
  rm -r /tmp/gazebo_models
fi
hg clone https://bitbucket.org/osrf/gazebo_models /tmp/gazebo_models

if [ -e /tmp/gazebo_models ]; then
  echo "Install generic gazebo models"
  mv -n /tmp/gazebo_models/* ~/.gazebo/models/
  echo "Completed"
else
  echo "Error"
fi

echo "Install citysim models"
SCRIPT_DIR=$(cd $(dirname $0); pwd)
mv -n $SCRIPT_DIR/../../external_models/osrf_citysim/models/* ~/.gazebo/models/

echo "Install citysim models"
mv -n $SCRIPT_DIR/../../external_models/car_demo/models/* ~/.gazebo/models/