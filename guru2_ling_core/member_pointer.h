#pragma once

/**
 * ��Աָ��ָ����ķǾ�̬��Ա
 ��Աָ������: ������� + ��Ա������ const std::string Screen::*pdata; 
 ��ʼ��: ����ָ�����ĳ����Ա pdata = &Screen::contents;
 ʹ��: �ṩ��Ա�����Ķ��� obj.*pdata, pt->*pdata
 */

/**
 * ��Ա����ָ��
 char (Screen::*pmf2)(Screen::pos, Screen::pos) const;
 pmf2 = &Screen::get
 ����ͨ����ָ�벻ͬ���ڳ�Ա������ָ��ó�Ա��ָ��֮�䲻�����Զ�ת������
 (pt->*pmf2)();
 (obj.*pmf2)();
 */