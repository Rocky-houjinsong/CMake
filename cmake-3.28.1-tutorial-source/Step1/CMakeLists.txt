# TODO 1: Set the minimum required version of CMake to be 3.10  
cmake_minimum_required(VERSION 3.10)  #设置 CMake最低版本
# TODO 2: Create a project named Tutorial
#project (Tutorial)   # 设置项目名称
# TODO 7: Set the project version number as 1.0 in the above project command
# 设置项目的时候,同时设置 版本号, 后面的MAJOR 和MINOR读取的就是小数点前后两个数字
project(Tutorial VERSION 2.11)
# TODO 6: Set the variable CMAKE_CXX_STANDARD to 11
#         and the variable CMAKE_CXX_STANDARD_REQUIRED to True
# C++标准变量枚举值 有 (98, 11,14,17,20,23等 其他报错)  ?? 如何 查看当前版本
# VS 可能要重新清理缓存  但 我清理之后依然还是 199711 ,其他平台的有用的

set(CMAKE_CXX_STANDARD 20) # 设置启用的C++标准为 11 
set(CMAKE_CXX_STANDARD_REQUIRED true)  #  启用C++标准

#在CMakeLists.txt定义变量, 有CPP文件进行读取
#放在此处 , 设置后,可能不会理解刷新到 头文件 ,重新走命令行 重新cmake .. 一下 , 就可以
set(STR_TEST "Hello World!")
# TODO 8: Use configure_file to configure and copy TutorialConfig.h.in to
#         TutorialConfig.h
# 输入文件/模板文件  --> 输出文件
# 输出文件 放到Build 文件夹下  此时 , 生成文件在 build文件夹内, 而要在 build同级文件(tutorial.cxx) 中使用,如何 找到呢?无法直接包含,所以要指定 头文件的路径
configure_file(TutorialConfig.h.in TutorialConfig.h)   #复制输入文件并替换指定的CMake变量
# TODO 3: Add an executable called Tutorial to the project
# Hint: Be sure to specify the source file as tutorial.cxx
add_executable(Tutorial tutorial.cxx)  #添加 可执行文件,  一定要指定 源文件 
# TODO 9: Use target_include_directories to include ${PROJECT_BINARY_DIR}
#指定可执行目标 应在何处 查找包含文件  --->? 因为要添加的头文件 TutorialConfig.h无法直接包含,所以要指定路径
# build目录 可以使用 PROJECT_BINARY_DIR  进行表示 
# PUBLIC PRIVATE INTERFACE
# 若 路径无空格,可使用{},如果有空格,使用"" 进行包含
target_include_directories(Tutorial PUBLIC 
						"${PROJECT_BINARY_DIR}"
						)

#Specify MSVC UTF-8 encoding   添加以下两行 做UTF8编译
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "${Tutorial_VERSION_MAJOR}")
message(STATUS "${Tutorial_VERSION_MINOR}")




