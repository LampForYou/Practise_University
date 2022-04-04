#include "employee.h"

employee::employee(int id, string name, int detid) {
	m_ID = id;
	m_Name = name;
	m_DetID = detid;
}


void employee::show_Info() {

	cout << "职工编号： " << m_ID
	 << " \t职工姓名： " << m_Name
	 << " \t岗位：" << get_DepNum()
	 << " \t岗位职责：完成经理交给的任务" << endl;
}

string employee::get_DepNum() {

	return string("员工");

}