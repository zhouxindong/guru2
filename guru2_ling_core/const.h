#pragma once
// const��Ҫ�����ƾ���ֻ����const���Ͷ�����ִ�в��ı������ݵĲ���
// ȱʡ״̬�£�const��������ļ�����Ч
const int kBufSize = 512;

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