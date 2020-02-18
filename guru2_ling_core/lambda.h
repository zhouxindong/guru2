#pragma once
/**
 * lambda只是匿名仿函数(闭包)，从其父作用域中取得参数
 (可以直接访问其父作用域中的static或之外作用域的变量)
 */

/**
 * 捕获列表
 1. []
 2. [names]	值捕获，&为引用捕获
 3. [&]		引用捕获，参数由执行体自动推断
 4. [=]
 5. [&, identifier_list]	缺省引用捕获，identifier_list值捕获
 6. [=, identifier_list]
 */