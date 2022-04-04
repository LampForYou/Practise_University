#include "boss.h"

boss::boss(int id, string name, int detid) {
	m_ID = id;
	m_Name = name;
	m_DetID = detid;
}


void boss::show_Info() {

	cout << "职工编号： " << m_ID
	 << " \t职工姓名： " << m_Name
	 << " \t岗位：" << get_DepNum()
	 << " \t岗位职责：管理公司所有事务" << endl;
}

string boss::get_DepNum() {

	return string("boss老板");

}