#pragma once
#include "Worker.h"
#include<iostream>
using namespace std;

class employee :public worker {

public:
	employee(int id, string name, int detid);

	//展示个人信息
	virtual void show_Info();
	//获取岗位名称
	virtual string get_DepNum();

};