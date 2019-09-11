cmake_minimum_required(VERSION 3.10.2)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include${gtest_SOURCE_DIR})

set(SOURCE_TEST_FILES runAllTests.cpp A_Test.cpp B_Test.cpp C_Test.cpp)
add_executable(runAllTests ${SOURCE_TEST_FILES})
target_link_libraries(runAllTests gtest gtest_main core)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(runAllTests sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
endif()