#pragma once  //��֤��ͬһ���ļ����ᱻ������Ρ�ע��������˵�ġ�ͬһ���ļ�����ָ�����ϵ�һ���ļ���������ָ������ͬ�������ļ���
#include<iostream>
using namespace std;
#include "worker.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include "worker.h"
#include <fstream>
#define  FILENAME "empfile.txt"
#include <string>

class WorkManage {
public:
	WorkManage();

	~WorkManage();

	//չʾ�˵�
	void show_Menu();

	//�Ƴ�����
	void ExitSystem();

	//��¼�ļ��е���������
	int m_EmpNum;

	//Ա�������ָ��
	worker** m_EmpArray;

	//����Ա��
	void Add_Emp();

	//�����ļ�
	void save();

	//��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//��ȡ��ǰ�ļ�����Ա��Ŀ
	int get_EmpNum();

	//���ļ��г�ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//����ְ������ж�ְ���Ƿ����,�����ڷ���ְ����������λ�ã������ڷ���-1
	int IsExist(int id);

	//�޸�ְ��
	void Change_Emp();

	//����ְ��
	void Find_Emp();

	//����ְ��
	void Sort_Emp();

	//����ļ�
	void Clean_File();
};