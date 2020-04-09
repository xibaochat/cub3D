#!/bin/bash

# Install X11 XShm extension
sudo apt-get install --assume-yes libxext-dev

# Setup your OS
git clone https://github.com/ttshivhula/minilibx.git
sudo mkdir /usr/X11
sudo mkdir /usr/X11/include
sudo mkdir /usr/X11/lib
sudo mkdir /usr/local/lib
cd minilibx
export PKG_CONFIG_PATH=$PWD
make
sudo cp mlx.h /usr/X11/include
sudo cp mlx.h /usr/local/include
sudo cp libmlx.a /usr/X11/lib
sudo cp libmlx.a /usr/local/lib
echo "\n# Finished -- Give to your compilator these instructions :"
echo "## -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11\n"
