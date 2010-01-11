#!/bin/bash
# USAGE: Copy this file to ~/.kde/share/env and reboot (or just restart the desktop)
#        Then run mkplasmoidtestingdirs script
# NOTE: before copying the file, you may modify it and change 'compiled_plasmoids' to anything you like

export KDEDIR=`kde4-config --prefix`
export LOCALAPPSPREFIX=${HOME}/compiled_plasmoids
export KDEDIRS=${KDEDIR}:${LOCALAPPSPREFIX}
export PATH=${LOCALAPPSPREFIX}/bin:$PATH
export LD_LIBRARY_PATH=${LOCALAPPSPREFIX}/lib
export XDG_DATA_DIRS=/usr/share:${LOCALAPPSPREFIX}/share
export PKG_CONFIG_PATH=${LOCALAPPSPREFIX}/lib/pkgconfig:${LOCALAPPSPREFIX}/share/pkgconfig

/usr/bin/kbuildsycoca4
