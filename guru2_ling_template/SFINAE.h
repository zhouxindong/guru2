#pragma once

// SFINAE���ں���ģ��Ĳ�ͬʵ��ѡ��
/**
 * ����decltypeָ��ģ�������Լ��
 * ��decltype�Ŀ�ʼ����������Լ��(ת��Ϊvoid��ֹ�������������)
 * �����һ������������ʵ�ķ�������
 */
template <typename T>
auto len(T const& t) -> decltype((void)(t.size()), T::size_type())
{
	return t.size();
}

/**
 * ���ֻ��ڱ�������������������ض����ļ���
 * 1. �ֲ��ﻯ
 * 2. SFINAE
 * 3. std::enable_if
 * 4. if constexpr(...)
 */