#include "Functions.h"

/*���� ������*/
//...........................................................................FirstMenu Data
void DataEntry(Data* (&d), int& n) 
{
	/*�������� ����*/
	Address   address;
	Items     items;
	Staff     staff;

	cout << "������ ������ ������� ������: ";
	cin >> n;

	d = new Data[n];//�������� ���'��� ��� ������ ������

	/**������ ����*/
	for (int i = 0; i < n; i++) 
	{
		cout << "������ ����� ���� �� ������: ";
		cin >> address.department >> address.part;

		cout << "������ ����� ����� ����, ���, ��� ������: ";
		cin >> items.classes >> items.type >> items.workTime;

		cout << "������ ����� ����� ����� �������, ����� �������, ���������: ";
		cin >> staff.team >> staff.teamComposition >> staff.foreman;

		d[i].DataEntry(address, items, staff);//����� ��� ���� � ������� ������ ��'��� �����

		cout << "___________________________________________\n";
	}
}

void DataReading(Data* (&d), int& n, string fileName)
{
	ifstream reading(fileName);//�������� ����� ��� ������� �����

	if (reading)
	{
		/*�������� ����*/
		Address   address;
		Items     items;
		Staff     staff;

		reading >> n;

		d = new Data[n];//�������� ���'��� ��� ������� ������

		/*������ ����*/
		for (int i = 0; i < n; i++)
		{
			reading >> address.department >> address.part;
			reading >> items.classes >> items.type >> items.workTime;
			reading >> staff.team >> staff.teamComposition >> staff.foreman;

			d[i].DataEntry(address, items, staff);//����� ��� ���� � ������� ������ ��'��� �����
		}

		cout << "���� ������ ������!" << endl;

	}
	else
		cout << "������� �������� �����!" << endl;

	reading.close();
}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "���� �����" << i + 1 << endl;

		d[i].Print();
		cout << "____________________________________________________\n";
	}
}

void DataChange(Data* d, int n)
{
	/*�������� ����*/
	Address   address;
	Items     items;
	Staff     staff;
	int _n;

	cout << "������ ����� ��������� ������ (�� 1 �� "<< n <<"):";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n)
	{
		cout << "������ ����� ����� ���� �� ������: ";
		cin >> address.department >> address.part;

		cout << "������ ��� �����, ����, ��� ������:  ";
		cin >> items.classes >> items.type >> items.workTime;

		cout << "������ ��� �������, ����� �������, ��������: ";
		cin >> staff.team >> staff.teamComposition >> staff.foreman;

		d[_n].DataEntry(address, items, staff);//����� ��� ���� � ������� ������ ��'��� �����
	}
	else
		cout << "����� ��� ��������� ������!" << endl;
}

void Copy(Data* d_n, Data* d_o, int n)
{
	for (int i = 0; i < n; i++)
		d_n[i] = d_o[i];
}

void AddData(Data* (&d), int& n)
{
	/*�������� ����*/
	Address   address;
	Items     items;
	Staff     staff;
	Data* buf = new Data[n];//���������� �����
	int size = n, new_size = ++n;//(����\�����)

	Copy(buf, d, size);//���������� ����� � ����� ����� ���������� ������

	d = new Data[new_size];//�������� ����� �+1

	Copy(d, buf, size);//��������������� ����� � ������ � �����

	cout << "������ ����� ����� ���� �� ������: ";
	cin >> address.department >> address.part;

	cout << "������ ��� �����, ����, ��� ������:  ";
	cin >> items.classes >> items.type >> items.workTime;

	cout << "������ ��� �������, ����� �������, ��������: ";
	cin >> staff.team >> staff.teamComposition >> staff.foreman;

	d[size].DataEntry(address, items, staff);//����� ��� ���� � ������� ������ ��'��� ����� 

	cout << "���� �����" << endl;

	delete[] buf;//������ �����
}

void DeleteData(Data* (&d), int& n)
{
	int _n;
	Data* buf = new Data[n];

	cout << "������ ����� ��������� ������ (�� 1 �� " << n << "):";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n)
	{
		Copy(buf, d, n);
		int q = 0;
		n--;


		//�������� ���� ���'���
		d = new Data[n];

		for (int i = 0; i <= n; i++)
		{
			if (i != _n)
			{
				d[q] = buf[i];
				q++;
			}
		}
		cout << "���� ����� " << _n << "��������!" << endl;
	}
	else
		cout << "����� ��� �������� ������!"<< endl;

	delete[]buf;
}

void SortingData(Data* d, int n)
{
	//�������� ����
	Data buf;
	int nomOfSorted = 0;

	//buble sort
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (d[i].GetAddress().department > d[j].GetAddress().department)//����� ���������� 
			{
				/*����������*/
				buf = d[i];
				d[i] = d[j];
				d[j] = buf;

				nomOfSorted++;
			}
		}
	}

	cout << "���� ����������.\nʳ������ ���������: " << nomOfSorted << endl;
}

void SaveData(Data* d, int n, string fileName)
{
	ofstream record(fileName);//�������� ����� ��� ������ �����

	if (record)
	{
		record << n << endl;

		for (int i = 0; i < n; i++)
		{
			record << d[i].GetAddress().department << " " << d[i].GetAddress().part << endl;
			record << d[i].GetItems().classes << " " << d[i].GetItems().type << " " << d[i].GetItems().workTime << endl;
			record << d[i].GetStaff().team << " " << d[i].GetStaff().teamComposition << " " << d[i].GetStaff().foreman << endl;

			if (i < n - 1)
				record << endl;
		}
	}
	else
		cout << "������� �������� �����!" << endl;

	cout << "���� �������� � ����: " << fileName << endl;

	record.close();
}

//...........................................................................FirstMenu People
void PeopleEntry(People* (&p), int& g)
{
	/*�������� ����*/
	Labs labs;
	Worker worker;

	cout << "������ ������ ������� ������: ";
	cin >> g;

	p = new People[g];//�������� ���'��� ��� ������ ������

	/**������ ����*/
	for (int i = 0; i < g; i++)
	{
		cout << "������ ����� ���� �� ������: ";
		cin >> labs.department >> labs.part;

		cout << "������ ����� ����� ��'�, �������, �������, ������������: ";
		cin >> worker.name >> worker.surName >> worker.category >> worker.speciation;

		p[i].PeopleEntry(labs, worker);//����� ��� ���� � ������� ������ ��'��� �����

		cout << "___________________________________________\n";
	}
}

void SavePeople(People* p, Data* (&d), int g, string fileName4P)
{
	ofstream record(fileName4P);
	if (record)
	{
		record << g << endl;

		for (int i = 0; i < g; i++)
		{
			// �������� �������� workTime �� d[i]
			int workTime = d[i].GetItems().workTime;

			// ���������� testTime �������� ���������� �������
			int testTime;
			if (workTime % 2 == 0)
				testTime = workTime / 2;
			else
				testTime = 0;

			record << p[i].GetLabs().department << " " << p[i].GetLabs().part << " " << testTime << endl;
			record << p[i].GetWorker().name << " " << p[i].GetWorker().surName << " " << p[i].GetWorker().category << " " << p[i].GetWorker().speciation << endl;

			if (i < g - 1)
				record << endl;
		}
	}
	else
		cout << "������� �������� �����!" << endl;

	cout << "���� �������� � ����: " << fileName4P << endl;

	record.close();
}

void PeopleReading(People* (&p), int& g, string fileName4P)
{
	ifstream reading(fileName4P);

	if (reading)
	{
		reading >> g;
		Labs labs;
		Worker worker;
		p = new People[g];

		for (int i = 0; i < g; i++)
		{

			reading >> labs.department >> labs.part >> labs.testTime;
			reading >> worker.name >> worker.surName >> worker.category >> worker.speciation;

			p[i].PeopleEntry(labs,worker);
		}

		cout << "���� ������ ������!" << endl;
	}
	else
		cout << "������� �������� �����!" << endl;

	reading.close();
}

//...........................................................................SecondMenuCase_1
void Types(Data* d, int n, int department)
{
	int calcType = (4 * department) - 4;

	for (int i = calcType; i < calcType+4; i++)
	{
		if (d[i].GetAddress().department == department)
		{
			cout << "<-���/��������->" << endl;
			break;
		}
		else
		{
			cout << "��� ����� " << department << " ������ :(" << endl;
			break;
		}
	}
	
	for (int i = calcType; i < calcType+4; i++)
	{
		if (d[i].GetAddress().department == department)
		{
			cout << d[i].GetItems().type << " " << d[i].GetItems().classes << endl;
		}
	}
}

void specialTypes(Data* d, int n, int department, string category)
{
	int calcType = (4 * department) - 4,
		count = 0;

	for (int i = calcType; i < calcType + 4; i++)
	{
		if (d[i].GetAddress().department == department && d[i].GetItems().classes == category)
		{
			count++;
		}
	}
	
	if(count != 0)
	{
		cout<< "���� ����� '"<< category << "' � ���� ����� " << department << endl;
	}
	else
	{
		cout << "����� ��� �������� ����������� ���������!" << endl;
	}

	for (int i = calcType; i < calcType + 4; i++)
	{
		if (d[i].GetAddress().department == department && d[i].GetItems().classes == category )
		{
			cout << d[i].GetItems().type << endl;
		}
	}
}

void sortTypes(Data* d, int n)
{
	//�������� ����
	Data buf;

	//buble sort
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (d[i].GetItems().type > d[j].GetItems().type)//����� ���������� 
			{
				/*����������*/
				buf = d[i];
				d[i] = d[j];
				d[j] = buf;
			}
		}
	}
	
	for (int i = 0; i < n-1; i++)
	{
		if (d[i].GetItems().type != d[i+1].GetItems().type)
		{
				cout << d[i].GetItems().type << endl;
		}
	
	}
	if (d[n-2].GetItems().type != d[n-1].GetItems().type)
	{
		cout << d[n-1].GetItems().type << endl;
	}
	else if(d[n - 2].GetItems().type == d[n - 1].GetItems().type)
	{
		cout << d[n - 1].GetItems().type << endl;
	}
	
}

void specSortTypes(Data* d, int n, string category)
{
	//�������� ����
	Data buf;

	//buble sort
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (d[i].GetItems().type > d[j].GetItems().type)//����� ���������� 
			{
				/*����������*/
				buf = d[i];
				d[i] = d[j];
				d[j] = buf;
			}
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (d[i].GetItems().type != d[i + 1].GetItems().type && d[i].GetItems().classes == category)
		{
			cout << d[i].GetItems().type << endl;
		}

	}
}
//...........................................................................SecondMenuCase_2
void TypesPerHour(Data* d, int n, int department, int hour)
{
	int calcType = (4 * department) - 4;
	
	for (int i = calcType; i < calcType + 4; i++)
	{
		if (d[i].GetAddress().department == department)
		{
			cout << "� ���� ����� " << department << " ��� ������ ���:" << endl;
			break;
		}
		else
		{
			cout << "��� ����� " << department << " ������ :(" << endl;
			break;
		}
	}
	
	
	for (int i = calcType; i < calcType + 4; i++)
	{
		if(((double)hour / (double)d[i].GetItems().workTime) >= 1)
		{
			cout << d[i].GetItems().type << " ��������� " << hour / d[i].GetItems().workTime << " ��." << endl;
		}
		else
		{
			cout << d[i].GetItems().type << " ������ �� " << ((double)hour / (double)d[i].GetItems().workTime) * 100 << " %" << endl;
		}	
	}
}

void specialTypesPerHour(Data* d, int n, int department, string category, int hour)
{
	int calcType = (4 * department) - 4,
		count = 0;

	for (int i = calcType; i < calcType + 4; i++)
	{
		if (d[i].GetAddress().department == department && d[i].GetItems().classes == category)
		{
			count++;
		}
	}

	if (count != 0)
	{
		cout << "���� ����� '" << category << "' � ���� ����� " << department << endl;
	}
	else
	{
		cout << "����� ��� �������� ����������� ���������!" << endl;
	}

	for (int i = calcType; i < calcType + 4; i++)
	{
		if (((double)hour / (double)d[i].GetItems().workTime) >= 1 && d[i].GetAddress().department == department && d[i].GetItems().classes == category)
		{
			cout << d[i].GetItems().type << " ��������� " << hour / d[i].GetItems().workTime << " ��." << endl;
		}
		else if (d[i].GetAddress().department == department && d[i].GetItems().classes == category)
		{
			cout << d[i].GetItems().type << " ������ �� " << ((double)hour / (double)d[i].GetItems().workTime) * 100 << " %" << endl;
		}
	}
}

void sortTypesPerHour(Data* d, int n, int hour)
{
	//�������� ����
	Data buf;

	//buble sort
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (d[i].GetItems().type > d[j].GetItems().type)//����� ���������� 
			{
				/*����������*/
				buf = d[i];
				d[i] = d[j];
				d[j] = buf;
			}
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (((double)hour / (double)d[i].GetItems().workTime) >= 1 && d[i].GetItems().type != d[i + 1].GetItems().type)
		{
			cout << d[i].GetItems().type << " ��������� " << hour / d[i].GetItems().workTime << " ��." << endl;
		}

	}
	if (((double)hour / (double)d[n - 1].GetItems().workTime) >= 1 && d[n - 2].GetItems().type != d[n - 1].GetItems().type)
	{
		cout << d[n - 1].GetItems().type << " ��������� " << hour / d[n - 1].GetItems().workTime << " ��." << endl;
	}
	else if (((double)hour / (double)d[n - 1].GetItems().workTime) >= 1 && d[n - 2].GetItems().type == d[n - 1].GetItems().type)
	{
		cout << d[n - 1].GetItems().type << " ��������� " << hour / d[n - 1].GetItems().workTime << " ��." << endl;
	}

}
 
void specSortTypesPerHour(Data* d, int n, string category, int hour)
{
	//�������� ����
	Data buf;

	//buble sort
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (d[i].GetItems().type > d[j].GetItems().type)//����� ���������� 
			{
				/*����������*/
				buf = d[i];
				d[i] = d[j];
				d[j] = buf;
			}
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (((double)hour / (double)d[i].GetItems().workTime) >= 1 && d[i].GetItems().type != d[i + 1].GetItems().type && d[i].GetItems().classes == category)
		{
			cout << d[i].GetItems().type << " ��������� " << hour / d[i].GetItems().workTime << " ��." << endl;
		}

	}
}
//...........................................................................SecondMenuCase_3
void sortPeopleTypes(People* p, int g)
{
	// Bubble sort
	for (int i = 0; i < g - 1; i++)
	{
		for (int j = 0; j < g - i - 1; j++)
		{
			if (p[j].GetWorker().category > p[j + 1].GetWorker().category)
			{
				// Swap the elements
				People temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}

	// ��������� ������������ �����
	wcout << L"³��������� ��� �� ��������:" << endl;
	for (int i = 0; i < g; i++)
	{
		cout << "��'�: " << p[i].GetWorker().name << endl;
		cout << "�������: " << p[i].GetWorker().surName << endl;
		cout << "��������: " << p[i].GetWorker().category << endl;
		cout << "������������: " << p[i].GetWorker().speciation << endl;
		cout << endl;
	}
}
//...........................................................................SecondMenuCase_4
void Area(Data* d, int n, int department)
{
	int calcType = (4 * department) - 4;

	for (int i = calcType; i < calcType + 4; i++)
	{
		if (d[i].GetAddress().department == department)
		{
			cout << "<-���/ĳ�����/���������->" << endl;
			break;
		}
		else
		{
			cout << "��� ����� " << department << " ������ :(" << endl;
			break;
		}
	}

	for (int i = calcType; i < calcType + 4; i++)
	{
		if (d[i].GetAddress().department == department)
		{
			cout << "   " << d[i].GetAddress().department << "   " << d[i].GetAddress().part << "     " << d[i].GetStaff().foreman << endl;
		}
	}
}
//...........................................................................SecondMenuCase_5
void workItem(Data* (&d), int n, string item)
{
	for (int i = 0; i < n; i++)
	{
		if (d[i].GetItems().type == item)
		{
			// �������� 䳿 ��� ���� ���� �����
			// ���������, ������� ��� ��� �����

			cout << "�����, �� ��������� ��� ������ '" << item << "':" << endl;
			cout << "���: " << d[i].GetAddress().department << ", ĳ�����: " << d[i].GetAddress().part << endl;
			cout << "����� �������: " << d[i].GetItems().classes << endl;
			cout << "��� ������: " << d[i].GetItems().workTime << " �����" << endl;
			cout << "-------------------------------" << endl;
		}
	}
}
//...........................................................................SecondMenuCase_6
void departmentGroop(People* p, int g, int department)
{
	cout << "����� ������� �� ������ " << department << ":" << endl;

	for (int i = 0; i < g; i++)
	{
		if (p[i].GetLabs().department == department)
		{
			cout << "��'�: " << p[i].GetWorker().name << endl;
			cout << "�������: " << p[i].GetWorker().surName << endl;
			cout << "��������: " << p[i].GetWorker().category << endl;
			cout << "������������: " << p[i].GetWorker().speciation << endl;
			cout << endl;
		}
	}
}

void partGroop(People* p, int g, int part)
{
	cout << "����� ������ ����������� ���� " << part << ":" << endl;

	for (int i = 0; i < g; i++)
	{
		if (p[i].GetLabs().part == part)
		{
			cout << "��'�: " << p[i].GetWorker().name << endl;
			cout << "�������: " << p[i].GetWorker().surName << endl;
			cout << "��������: " << p[i].GetWorker().category << endl;
			cout << "������������: " << p[i].GetWorker().speciation << endl;
			cout << endl;
		}
	}
}
//...........................................................................SecondMenuCase_7
void areaMasters(People* p, int g, int area)
{
	cout << "������ ������� �� ������ " << area << ":" << endl;

	for (int i = 0; i < g; i++)
	{
		if (p[i].GetLabs().part == area)
		{
			cout << "��'�: " << p[i].GetWorker().name << endl;
			cout << "�������: " << p[i].GetWorker().surName << endl;
			cout << "��������: " << p[i].GetWorker().category << endl;
			cout << "������������: " << p[i].GetWorker().speciation << endl;
			cout << endl;
		}
	}
}

void departmentMasters(People* p, int g, int department)
{
	cout << "������ ������� � ���� " << department << ":" << endl;

	for (int i = 0; i < g; i++)
	{
		if (p[i].GetLabs().department == department)
		{
			cout << "��'�: " << p[i].GetWorker().name << endl;
			cout << "�������: " << p[i].GetWorker().surName << endl;
			cout << "��������: " << p[i].GetWorker().category << endl;
			cout << "������������: " << p[i].GetWorker().speciation << endl;
			cout << endl;
		}
	}
}
//...........................................................................SecondMenuCase_8
void assemblyItemsByCategory(Data* d, int n, int department, string category)
{
	cout << "������ ������ ������� " << category << ", �� ���������� � ���� " << department << ":" << endl;

	for (int i = 0; i < n; i++)
	{
		if (d[i].GetAddress().department == department && d[i].GetItems().classes == category)
		{
			cout << d[i].GetItems().type << endl;
		}
	}
}
//...........................................................................SecondMenuCase_9
void assemblyCrewsByItem(People* p, Data* d, int n, int g, string item)
{
	cout << "����� ������, �� ������ ������ � �������� ������ " << item << ":" << endl;

	for (int i = 0; i < g; i++)
	{
		if (d[i].GetItems().type == item)
		{
			cout << "�������: " << p[i].GetLabs().department << " " << p[i].GetLabs().part << endl;
			cout << "����� �������: " << p[i].GetWorker().name << " " << p[i].GetWorker().surName << endl;
			cout << "��������: " << d[i].GetStaff().foreman << endl;
			cout << endl;
		}
	}
}
//...........................................................................SecondMenuCase_10
void testLabsByItem(People* p, Data* d, int n, int g, string item)
{
	cout << "������ �������������� ����������, �� ������ ������ � ������������� ������ " << item << ":" << endl;

	for (int i = 0; i < n; i++)
	{
		if (d[i].GetItems().type == item && p[i].GetLabs().testTime != 0)
		{
			cout << "����������: " << p[i].GetLabs().department << " " << p[i].GetLabs().part << endl;
			cout << "��� ������������: " << p[i].GetLabs().testTime << " �����" << endl;
			cout << endl;
		}
	}
}
//...........................................................................SecondMenuCase_11
void productsByLabAndPeriod(People* p, Data* d, int n, int g, int labDepartment, string category, int hour)
{
    cout << "������ ������� '" << category << "' � ��������� ���� " << labDepartment << ":" << endl;

    for (int i = 0; i < n; i++)
    {
        if (d[i].GetAddress().department == labDepartment && d[i].GetItems().classes == category)
        {
            cout << d[i].GetItems().type << endl;
        }
    }

    cout << endl;

    cout << "�� ������, �� ��������� ������������ � ��������� ���� " << labDepartment << " �������� " << hour << " �����:" << endl;

    for (int i = 0; i < n; i++)
    {
        if (d[i].GetAddress().department == labDepartment && p[i].GetLabs().testTime <= hour)
        {
            cout << d[i].GetItems().type << endl;
        }
    }
}
//...........................................................................SecondMenuCase_12
void testersByLabAndPeriod(People* p,Data* d, int g,int n, int labDepartment, int period)
{
	cout << "������ ������������, �� ����� ������ � ������������� � ��������� ���� " << labDepartment << " �������� " << period << " �����:" << endl;

	for (int i = 0; i < n; i++)
	{
		if (p[i].GetLabs().department == labDepartment && p[i].GetLabs().testTime <= period && p[i].GetLabs().testTime != 0)
		{
			cout << p[i].GetWorker().name << " " << p[i].GetWorker().surName << endl;
		}
	}
}
//...........................................................................SecondMenuCase_13
void equipmentByLabAndPeriod(People* p, Data* d, int g, int n, int labDepartment, int period)
{
	cout << "����� ����������, �� ����������������� ��� ����������� � ��������� ���� " << labDepartment << " �������� " << period << " �����:" << endl;

	for (int i = 0; i < n; i++)
	{
		if (p[i].GetLabs().department == labDepartment && p[i].GetLabs().testTime <= period && p[i].GetLabs().testTime != 0)
		{
			cout << "����������: " << d[i].GetItems().type << endl;
		}
	}
}
//...........................................................................SecondMenuCase_14
void productsByCategoryAndDepartment(People* p, Data* d, int g, int n, string category, int department)
{
	int count = 0;
	cout << "��������: " << category << endl;
	cout << "���: " << department << endl;

	for (int i = 0; i < n; i++)
	{
		if (d[i].GetAddress().department == department && d[i].GetItems().classes == category)
		{
			count++;
			cout << "- " << d[i].GetItems().type << endl;
		}
	}

	cout << "�������� ������� ������: " << count << endl;
}

void productsByCategoryCompanyWide(Data* d, int n, string category)
{
	int count = 0;
	cout << "��������: " << category << endl;
	cout << "ϳ��������� � ������" << endl;

	for (int i = 0; i < n; i++)
	{
		if (d[i].GetItems().classes == category)
		{
			count++;
			cout << "- " << d[i].GetItems().type << endl;
		}
	}

	cout << "�������� ������� ������: " << count << endl;
}

void allProductsCompanyWide(Data* d, int n)
{
	cout << "ϳ��������� � ������" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "- " << d[i].GetItems().type << endl;
	}

	cout << "�������� ������� ������: " << n << endl;
}
