#pragma once
#include<iostream>
#include<string>
using namespace std;

class worker {

public:

	//显示个人信息
	virtual void show_Info() = 0;

	//获取岗位名称
	virtual string get_DepNum() = 0;

	int m_ID;  //职工编号
	string m_Name;   //职工姓名
	int m_DetID;   //岗位编号
};