cmake_minimum_required(VERSION 3.10)
project(explorer)

file(GLOB COMMON_SOURCES "src/common/*.c")

if(WIN32)
    file(GLOB OS_SOURCES "src/windows/*.c")
else()
    file(FLOB OS_SOURCES "src/windows/*.c")
endif()

add_executable(${PROJECT_NAME} ${COMMON_SOURCES} ${OS_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_directories(${PROJECT_NAME} PRIVATE lib)
