#include "manager.h"

manager::manager(int id, string name, int detid) {
	m_ID = id;
	m_Name = name;
	m_DetID = detid;
}

void manager::show_Info() {

	cout << "ְ����ţ� " << m_ID
	<< " \tְ�������� " << m_Name
	<< " \t��λ��" << get_DepNum()
	<< " \t��λְ������ϰ彻��������,���·������Ա��" << endl;
}

string manager::get_DepNum() {

	return string("����");

}