# TODO 1: Set the minimum required version of CMake to be 3.10  
cmake_minimum_required(VERSION 3.10)  #设置 CMake最低版本
# TODO 2: Create a project named Tutorial
project (Tutorial)   # 设置项目名称
# TODO 7: Set the project version number as 1.0 in the above project command
project(Tutorial VERSION 1.0)
# TODO 6: Set the variable CMAKE_CXX_STANDARD to 11
#         and the variable CMAKE_CXX_STANDARD_REQUIRED to True
set(CMAKE_CXX_STANDARD 11) # 设置启用的C++标准为 11 
set(CMAKE_CXX_STANDARD_REQUIRED true)  #  启用C++标准
# TODO 8: Use configure_file to configure and copy TutorialConfig.h.in to
#         TutorialConfig.h
configure_file(TutorialConfig.h.in TutorialConfig.h)   #复制输入文件并替换指定的CMake变量
# TODO 3: Add an executable called Tutorial to the project
# Hint: Be sure to specify the source file as tutorial.cxx
add_executable(Tutorial tutorial.cxx)  #添加 可执行文件,  一定要指定 源文件 
# TODO 9: Use target_include_directories to include ${PROJECT_BINARY_DIR}
#指定可执行目标 应在何处 查找包含文件
target_include_directories(Tutorial PUBLIC 
						"${PROJECT_BINARY_DIR}"
						)

#Specify MSVC UTF-8 encoding   添加以下两行 做UTF8编译
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")