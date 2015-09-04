#!/usr/bin/env bash

phpize
./configure
make
sudo make install
make clean
php --re focusphp
