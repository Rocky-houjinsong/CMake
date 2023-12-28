# TODO 1: Update the minimum required version to 3.15

cmake_minimum_required(VERSION 3.15)

# set the project name and version
project(Tutorial VERSION 1.0)
#配置阶段 message无法定位跟踪  生成器表达式 
message(STATUS "$<1:Hello>")
#使用该语句 在生成阶段定位跟踪  ged :generate debug 缩写
#生成阶段  指定目标即可 cmake --build . --target ged
#设置为0 ,输出空字符串
add_custom_target(ged COMMAND ${CMAKE_COMMAND} -E echo "$<1:hello>")
# specify the C++ standard
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

# TODO 2: Create helper variables to determine which compiler we are using:
# * Create a new variable gcc_like_cxx that is true if we are using CXX and
#   any of the following compilers: ARMClang, AppleClang, Clang, GNU, LCC
# * Create a new variable msvc_cxx that is true if we are using CXX and MSVC
# Hint: Use set() and COMPILE_LANG_AND_ID
# 两个变量, 值的根据生成器表达式设定
#返回输出 1, 0 
#而<1:值> 则输出, <0:"">输出空白 这是另一个 生成器表达式
#针对 当前编译器 制作一个警告
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
# TODO 3: Add warning flag compile options to the interface library
# tutorial_compiler_flags.
# * For gcc_like_cxx, add flags -Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused
# * For msvc_cxx, add flags -W3
# Hint: Use target_compile_options()
#添加编译警告
#变量访问的方式来编写
target_compile_options(tutorial_compiler_flags INTERFACE
           "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>"
           "$<${msvc_cxx}:-W3>"
)
# TODO 4: With nested generator expressions, only use the flags for the
# build-tree
# Hint: Use BUILD_INTERFACE

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(TutorialConfig.h.in TutorialConfig.h)

# add the MathFunctions library
add_subdirectory(MathFunctions)

# add the executable
add_executable(Tutorial tutorial.cxx)

target_link_libraries(Tutorial PUBLIC MathFunctions tutorial_compiler_flags)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
