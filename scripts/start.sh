#!/bin/bash

sshpass -p $1 ssh pi@raspi3-01 "sudo /home/pi/startup.sh"
sleep 3
sshpass -p $1 ssh pi@raspi3-02 "sudo /home/pi/startup.sh"
sshpass -p $1 ssh pi@raspi3-03 "sudo /home/pi/startup.sh"
