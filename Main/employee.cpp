#include "employee.h"

employee::employee(int id, string name, int detid) {
	m_ID = id;
	m_Name = name;
	m_DetID = detid;
}


void employee::show_Info() {

	cout << "ְ����ţ� " << m_ID
	 << " \tְ�������� " << m_Name
	 << " \t��λ��" << get_DepNum()
	 << " \t��λְ����ɾ�����������" << endl;
}

string employee::get_DepNum() {

	return string("Ա��");

}