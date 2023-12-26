# TODO 14: Remove mysqrt.cxx from the list of sources

# TODO 1: Add a library called MathFunctions with sources MathFunctions.cxx
# and mysqrt.cxx
# Hint: You will need the add_library command
#创建 一个 名为 xxx的库, 将 涉及到的cxx文件添加进来,提供编译,对应的h文件也可添加,一般如果在对应的cxx文件中引用(include) 
add_library(MathFunctions MathFunctions.cxx)

# TODO 7: Create a variable USE_MYMATH using option and set default to ON
# 该选项 可由用户更改
option(USE_MYMATH "Use tutorial provided math implementation,this is 提示信息:" ON)
message(STATUS USE_MYMATH = "${USE_MYMATH}")
# TODO 8: If USE_MYMATH is ON, use target_compile_definitions to pass
# USE_MYMATH as a precompiled definition to our source files
# 检查值,若是则启用源代码中的某些部分
if(USE_MYMATH)
	target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")
endif()
# TODO 12: When USE_MYMATH is ON, add a library for SqrtLibrary with
# source mysqrt.cxx
add_library(SqrtLibrary STATIC 
			mysqrt.cxx

)
# TODO 13: When USE_MYMATH is ON, link SqrtLibrary to the MathFunctions Library
target_link_libraries(MathFunctions PRIVATE SqrtLibrary)


message(STATUS MathFunctions -$$- "${PROJECT_SOURCE_DIR}")