#include "manager.h"

manager::manager(int id, string name, int detid) {
	m_ID = id;
	m_Name = name;
	m_DetID = detid;
}

void manager::show_Info() {

	cout << "职工编号： " << m_ID
	<< " \t职工姓名： " << m_Name
	<< " \t岗位：" << get_DepNum()
	<< " \t岗位职责：完成老板交给的任务,并下发任务给员工" << endl;
}

string manager::get_DepNum() {

	return string("经理");

}