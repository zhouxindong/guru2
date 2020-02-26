#pragma once

#include <memory>
#include <string>

/**
 * shared_ptr和 unique_ptr都支持的操作
 shared_ptr<T> sp, unique_ptr<T> up
 p	隐式bool转换，若p指向一个对象，则为true
 *p
 p->mem
 p->get()	返回p中保存的指针
 swap(p, q)
 p.swap(q)
 p.reset(), p.reset(q), p.reset(q,d) //释放对象，释放对象并指向q，同时使用d而不是缺省delete来释放对象
 */

/**
 * shared_ptr
 make_shared<T>(args)	返回一个shared_ptr,指向一个动态分配的类型T的对象
 shared_ptr<T>p (q)
 p = q
 p.unique()	是否是唯一指向
 p.use_count()
 */

void foo()
{
	// 用传递的参数构造给定类型的对象
	std::shared_ptr<int> p3 = std::make_shared<int>(42);
	std::shared_ptr<std::string> p2 = std::make_shared<std::string>(10, '9');
	std::shared_ptr<int> p4(new int(1024));
}

void foo2()
{
	std::shared_ptr<std::string> p(new std::string("hello"));
	if (!p.unique())
		p.reset(new std::string(*p));
	*p += " world";	// 现在p是唯一用户
}

/**
 * 用shared_ptr包装资源类的释放
 智能指针管理的资源不是new分配的内存时，传递给它一个删除器(取代缺省的delete操作)
 */
struct connection {};
void disconnection(connection) {}

void end_connection(connection* p)
{
	disconnection(*p);
}

void f()
{
	connection c;
	std::shared_ptr<connection> p(&c, end_connection);
}

/**
 * unique_ptr
 unique_ptr<T> u1
 unique_ptr<T, D> u2
 unique_ptr<T, D> u(d)
 u = nullptr
 u.release() // 返回指针，放置所有权(注意没有delete指针)
 u.reset()
 u.reset(q)
 u.reset(nullptr)
 */
void foo3()
{
	std::unique_ptr<int> up(new int(42));
	// unique_ptr不支持拷贝构造、赋值，但可以将所有权转移
	// 但是可以拷贝或赋值一个将要被销毁的unique_ptr，如函数返回值(支持移动构造、赋值)

	std::unique_ptr<std::string> p1(new std::string("hello"));
	std::unique_ptr<std::string> p2(p1.release()); // p1置空，返回值初始化p2
	std::unique_ptr<std::string> p3(new std::string("Trex"));
	p2.reset(p3.release()); // reset释放p2原先指向的内存，如果有参数，则用参数值初始化
}

/**
 * unique_ptr的删除器指定略有不同
 */
void f2() {
	connection c;
	std::unique_ptr<connection, decltype(end_connection)*> p(&c, end_connection);
}