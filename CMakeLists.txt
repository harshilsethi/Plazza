cmake_minimum_required(VERSION 3.8)
project(Plazzav1)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp
        AKitchen.h
        AKitchen.cpp
        Cooker.cpp
        Cooker.h
        Order.cpp
        Order.h
        Pizza/PizzaFactory.cpp
        Pizza/PizzaFactory.h
        Pizza/APizza.h
        Pizza/Margarita.cpp
        Pizza/Margarita.h
        Pizza/APizza.cpp
        Pizza/American.cpp
        Pizza/American.h
        Pizza/Fantasia.cpp
        Pizza/Fantasia.h
        Pizza/Regina.cpp
        Pizza/Regina.h
        Manager.cpp
        Manager.h
        Kitchen.cpp
        Kitchen.h
        Team.cpp
        Team.h)
add_executable(Plazzav1 ${SOURCE_FILES})