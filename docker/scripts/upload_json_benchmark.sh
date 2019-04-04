#!/bin/bash
# Command line parameters:
# 1 - bitbucket organization name. For example ignitionrobotics or osrf.
# 2 - the name of the ignition repository. For example ign-math.
# 3 - the name of the branch. For example ign-math6

set -o errexit
set -o verbose

curl -k -X POST -d @$1 https://api.ignitionrobotics.org/1.0/benchmarks/gazebo --header 'authorization: Bearer '$AUTH0_JWT_TOKEN
