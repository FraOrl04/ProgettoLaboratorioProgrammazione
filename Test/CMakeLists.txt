add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(SOURCE_TEST_FILES runAllTests.cpp GameCharacter_Test.cpp Grid_Test.cpp
        Node_Test.cpp
        Astar_Test.cpp)
add_executable( runAstarTest ${SOURCE_TEST_FILES})
target_link_libraries( runAstarTest gtest gtest_main core)