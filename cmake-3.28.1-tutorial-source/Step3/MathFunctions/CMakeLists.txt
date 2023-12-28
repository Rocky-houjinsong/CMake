add_library(MathFunctions MathFunctions.cxx)

# TODO 1: State that anybody linking to MathFunctions needs to include the
# current source directory, while MathFunctions itself doesn't.
# Hint: Use target_include_directories with the INTERFACE keyword
# 任何 链接 类库a的项目 都需要 类库a的文件路径 ,但 类库a本身不需要 ; 使用`interface` 
target_include_directories(MathFunctions 
                            INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "MathFunctions ======= ${CMAKE_CURRENT_SOURCE_DIR}")
# should we use our own math functions
option(USE_MYMATH "Use tutorial provided math implementation" ON)
message(STATUS "USE_MYMATH ======= ${USE_MYMATH}")
if (USE_MYMATH)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")
endif()
  # library that just does sqrt
  add_library(SqrtLibrary STATIC
              mysqrt.cxx
              )

  # TODO 7: Link SqrtLibrary to tutorial_compiler_flags
  target_link_libraries(MathFunctions PUBLIC tutorial_compiler_flags)
  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)


# TODO 6: Link MathFunctions to tutorial_compiler_flags
target_link_libraries(SqrtLibrary PUBLIC tutorial_compiler_flags)