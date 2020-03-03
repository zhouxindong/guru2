#pragma once

/**
 * 成员指针指向类的非静态成员
 成员指针类型: 类的类型 + 成员的类型 const std::string Screen::*pdata; 
 初始化: 令其指向类的某个成员 pdata = &Screen::contents;
 使用: 提供成员所属的对象 obj.*pdata, pt->*pdata
 */

/**
 * 成员函数指针
 char (Screen::*pmf2)(Screen::pos, Screen::pos) const;
 pmf2 = &Screen::get
 和普通函数指针不同，在成员函数和指向该成员的指针之间不存在自动转换规则
 (pt->*pmf2)();
 (obj.*pmf2)();
 */