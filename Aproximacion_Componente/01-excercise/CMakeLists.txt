cmake_minimum_required(VERSION 3.13)
project(00_exercise)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(00_exercise
        bin/Greeter.dll
        bin/main.exe
        bin/Message.dll
        include/ApplicationInterface.h
        include/ComponentFactory.h
        include/ComponentInterface.h
        include/dlfcn.h
        include/GreeterIterface.h
        include/IMessage.h
        include/LibraryLoader.h
        include/MessengerInterface.h
        src/Application/Application.cpp
        src/Application/Message.cpp
        src/ConsoleGreeter/ConsoleGreeter.cpp
        src/ConsoleGreeter/Message.cpp
        src/GtkGreeter/GtkGreeter.cpp
        main.cpp)
