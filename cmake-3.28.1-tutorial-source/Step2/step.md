> 创建 链接库 , 默认是静态库

* 在 `mathFunctions`文件夹下  ` add_library`
  * 类库下 无需 添加最小版本号 等   
* 顶层  添加子文件夹  
  * ` add_subdirectory添加的是文件夹  --- 搜索 到 源代码 
  * `target_link_libraries`   链接 类库的源代码 
    * `target_include_directionries `  提供搜索路径  包含到头文件中提供使用



---

option  cmakedefine  以及  和 define的 区别

* option  创建 可选 变量
* cmakedefint  和  define  作用基本相同,稍有一些区别
* 当 获取的值是0 , define 存在, cmakedefine 则 自动注释掉 ; 非零值  二者都存在
* 对于 bool值 false , cmakedefine 也被注释掉

总结: define 任何情况都会定义, cmakedefine  只有 值被定义,且非0 或 true才会被定义