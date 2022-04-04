#include "WorkManage.h"


WorkManage::WorkManage(){

    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int num = 0;             //ÿ���ļ����и��³�Ա���� �м���
    //�ļ����������
    if (!ifs.is_open())
    {
        cout << "�ļ�������" << endl; //�������
        this->m_EmpNum = 0;  //��ʼ������
        this->m_FileIsEmpty = true; //��ʼ���ļ�Ϊ�ձ�־
        this->m_EmpArray = NULL; //��ʼ������
        ifs.close(); //�ر��ļ�
        return;
    }

    //�ļ����ڣ�����û�м�¼
    char ch;
    ifs >> ch;             //�ȶ�һ�����жϴ�ʱ�Ƿ����EOF
    if (ifs.eof())
    {
        cout << "�ļ�Ϊ��!" << endl;
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
    cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
    cout << "*************  0.�˳��������  *************" << endl;
    cout << "*************  1.����ְ����Ϣ  *************" << endl;
    cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
    cout << "*************  3.ɾ����ְְ��  *************" << endl;
    cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
    cout << "*************  5.����ְ����Ϣ  *************" << endl;
    cout << "*************  6.���ձ������  *************" << endl;
    cout << "*************  7.��������ĵ�  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;

}

void WorkManage::ExitSystem() {

    cout << "��ӭ�´�ʹ��" << endl;
    exit(0);
}

void WorkManage::Add_Emp() {              //��woreker **
    cout << "���������ӵ���Ա��" << endl;
    int new_num = 0;
    new_num:cin >> new_num;
    if (new_num > 0)
    
    {

        //�����¿ռ��С  
        int NewSize = m_EmpNum + new_num;

        //ָ������
        worker** newSpace = new worker * [NewSize];

        //ת��ԭ�пռ䵽�¿ռ�
        if (m_EmpArray != NULL) {
            for (int i = 0; i < m_EmpNum; i++)
            {
                newSpace[i] = m_EmpArray[i];
            }
        }

        //����������
        for (int i = 0; i < new_num; i++)
        {
            int id;
            string name;
            int dSelect=0;

            cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
            cin >> id;
            cout << "������� " << i + 1 << " ����ְ��������" << endl;
            cin >> name;
            cout << "��ѡ���ְ���ĸ�λ��" << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
            dSelect:cin >> dSelect;
            worker* worker1 = NULL;
            if (dSelect > 3 || dSelect < 1) {
                cout << "δ֪��λ���  ����������" << endl;
                cin.clear();  //���cin״̬��
                //cin.sync();   //�����
                cin.ignore(1024, '\n');  //��� /n֮ǰ��1024���ַ�
                goto dSelect;
            }
            switch (dSelect)
            {
            case 1: //��ͨԱ��
                worker1 = new employee(id, name, 1);
                break;
            case 2: //����
                worker1 = new manager(id, name, 2);
                break;
            case 3:  //�ϰ�
                worker1 = new boss(id, name, 3);
                break;
            default:
                break;

            }
            newSpace[m_EmpNum + i] = worker1;
        }

        //�ͷ�ԭ���ڴ�
        delete[] m_EmpArray;

        //����ָ�����Ӻ���ڴ�
        m_EmpArray = newSpace;

        //����ְ����Ϊ�ձ�־
        m_FileIsEmpty = false;

        //���³�Ա�ĸ���
        m_EmpNum = NewSize;
        cout << "�ɹ����" << new_num << "����ְ����" << endl;

        //�����ļ�
        save();

    }
    else
    {
        cout << "�������" << endl;
        cout << "����������" << endl;
        cin.clear();  //���cin״̬��
        //cin.sync();   //�����
        cin.ignore(1024, '\n');  //��� /n֮ǰ��1024���ַ�
        goto new_num;
    }
    system("pause");
    system("cls");
}

//ÿ�ζ���Ҫ����дһ������
//�����Ż�
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
        //��¼����
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

    int index = 0;  //worker** �������Դ������
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        worker* worker = NULL;
        //���ݲ�ͬ�Ĳ���Id������ͬ����
        if (dId == 1)  // 1��ͨԱ��
        {
            worker = new employee(id, name, dId);
        }
        else if (dId == 2) //2����
        {
            worker = new manager(id, name, dId);
        }
        else //�ܲ�
        {
            worker = new boss(id, name, dId);
        }
        //�����������
        this->m_EmpArray[index] = worker;
        index++;
    }

}

void WorkManage::Show_Emp() {

    if (m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else
    {
        for (int i = 0; i < m_EmpNum; i++)
        {
            //���ö�̬���ýӿ�
            m_EmpArray[i]->show_Info();
        }
    }

    system("pause");
    system("cls");
}

void WorkManage::Del_Emp(){

    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else {
        //��ְ�����ɾ��
        cout << "��������Ҫɾ����ְ���ţ�" << endl;
        int id; cin >> id;
        int index = IsExist(id);
        if (index != -1) {
            for (int i = index; i < this->m_EmpNum - 1; i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;
            save();
            cout << "ɾ���ɹ���" << endl;
        }
        else{
            cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
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
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else {
        cout << "�������޸�ְ���ı�ţ�" << endl;
        int id;
        cin >> id;

        int ret = IsExist(id);
        if (ret != -1)
        {
            delete m_EmpArray[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "�Ѳ鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
            cin >> newId;

            cout << "�������������� " << endl;
            cin >> newName;

            cout << "�������λ�� " << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
        dSelectnew:cin >> dSelect;

            worker* workernew = NULL;
            if (dSelect > 3 || dSelect < 1) {
                cout << "δ֪��λ���  ����������" << endl;
                cin.clear();  //���cin״̬��
                //cin.sync();   //�����
                cin.ignore(1024, '\n');  //��� /n֮ǰ��1024���ַ�
                goto dSelectnew;
            }
            switch (dSelect)
            {
            case 1: //��ͨԱ��
                workernew = new employee(id, newName, dSelect);
                break;
            case 2: //����
                workernew = new manager(id, newName, dSelect);
                break;
            case 3:  //�ϰ�
                workernew = new boss(id, newName, dSelect);
                break;
            default:
                break;

            }

            m_EmpArray[ret] = workernew;  //����ָ��

            cout << "�޸ĳɹ���" << endl;

            //���浽�ļ���
            save();
        }
        else {
            cout << "�޸�ʧ�ܣ����޴���" << endl;
        }
       
    }

    system("pause");
    system("cls");
}

void WorkManage::Find_Emp() {

    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else 
    {
        cout << "��������ҵķ�ʽ��" << endl;
        cout << "1����ְ����Ų���" << endl;
        cout << "2������������" << endl;

        int select = 0;
        cin >> select;

        //��ְ���Ų���
        if (select == 1)
        {
            int id;
            cout << "��������ҵ�ְ����ţ�" << endl;
            cin >> id;

            int ret = IsExist(id);
            if (ret != -1)
            {
                cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
                m_EmpArray[ret]->show_Info();
            }
            else
            {
                cout << "����ʧ�ܣ����޴���" << endl;
            }
        }

        //����������
        else if (select == 2) {

            string name;
            cout << "��������ҵ�������" << endl;
            cin >> name;

            bool flag = false;  //���ҵ��ı�־
            for (int i = 0; i < m_EmpNum; i++)
            {
                if (m_EmpArray[i]->m_Name == name)
                {
                    cout << "���ҳɹ�,ְ�����Ϊ��"
                        << m_EmpArray[i]->m_ID
                        << " �ŵ���Ϣ���£�" << endl;

                    flag = true;

                    this->m_EmpArray[i]->show_Info();
                }
            }

            if (flag == false)
            {
                //���޴���
                cout << "����ʧ�ܣ����޴���" << endl;
            }

        }

        else {

        cout << "����ѡ������" << endl;

        }
    }

    system("pause");
    system("cls");
}

void WorkManage::Sort_Emp() {

    if (this->m_FileIsEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
        system("pause");
        system("cls");
    }
    else {

        cout << "��ѡ������ʽ�� " << endl;
        cout << "1����ְ���Ž�������" << endl;
        cout << "2����ְ���Ž��н���" << endl;

        int select = 0;
        sort:cin >> select;

        /*
        for (int i = 0; i < m_EmpNum - 1; i++)    //ð������
        {
            
            for (int j = 0 ; j < m_EmpNum-1-i; j++) {
                
                if (select == 1)//����
                {
                    if (m_EmpArray[j]->m_ID > m_EmpArray[j+1]->m_ID) {
                        worker* temp = m_EmpArray[j];
                        m_EmpArray[j] = m_EmpArray[j + 1];
                        m_EmpArray[j + 1] = temp;
                    }
                }

                else if (select == 2)//����
                {
                    if (m_EmpArray[j]->m_ID < m_EmpArray[j + 1]->m_ID) {
                        worker* temp = m_EmpArray[j];
                        m_EmpArray[j] = m_EmpArray[j + 1];
                        m_EmpArray[j + 1] = temp;
                    }
                }

                else {
                    cout << "����ֻ������Ŷ������Ϸˣ�˳���" << endl;
                    cout << "��������������ʽ ��" << endl;
                    goto sort;
                }
            }
        }
        */


        //ѡ������
        for (int i = 0; i < m_EmpNum; i++)           
        {
            int minOrMax = i;
            for (int j = i + 1; j < m_EmpNum; j++)
            {
                if (select == 1) //����
                {
                    if (m_EmpArray[minOrMax]->m_ID > m_EmpArray[j]->m_ID)
                    {
                        minOrMax = j;
                    }
                }
                else if (select == 2)  //����
                {
                    if (m_EmpArray[minOrMax]->m_ID < m_EmpArray[j]->m_ID)
                    {
                        minOrMax = j;
                    }
                }
        
                else {
                    cout << "����ֻ������Ŷ������Ϸˣ�˳���" << endl;
                    cout << "��������������ʽ ��" << endl;
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

        cout << "����ɹ�,�������Ϊ��" << endl;
        save();
        Show_Emp();

        //system("pause");
        system("cls");
    }
}

void WorkManage::Clean_File() {

    cout << "ȷ����գ�" << endl;
    cout << "1��ȷ��" << endl;
    cout << "2������" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        //��ģʽ ios::trunc �������ɾ���ļ������´���
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
        cout << "��ճɹ���" << endl;
    }

    system("pause");
    system("cls");
}