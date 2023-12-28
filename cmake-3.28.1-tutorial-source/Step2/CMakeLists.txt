cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(TutorialConfig.h.in TutorialConfig.h)

# TODO 2: Use add_subdirectory() to add MathFunctions to this project
add_subdirectory(MathFunctions)   #在顶级CMakeLists中 提供调用新库
# add the executable
add_executable(Tutorial tutorial.cxx)

# TODO 3: Use target_link_libraries to link the library to our executable
# 使用新的库 目标 链接到 可执行文件中
target_link_libraries(Tutorial PUBLIC MathFunctions)
# TODO 4: Add MathFunctions to Tutorial's target_include_directories()
# Hint: ${PROJECT_SOURCE_DIR} is a path to the project source. AKA This folder!

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
#指定库的头文件位置(子文件添加,链接到可执行文件,最后才 指定库的头文件位置 这个步骤完成,才可以使用我们的库)

target_include_directories(Tutorial PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/MathFunctions"
                          )

#message 在 cmake .. 阶段在终端 可以查看到
#两个 message比较发现 ,该变量 PROJECT_SOURCE_DIR  指的是 project所在的文件路径 都是一样的
message(STATUS out --"${PROJECT_SOURCE_DIR}")