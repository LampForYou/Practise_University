#include "boss.h"

boss::boss(int id, string name, int detid) {
	m_ID = id;
	m_Name = name;
	m_DetID = detid;
}


void boss::show_Info() {

	cout << "ְ����ţ� " << m_ID
	 << " \tְ�������� " << m_Name
	 << " \t��λ��" << get_DepNum()
	 << " \t��λְ�𣺹���˾��������" << endl;
}

string boss::get_DepNum() {

	return string("boss�ϰ�");

}