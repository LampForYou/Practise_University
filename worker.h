#pragma once
#include<iostream>
#include<string>
using namespace std;

class worker {

public:

	//��ʾ������Ϣ
	virtual void show_Info() = 0;

	//��ȡ��λ����
	virtual string get_DepNum() = 0;

	int m_ID;  //ְ�����
	string m_Name;   //ְ������
	int m_DetID;   //��λ���
};