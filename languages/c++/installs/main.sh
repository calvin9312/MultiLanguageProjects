#!/bin/bash
OS="`awk -F= '/^NAME/{print $2}' /etc/os-release`"
if [[ $OS == "Ubuntu" ]]
then
	sudo apt-get install cmake g++ qt5-qmake qt5base-dev
fi
