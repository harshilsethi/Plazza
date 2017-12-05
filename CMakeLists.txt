cmake_minimum_required(VERSION 3.8)
project(Plazzav1)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp
        order/AKitchen.h
        order/AKitchen.cpp
        order/Cooker.cpp
        order/Cooker.h
        order/Order.cpp
        order/Order.h
        order/Manager.cpp
        order/Manager.h
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
        Pizza/Regina.h)
add_executable(Plazzav1 ${SOURCE_FILES})

include_directories(Pizza)
include_directories(order)

add_subdirectory(test)