cmake_minimum_required(VERSION 3.8)
project(PlazzaTests)

include_directories(${gtest_SOURCE_DIR}/include
                        lib/googletest/googlemock/include
                        ../order
                        ../Pizza)

add_subdirectory(lib/googletest)

SET(SRC ../Pizza/APizza.h ../Pizza/APizza.cpp
        ../Pizza/American.h ../Pizza/American.cpp
        ../Pizza/Regina.h ../Pizza/Regina.cpp
        ../Pizza/Fantasia.h ../Pizza/Fantasia.cpp
        ../Pizza/Margarita.h ../Pizza/Margarita.cpp
        ../Pizza/PizzaFactory.h ../Pizza/PizzaFactory.cpp
        ../order/AKitchen.h ../order/AKitchen.cpp
        ../order/Cooker.h ../order/Cooker.cpp
        ../order/Order.h ../order/Order.cpp
        ../order/Manager.h ../order/Manager.cpp)

SET(TEST_SOURCES tests_Cooker.cpp MainGTest.cpp)

add_executable(tests ${SRC} ${TEST_SOURCES})



target_link_libraries(tests gtest)