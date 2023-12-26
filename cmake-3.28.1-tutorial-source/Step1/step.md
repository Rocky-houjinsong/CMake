 https://cmake.org/cmake/help/latest/guide/tutorial

* 最小版本  
* 设置项目名称
* 添加 可执行文件  

> 以上 三步 设置成功,  可以 完成  一个可执行程序 的链接生成 

* 启用 C++ 标准 
* 单一变量 单独 独立 并重定向  



---

> :interrobang:  如何测试?  
>
> * 在Visual studio  中打开Powershell 
>
> * 测试指令集合 
>
>   * ```cmake
>     #在Step1 的build路径下
>     #删除build文件夹下内容
>     cmake ..
>     cmake --build .
>     #进入 Build/Debug文件夹下  
>     Tutorial 10     # 调用 平方根函数
>     Tutorial  # 调用返回 版本等基本信息
>     ```
>
>     
>
>



> 通过一个 模板文件(.in)  一个 头文件(.h)  和 一个 `configure_file`  命令   实现 CMake变量 可被 CPP文件读取到
>
> 对应头文件目标 搜索路径  
