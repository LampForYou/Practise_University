#pragma once
#include "Worker.h"
#include<iostream>
using namespace std;

class employee :public worker {

public:
	employee(int id, string name, int detid);

	//չʾ������Ϣ
	virtual void show_Info();
	//��ȡ��λ����
	virtual string get_DepNum();

};