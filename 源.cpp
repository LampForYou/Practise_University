#include <iostream>
#include "WorkManage.h"
using namespace std;

//#include "boss.h"
//#include "employee.h"
//#include "manager.h"
//#include "worker.h"

void text01() {            //��֤��̬
    
    worker* worker = NULL;
    worker = new employee(1, "����", 1);
    worker->show_Info();
    delete worker;

    worker = new manager(2, "����", 2);
    worker->show_Info();
    delete worker;

    worker = new boss(3, "����", 3);
    worker->show_Info();
    delete worker;
}

int main() {

	WorkManage Wm;
	int choice = 0;
	while (true)
	{
	
		Wm.show_Menu();
        cout << "��ǰ��Ա����: " << Wm.m_EmpNum << endl;
		cout << "�밴��ʾѡ����" << endl;
		cin >> choice;
	
		switch (choice)
		{
        case 0: //�˳�ϵͳ
            Wm.ExitSystem();
            break;
        case 1: //���ְ��
            Wm.Add_Emp();
            break;
        case 2: //��ʾְ��
            Wm.Show_Emp();
            break;
        case 3: //ɾ��ְ��
            Wm.Del_Emp();
            break;
        case 4: //�޸�ְ��
            Wm.Change_Emp();
            break;
        case 5: //����ְ��
            Wm.Find_Emp();
            break;
        case 6: //����ְ��
            Wm.Sort_Emp();
            break;
        case 7: //����ļ�
            Wm.Clean_File();
            break;
        default: 
            system("cls");    //�����Ļ
            break;
		}
	}	
    system("pause");


	return 0;
}