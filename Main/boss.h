#pragma once
#include "Worker.h"

class boss :public worker {

public:
	boss(int id, string name, int detid);

	//չʾ������Ϣ
	virtual void show_Info();
	//��ȡ��λ����
	virtual string get_DepNum();
};