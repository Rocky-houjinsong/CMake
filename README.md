# CMake
学习CMake



---

## 开发经验集合 

---

* CMake 多使用 终端  操作  

* CMakeLists.txt  和 CPP文件 分别由 CMake解析器 和  C++编译器 操作 二者是独立不共通的

  > 如果在CMakeList.txt中定义 变量,  是无法让CPP文件直接读取的

  * :interrobang: CPP文件如何访问到CMakLists中保存的变量呢?





* UTF8设置

  * ```cmake
    #Specify MSVC UTF-8 encoding   添加以下两行 做UTF8编译
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
    ```

    
