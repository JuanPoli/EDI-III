#!/bin/bash

## Compilo todo
g++ -shared -Wall -std=c++11 -fPIC -I../../include/ Message.cpp -o Message.so `pkg-config --cflags --libs gtk+-2.0`



