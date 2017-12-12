cmake_minimum_required(VERSION 3.8)
project(PlazzaTests)

include_directories(${gtest_SOURCE_DIR}/include
                        lib/googletest/googlemock/include
                        ../Pizza)

add_subdirectory(lib/googletest)

SET(SRC ../Pizza/APizza.h ../Pizza/APizza.cpp
        ../Pizza/American.h ../Pizza/American.cpp
        ../Pizza/Regina.h ../Pizza/Regina.cpp
        ../Pizza/Fantasia.h ../Pizza/Fantasia.cpp
        ../Pizza/Margarita.h ../Pizza/Margarita.cpp
        ../Pizza/PizzaFactory.h ../Pizza/PizzaFactory.cpp
        ../AKitchen.h ../AKitchen.cpp
        ../Cooker.h ../Cooker.cpp
        ../Order.h ../Order.cpp
        ../Manager.h ../Manager.cpp
        ../Kitchen.h ../Kitchen.cpp
        ../Team.h ../Team.cpp)

SET(TEST_SOURCES MainGTest.cpp  tests_Cooker.cpp
                                tests_Kitchen.cpp)

add_executable(tests ${SRC} ${TEST_SOURCES})

target_link_libraries(tests gtest)