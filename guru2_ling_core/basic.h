#pragma once

/**
 * 类有三种用户:
 1. 普通用户
	使用类的对象，只能访问类的公有(接口)成员
 2. 类的实现者
	编写类的成员和友元代码，既能访问类的公有部分，也能访问类的私有部分(实现)
 3. 派生类
	可以使用基类的保护部分，无法访问私有部分
 三种用户可以对应类的三种可访问性
 */

/**
 * 类的作用域
 类的定义体内也就是类的作用域，派生类的作用域嵌套在基类的作用域之内，名称的查找从自己的作用域开始，逐层向外
 类模板在自己的作用域内不需要模板参数信息。在类模板外，直到遇到类名才表示进入类的作用域。
 */