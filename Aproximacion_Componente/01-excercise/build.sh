#!/bin/bash

## Borro el directorio bin si ya existiera
if [ -d "./bin" ];
    then rm -r ./bin;
fi

## Creo el directorio para los binarios
mkdir ./bin/

## Compilo todo
g++ -Wall -std=c++11 -ldl -I./include/ main.cpp -o ./bin/main.bin
g++ -shared -Wall -std=c++11 FPIC -I./include/ ./src/Application/Application.cpp -o ./bin/Application.so
g++ -shared -Wall -std=c++11 FPIC -I./include/ ./src/ConsoleGreeter/Greeter.cpp -o ./bin/Greeter.so
g++ -shared -Wall -std=c++11 FPIC -I./include/ ./src/ConsoleGreeter/Message.cpp -o ./bin/Message.so

## Otorgo permisos de escritura al ejecutable
chmod +x ./bin/main.bin


