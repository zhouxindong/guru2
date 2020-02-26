#pragma once
// const��Ҫ�����ƾ���ֻ����const���Ͷ�����ִ�в��ı������ݵĲ���
// ȱʡ״̬�£�const��������ļ�����Ч
const int kBufSize = 512;

const int GetConst()
{
	return 10;
}

constexpr int GetConst2()
{
	return 10;
}

//int buf[GetConst()]; // const����ǿ����������ʱ����
int buf[GetConst2()];	// constexpr���������ʽ�������ڳ���

// const�������һ�����壬�����ļ��й���
// extern const int kBufSize = fcn(); .cpp
// extern const int kBufSize; //.h

template <char const* str>
class Message {
};

extern char const hello[] = "Hello World!";	// external linkage
char const hello11[] = "Hello World!";		// internal linkage

void foo()
{
	static char const hello17[] = "Hello World!";	// any linkage

	Message<hello> msg03;
	Message<hello11> msg11;
	//Message<hello17> msg17;
}

/**
 * ���Ա����constʱ����ʵ���޸���ʽthisָ�������
 ȱʡʱthis������ָ�������ͷǳ����汾�ĳ���ָ��: type *const
 �����䲻�ܰ󶨵�һ�����������ϡ�
 ��const���γ�Ա��������ʵ���޸���thisָ�������: const type *const��ʹ�����ܹ����󶨵Ķ���Χ������

 ����const��Ա�ͷ�const��Ա�����������أ���Ϊ����ʽ��thisָ������Ͳ�ͬ�����䷵�ز�ͬ����(const, nonconst)����
 ����ʱ��const������ƥ��const�汾����constƥ���const�汾
 ͨ�����ڷ����������͵ĺ����ṩ�����汾: const�汾�ͷ�const�汾
 */

/**
 * ��Ա��������const�޶����⣬��������������޶������޶��ܹ����øó�Ա�����Ķ��������: &, &&
 ����ͬʱ�������а汾�������޶���������ֻ����һ��
 Foo anotherMem() const &;
 */
#include <vector>
class Foo {
public:
	Foo sorted() &&;	// �����ڿɸı����ֵ
	Foo sorted() const &;	// �������κ����͵�Foo
private:
	std::vector<int> data;
};

// ������Ϊ��ֵ����˿���ԭַ����
Foo Foo::sorted() &&
{
	sort(data.begin(), data.end());
	return *this;
}

// ��������const����һ����ֵ������ԭַ����
Foo Foo::sorted() const & {
	Foo ret(*this);
	sort(ret.data.begin(), ret.data.end());
	return ret; // ���ظ���
}