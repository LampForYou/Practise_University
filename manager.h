#pragma once
#include<iostream>
using namespace std;
#include <string>
#include "Worker.h"

class manager :public worker {

public:

public:
	manager(int id, string name, int detid);

	//չʾ������Ϣ
	virtual void show_Info();
	//��ȡ��λ����
	virtual string get_DepNum();

};