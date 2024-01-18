cmake_minimum_required(VERSION 3.27)
project(LibraryCatalogue)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/thirdparty/SQLiteCpp-3.3.1)

add_executable(LibraryCatalogue src/main.cpp
        src/App.cpp
        include/App.h
        src/UI.cpp
        include/UI.h)

target_include_directories(LibraryCatalogue
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include/>)

target_link_libraries(LibraryCatalogue
        SQLiteCpp
        sqlite3
        pthread
        dl
        ${CURSES_LIBRARIES}
)


add_executable(my_test test/my_test.cpp)

target_link_libraries(my_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(my_test)