#pragma once  //保证：同一个文件不会被包含多次。注意这里所说的“同一个文件”是指物理上的一个文件，而不是指内容相同的两个文件。
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

	//展示菜单
	void show_Menu();

	//推出功能
	void ExitSystem();

	//记录文件中的人数个数
	int m_EmpNum;

	//员工数组的指针
	worker** m_EmpArray;

	//增加员工
	void Add_Emp();

	//保存文件
	void save();

	//标志文件是否为空
	bool m_FileIsEmpty;

	//获取当前文件中人员数目
	int get_EmpNum();

	//从文件中初始化员工
	void init_Emp();

	//显示职工
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1
	int IsExist(int id);

	//修改职工
	void Change_Emp();

	//查找职工
	void Find_Emp();

	//排序职工
	void Sort_Emp();

	//清空文件
	void Clean_File();
};