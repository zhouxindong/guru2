#pragma once

#include <memory>
#include <string>

/**
 * shared_ptr�� unique_ptr��֧�ֵĲ���
 shared_ptr<T> sp, unique_ptr<T> up
 p	��ʽboolת������pָ��һ��������Ϊtrue
 *p
 p->mem
 p->get()	����p�б����ָ��
 swap(p, q)
 p.swap(q)
 p.reset(), p.reset(q), p.reset(q,d) //�ͷŶ����ͷŶ���ָ��q��ͬʱʹ��d������ȱʡdelete���ͷŶ���
 */

/**
 * shared_ptr
 make_shared<T>(args)	����һ��shared_ptr,ָ��һ����̬���������T�Ķ���
 shared_ptr<T>p (q)
 p = q
 p.unique()	�Ƿ���Ψһָ��
 p.use_count()
 */

void foo()
{
	// �ô��ݵĲ�������������͵Ķ���
	std::shared_ptr<int> p3 = std::make_shared<int>(42);
	std::shared_ptr<std::string> p2 = std::make_shared<std::string>(10, '9');
	std::shared_ptr<int> p4(new int(1024));
}

void foo2()
{
	std::shared_ptr<std::string> p(new std::string("hello"));
	if (!p.unique())
		p.reset(new std::string(*p));
	*p += " world";	// ����p��Ψһ�û�
}

/**
 * ��shared_ptr��װ��Դ����ͷ�
 ����ָ��������Դ����new������ڴ�ʱ�����ݸ���һ��ɾ����(ȡ��ȱʡ��delete����)
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
 u.release() // ����ָ�룬��������Ȩ(ע��û��deleteָ��)
 u.reset()
 u.reset(q)
 u.reset(nullptr)
 */
void foo3()
{
	std::unique_ptr<int> up(new int(42));
	// unique_ptr��֧�ֿ������졢��ֵ�������Խ�����Ȩת��
	// ���ǿ��Կ�����ֵһ����Ҫ�����ٵ�unique_ptr���纯������ֵ(֧���ƶ����졢��ֵ)

	std::unique_ptr<std::string> p1(new std::string("hello"));
	std::unique_ptr<std::string> p2(p1.release()); // p1�ÿգ�����ֵ��ʼ��p2
	std::unique_ptr<std::string> p3(new std::string("Trex"));
	p2.reset(p3.release()); // reset�ͷ�p2ԭ��ָ����ڴ棬����в��������ò���ֵ��ʼ��
}

/**
 * unique_ptr��ɾ����ָ�����в�ͬ
 */
void f2() {
	connection c;
	std::unique_ptr<connection, decltype(end_connection)*> p(&c, end_connection);
}