#!/bin/bash

echo user id: $UID
echo primary group id: `id -G $USER`
echo names of all groups: `id -Gn $USER`
echo absolute path of the bash shell: `which bash`
echo absolute path of home directory: $HOME
echo path environment variable: $PATH

