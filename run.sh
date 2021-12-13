#!/bin/bash

function retry { python3 /home/god/.config/bspwm/controladorBrillo/controladorBrillo.py /dev/ttyACM0 && echo "success" || (echo "fail" && retry) }; retry

retry
