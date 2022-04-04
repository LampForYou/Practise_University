#include "WorkManage.h"


WorkManage::WorkManage(){

    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int num = 0;             //每次文件运行更新成员个数 中间量
    //文件不存在情况
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl; //测试输出
        this->m_EmpNum = 0;  //初始化人数
        this->m_FileIsEmpty = true; //初始化文件为空标志
        this->m_EmpArray = NULL; //初始化数组
        ifs.close(); //关闭文件
        return;
    }

    //文件存在，并且没有记录
    char ch;
    ifs >> ch;             //先读一个再判断此时是否读到EOF
    if (ifs.eof())
    {
        cout << "文件为空!" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }
    else { 
        m_FileIsEmpty = false;
        num = get_EmpNum();
        m_EmpNum = num;
        m_EmpArray = new worker * [m_EmpNum];
        init_Emp();
    }
    
    m_EmpNum = num;

}

WorkManage::~WorkManage() {

    if (m_EmpArray != NULL) {
        delete[] m_EmpArray;
        m_EmpArray = NULL;
    }
}

void WorkManage::show_Menu(){

    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;

}

void WorkManage::ExitSystem() {

    cout << "欢迎下次使用" << endl;
    exit(0);
}

void WorkManage::Add_Emp() {              //以woreker **
    cout << "请输入增加的人员数" << endl;
    int new_num = 0;
    new_num:cin >> new_num;
    if (new_num > 0)
    
    {

        //计算新空间大小  
        int NewSize = m_EmpNum + new_num;

        //指针数组
        worker** newSpace = new worker * [NewSize];

        //转移原有空间到新空间
        if (m_EmpArray != NULL) {
            for (int i = 0; i < m_EmpNum; i++)
            {
                newSpace[i] = m_EmpArray[i];
            }
        }

        //输入新数据
        for (int i = 0; i < new_num; i++)
        {
            int id;
            string name;
            int dSelect=0;

            cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
            cin >> id;
            cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
            cin >> name;
            cout << "请选择该职工的岗位：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            dSelect:cin >> dSelect;
            worker* worker1 = NULL;
            if (dSelect > 3 || dSelect < 1) {
                cout << "未知岗位编号  请重新输入" << endl;
                cin.clear();  //清空cin状态符
                //cin.sync();   //清空流
                cin.ignore(1024, '\n');  //清楚 /n之前的1024个字符
                goto dSelect;
            }
            switch (dSelect)
            {
            case 1: //普通员工
                worker1 = new employee(id, name, 1);
                break;
            case 2: //经理
                worker1 = new manager(id, name, 2);
                break;
            case 3:  //老板
                worker1 = new boss(id, name, 3);
                break;
            default:
                break;

            }
            newSpace[m_EmpNum + i] = worker1;
        }

        //释放原有内存
        delete[] m_EmpArray;

        //重新指向增加后的内存
        m_EmpArray = newSpace;

        //更新职工不为空标志
        m_FileIsEmpty = false;

        //更新成员的个数
        m_EmpNum = NewSize;
        cout << "成功添加" << new_num << "名新职工！" << endl;

        //保存文件
        save();

    }
    else
    {
        cout << "输入错误" << endl;
        cout << "请重新输入" << endl;
        cin.clear();  //清空cin状态符
        //cin.sync();   //清空流
        cin.ignore(1024, '\n');  //清楚 /n之前的1024个字符
        goto new_num;
    }
    system("pause");
    system("cls");
}

//每次都需要重新写一遍数据
//可以优化
void WorkManage::save() {                  
    fstream ofs;

    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < m_EmpNum; i++) {
        ofs << m_EmpArray[i]->m_ID << " "
            << m_EmpArray[i]->m_Name << " "
            << m_EmpArray[i]->m_DetID << endl;
    }

    ofs.close();
}

int WorkManage::get_EmpNum(){
    
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    
    int id;
    string name;
    int dId;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        //记录人数
        num++;
    }
    ifs.close();

    return num;
}

void WorkManage::init_Emp() {

    fstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;  //worker** 数组用以存放人数
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        worker* worker = NULL;
        //根据不同的部门Id创建不同对象
        if (dId == 1)  // 1普通员工
        {
            worker = new employee(id, name, dId);
        }
        else if (dId == 2) //2经理
        {
            worker = new manager(id, name, dId);
        }
        else //总裁
        {
            worker = new boss(id, name, dId);
        }
        //存放在数组中
        this->m_EmpArray[index] = worker;
        index++;
    }

}

void WorkManage::Show_Emp() {

    if (m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        for (int i = 0; i < m_EmpNum; i++)
        {
            //利用多态调用接口
            m_EmpArray[i]->show_Info();
        }
    }

    system("pause");
    system("cls");
}

void WorkManage::Del_Emp(){

    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else {
        //按职工编号删除
        cout << "请输入想要删除的职工号：" << endl;
        int id; cin >> id;
        int index = IsExist(id);
        if (index != -1) {
            for (int i = index; i < this->m_EmpNum - 1; i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;
            save();
            cout << "删除成功！" << endl;
        }
        else{
            cout << "删除失败，未找到该职工" << endl;
        }
    }

    system("pause");
    system("cls");
}

int WorkManage::IsExist(int id) {

    int index = -1;

    for (int i = 0; i < m_EmpNum; i++)
    {
        if (this->m_EmpArray[i]->m_ID == id)
        {
            index = i;

            break;
        }
    }

    return index;
}

void WorkManage::Change_Emp() {

    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else {
        cout << "请输入修改职工的编号：" << endl;
        int id;
        cin >> id;

        int ret = IsExist(id);
        if (ret != -1)
        {
            delete m_EmpArray[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "已查到： " << id << "号职工，请输入新职工号： " << endl;
            cin >> newId;

            cout << "请输入新姓名： " << endl;
            cin >> newName;

            cout << "请输入岗位： " << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
        dSelectnew:cin >> dSelect;

            worker* workernew = NULL;
            if (dSelect > 3 || dSelect < 1) {
                cout << "未知岗位编号  请重新输入" << endl;
                cin.clear();  //清空cin状态符
                //cin.sync();   //清空流
                cin.ignore(1024, '\n');  //清楚 /n之前的1024个字符
                goto dSelectnew;
            }
            switch (dSelect)
            {
            case 1: //普通员工
                workernew = new employee(id, newName, dSelect);
                break;
            case 2: //经理
                workernew = new manager(id, newName, dSelect);
                break;
            case 3:  //老板
                workernew = new boss(id, newName, dSelect);
                break;
            default:
                break;

            }

            m_EmpArray[ret] = workernew;  //重新指向

            cout << "修改成功！" << endl;

            //保存到文件中
            save();
        }
        else {
            cout << "修改失败，查无此人" << endl;
        }
       
    }

    system("pause");
    system("cls");
}

void WorkManage::Find_Emp() {

    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else 
    {
        cout << "请输入查找的方式：" << endl;
        cout << "1、按职工编号查找" << endl;
        cout << "2、按姓名查找" << endl;

        int select = 0;
        cin >> select;

        //按职工号查找
        if (select == 1)
        {
            int id;
            cout << "请输入查找的职工编号：" << endl;
            cin >> id;

            int ret = IsExist(id);
            if (ret != -1)
            {
                cout << "查找成功！该职工信息如下：" << endl;
                m_EmpArray[ret]->show_Info();
            }
            else
            {
                cout << "查找失败，查无此人" << endl;
            }
        }

        //按姓名查找
        else if (select == 2) {

            string name;
            cout << "请输入查找的姓名：" << endl;
            cin >> name;

            bool flag = false;  //查找到的标志
            for (int i = 0; i < m_EmpNum; i++)
            {
                if (m_EmpArray[i]->m_Name == name)
                {
                    cout << "查找成功,职工编号为："
                        << m_EmpArray[i]->m_ID
                        << " 号的信息如下：" << endl;

                    flag = true;

                    this->m_EmpArray[i]->show_Info();
                }
            }

            if (flag == false)
            {
                //查无此人
                cout << "查找失败，查无此人" << endl;
            }

        }

        else {

        cout << "输入选项有误" << endl;

        }
    }

    system("pause");
    system("cls");
}

void WorkManage::Sort_Emp() {

    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
        system("pause");
        system("cls");
    }
    else {

        cout << "请选择排序方式： " << endl;
        cout << "1、按职工号进行升序" << endl;
        cout << "2、按职工号进行降序" << endl;

        int select = 0;
        sort:cin >> select;

        /*
        for (int i = 0; i < m_EmpNum - 1; i++)    //冒泡排序
        {
            
            for (int j = 0 ; j < m_EmpNum-1-i; j++) {
                
                if (select == 1)//升序
                {
                    if (m_EmpArray[j]->m_ID > m_EmpArray[j+1]->m_ID) {
                        worker* temp = m_EmpArray[j];
                        m_EmpArray[j] = m_EmpArray[j + 1];
                        m_EmpArray[j + 1] = temp;
                    }
                }

                else if (select == 2)//降序
                {
                    if (m_EmpArray[j]->m_ID < m_EmpArray[j + 1]->m_ID) {
                        worker* temp = m_EmpArray[j];
                        m_EmpArray[j] = m_EmpArray[j + 1];
                        m_EmpArray[j + 1] = temp;
                    }
                }

                else {
                    cout << "排序只有两种哦，请勿戏耍此程序！" << endl;
                    cout << "请重新输入排序方式 ：" << endl;
                    goto sort;
                }
            }
        }
        */


        //选择排序
        for (int i = 0; i < m_EmpNum; i++)           
        {
            int minOrMax = i;
            for (int j = i + 1; j < m_EmpNum; j++)
            {
                if (select == 1) //升序
                {
                    if (m_EmpArray[minOrMax]->m_ID > m_EmpArray[j]->m_ID)
                    {
                        minOrMax = j;
                    }
                }
                else if (select == 2)  //降序
                {
                    if (m_EmpArray[minOrMax]->m_ID < m_EmpArray[j]->m_ID)
                    {
                        minOrMax = j;
                    }
                }
        
                else {
                    cout << "排序只有两种哦，请勿戏耍此程序！" << endl;
                    cout << "请重新输入排序方式 ：" << endl;
                    goto sort;
                }
            }
        
            if (i != minOrMax)
            {
                worker* temp = m_EmpArray[i];
                m_EmpArray[i] = m_EmpArray[minOrMax];
                m_EmpArray[minOrMax] = temp;
            }
        
        }

        cout << "排序成功,排序后结果为：" << endl;
        save();
        Show_Emp();

        //system("pause");
        system("cls");
    }
}

void WorkManage::Clean_File() {

    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        //打开模式 ios::trunc 如果存在删除文件并重新创建
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i] != NULL)
                {
                    delete this->m_EmpArray[i];
                }
            }
            this->m_EmpNum = 0;
            delete[] m_EmpArray;
            m_EmpArray = NULL;
            m_FileIsEmpty = true;
        }
        cout << "清空成功！" << endl;
    }

    system("pause");
    system("cls");
}