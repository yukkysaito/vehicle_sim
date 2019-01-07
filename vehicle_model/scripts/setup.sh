#!/bin/sh

SCRIPT_DIR=$(cd $(dirname $0); pwd)
$SCRIPT_DIR/download_model.sh
$SCRIPT_DIR/upgrade_gazebo7.sh