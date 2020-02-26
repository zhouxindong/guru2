#pragma once

/**
 * 1. operator*()
 你可以令operator*完成任何操作，但通常返回某个引用

   2. operator->()
   你不能改变其内置语义，你只能改变->从哪个对象当中获取成员，所以必须返回指针或重载了->的类对象
   对于形如point->mem的表达式来说，point必须是指向类对象的指针或重载了->的类的对象
   前者(*point).mem，后者point.operator()->mem
 */