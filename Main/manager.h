#pragma once
#include<iostream>
using namespace std;
#include <string>
#include "Worker.h"

class manager :public worker {

public:

public:
	manager(int id, string name, int detid);

	//展示个人信息
	virtual void show_Info();
	//获取岗位名称
	virtual string get_DepNum();

};