#!/bin/sh

sudo pacman -Syu --noconfirm gcc
sudo pacman -Syu --noconfirm make
sudo pacman -Syu --noconfirm cmake
sudo pacman -Syu --noconfirm sfml
sudo pacman -Syu --noconfirm libusb
sudo pacman -Syu --noconfirm libnfc
sudo pacman -Syu --noconfirm mysql

curl https://raw.githubusercontent.com/Mazettt/Mazettt/main/build_csfml.sh -o build_csfml.sh
chmod 744 build_csfml.sh
sudo ./build_csfml.sh
