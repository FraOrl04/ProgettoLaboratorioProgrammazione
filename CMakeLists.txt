cmake_minimum_required(VERSION 3.28)
project(ProgettoLaboratorioProgrammazione)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(Test)
set(SOURCE_FILES Node.cpp
        Node.h
        Grid.cpp
        Grid.h
        AStar.h
        GameCharacter.cpp
        GameCharacter.h
        Test/Grid_Test.cpp
        Test/GameCharacter_Test.cpp
        Test/runAllTests.cpp)
add_executable(ProgettoLaboratorioProgrammazione main.cpp
)
add_library(core ${SOURCE_FILES})
target_link_libraries(ProgettoLaboratorioProgrammazione core)
#sfml
find_package(SFML 2.6.1 COMPONENTS system graphics window REQUIRED)
target_link_libraries(ProgettoLaboratorioProgrammazione sfml-system sfml-graphics sfml-window)



