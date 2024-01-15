cmake_minimum_required(VERSION 3.27)
project(LibraryCatalogue)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/thirdparty/SQLiteCpp-3.3.1)

add_executable(LibraryCatalogue main.cpp)

target_link_libraries(LibraryCatalogue
        SQLiteCpp
        sqlite3
        pthread
        dl
)
