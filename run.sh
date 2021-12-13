#!/bin/bash

# from https://stackoverflow.com/a/22644006/149987
trap "exit" INT TERM
trap "kill 0" EXIT

function retry { python3 /home/god/.config/bspwm/controladorBrillo/controladorBrillo.py /dev/ttyACM0 && echo "success" || (echo "fail" && retry) }; retry

retry
