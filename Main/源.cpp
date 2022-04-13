#include <iostream>
#include "WorkManage.h"
using namespace std;

//#include "boss.h"
//#include "employee.h"
//#include "manager.h"
//#include "worker.h"

void text01() {            //验证多态
    
    worker* worker = NULL;
    worker = new employee(1, "张三", 1);
    worker->show_Info();
    delete worker;

    worker = new manager(2, "李四", 2);
    worker->show_Info();
    delete worker;

    worker = new boss(3, "王五", 3);
    worker->show_Info();
    delete worker;
}

int main() {

	WorkManage Wm;
	int choice = 0;
	while (true)
	{
	
		Wm.show_Menu();
        cout << "当前人员个数: " << Wm.m_EmpNum << endl;
		cout << "请按提示选择功能" << endl;
		cin >> choice;
	
		switch (choice)
		{
        case 0: //退出系统
            Wm.ExitSystem();
            break;
        case 1: //添加职工
            Wm.Add_Emp();
            break;
        case 2: //显示职工
            Wm.Show_Emp();
            break;
        case 3: //删除职工
            Wm.Del_Emp();
            break;
        case 4: //修改职工
            Wm.Change_Emp();
            break;
        case 5: //查找职工
            Wm.Find_Emp();
            break;
        case 6: //排序职工
            Wm.Sort_Emp();
            break;
        case 7: //清空文件
            Wm.Clean_File();
            break;
        default: 
            system("cls");    //清空屏幕
            break;
		}
	}	
    system("pause");


	return 0;
}