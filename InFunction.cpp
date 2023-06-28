#include "Functions.h"

/*опис фукцій*/
//...........................................................................FirstMenu Data
void DataEntry(Data* (&d), int& n) 
{
	/*тимчасові змінні*/
	Address   address;
	Items     items;
	Staff     staff;

	cout << "Введіть бажану кількість записів: ";
	cin >> n;

	d = new Data[n];//виділяємо пам'ять для масиву данних

	/**вводим данні*/
	for (int i = 0; i < n; i++) 
	{
		cout << "Уведіть номер цеха та ділянки: ";
		cin >> address.department >> address.part;

		cout << "Уведіть через пробіл клас, вид, час роботи: ";
		cin >> items.classes >> items.type >> items.workTime;

		cout << "Уведіть через пробіл номер бригади, склад бригади, бригадира: ";
		cin >> staff.team >> staff.teamComposition >> staff.foreman;

		d[i].DataEntry(address, items, staff);//додаєм нові данні в єлемент масива об'єкт класу

		cout << "___________________________________________\n";
	}
}

void DataReading(Data* (&d), int& n, string fileName)
{
	ifstream reading(fileName);//створюєм поток для читання файлу

	if (reading)
	{
		/*тимчасові змінні*/
		Address   address;
		Items     items;
		Staff     staff;

		reading >> n;

		d = new Data[n];//виділяємо пам'ять для массиву данних

		/*зчитуєм данні*/
		for (int i = 0; i < n; i++)
		{
			reading >> address.department >> address.part;
			reading >> items.classes >> items.type >> items.workTime;
			reading >> staff.team >> staff.teamComposition >> staff.foreman;

			d[i].DataEntry(address, items, staff);//додаєм нові данні в єлемент масива об'єкт класу
		}

		cout << "Данні успішно зчитані!" << endl;

	}
	else
		cout << "Помилка відкриття файлу!" << endl;

	reading.close();
}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Данні номер" << i + 1 << endl;

		d[i].Print();
		cout << "____________________________________________________\n";
	}
}

void DataChange(Data* d, int n)
{
	/*тимчасові змінні*/
	Address   address;
	Items     items;
	Staff     staff;
	int _n;

	cout << "Введіть номер потрібного запису (від 1 до "<< n <<"):";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n)
	{
		cout << "Уведіть новий номер цеха та ділянки: ";
		cin >> address.department >> address.part;

		cout << "Уведіть нові класи, види, час роботи:  ";
		cin >> items.classes >> items.type >> items.workTime;

		cout << "Уведіть нові бригади, склад бригади, бригадир: ";
		cin >> staff.team >> staff.teamComposition >> staff.foreman;

		d[_n].DataEntry(address, items, staff);//додаєм нові данні в елемент масива об'єкт класу
	}
	else
		cout << "Номер був введенний невірно!" << endl;
}

void Copy(Data* d_n, Data* d_o, int n)
{
	for (int i = 0; i < n; i++)
		d_n[i] = d_o[i];
}

void AddData(Data* (&d), int& n)
{
	/*тимчасові змінні*/
	Address   address;
	Items     items;
	Staff     staff;
	Data* buf = new Data[n];//тимчасовий масив
	int size = n, new_size = ++n;//(було\стало)

	Copy(buf, d, size);//збереження даних у новий масив відповідного розміру

	d = new Data[new_size];//виділення памяті і+1

	Copy(d, buf, size);//перезаписування даних з буфера в масив

	cout << "Уведіть новий номер цеха та ділянки: ";
	cin >> address.department >> address.part;

	cout << "Уведіть нові класи, види, час роботи:  ";
	cin >> items.classes >> items.type >> items.workTime;

	cout << "Уведіть нові бригади, склад бригади, бригадир: ";
	cin >> staff.team >> staff.teamComposition >> staff.foreman;

	d[size].DataEntry(address, items, staff);//додаєм нові данні в елемент масива об'єкт класу 

	cout << "Данні додані" << endl;

	delete[] buf;//очищаєм буфер
}

void DeleteData(Data* (&d), int& n)
{
	int _n;
	Data* buf = new Data[n];

	cout << "Введіть номер потрібного запису (від 1 до " << n << "):";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n)
	{
		Copy(buf, d, n);
		int q = 0;
		n--;


		//виділяємо нову пам'ять
		d = new Data[n];

		for (int i = 0; i <= n; i++)
		{
			if (i != _n)
			{
				d[q] = buf[i];
				q++;
			}
		}
		cout << "Данні номер " << _n << "видаленні!" << endl;
	}
	else
		cout << "Номер був введений невірно!"<< endl;

	delete[]buf;
}

void SortingData(Data* d, int n)
{
	//тимчасові змінні
	Data buf;
	int nomOfSorted = 0;

	//buble sort
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (d[i].GetAddress().department > d[j].GetAddress().department)//умова сортування 
			{
				/*сортування*/
				buf = d[i];
				d[i] = d[j];
				d[j] = buf;

				nomOfSorted++;
			}
		}
	}

	cout << "Данні відсортовані.\nКількість сортувань: " << nomOfSorted << endl;
}

void SaveData(Data* d, int n, string fileName)
{
	ofstream record(fileName);//створити поток для запису файла

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
		cout << "Помилка відкриття файла!" << endl;

	cout << "Данні збережені в файл: " << fileName << endl;

	record.close();
}

//...........................................................................FirstMenu People
void PeopleEntry(People* (&p), int& g)
{
	/*тимчасові змінні*/
	Labs labs;
	Worker worker;

	cout << "Введіть бажану кількість записів: ";
	cin >> g;

	p = new People[g];//виділяємо пам'ять для масиву данних

	/**вводим данні*/
	for (int i = 0; i < g; i++)
	{
		cout << "Уведіть номер цеха та ділянки: ";
		cin >> labs.department >> labs.part;

		cout << "Уведіть через пробіл Ім'я, Прізвище, Ктегорію, Спеціалізацію: ";
		cin >> worker.name >> worker.surName >> worker.category >> worker.speciation;

		p[i].PeopleEntry(labs, worker);//додаєм нові данні в єлемент масива об'єкт класу

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
			// Получить значение workTime из d[i]
			int workTime = d[i].GetItems().workTime;

			// Рассчитать testTime согласно требуемому условию
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
		cout << "Помилка відкриття файла!" << endl;

	cout << "Данні збережені в файл: " << fileName4P << endl;

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

		cout << "Данні успішно зчитані!" << endl;
	}
	else
		cout << "Помилка відкриття файлу!" << endl;

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
			cout << "<-Вид/Категорія->" << endl;
			break;
		}
		else
		{
			cout << "Цех номер " << department << " пустий :(" << endl;
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
		cout<< "Види класу '"<< category << "' у цеху номер " << department << endl;
	}
	else
	{
		cout << "Пусто або перевірте правильність написання!" << endl;
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
	//тимчасові змінні
	Data buf;

	//buble sort
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (d[i].GetItems().type > d[j].GetItems().type)//умова сортування 
			{
				/*сортування*/
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
	//тимчасові змінні
	Data buf;

	//buble sort
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (d[i].GetItems().type > d[j].GetItems().type)//умова сортування 
			{
				/*сортування*/
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
			cout << "У цеху номер " << department << " йде робота над:" << endl;
			break;
		}
		else
		{
			cout << "Цех номер " << department << " пустий :(" << endl;
			break;
		}
	}
	
	
	for (int i = calcType; i < calcType + 4; i++)
	{
		if(((double)hour / (double)d[i].GetItems().workTime) >= 1)
		{
			cout << d[i].GetItems().type << " вироблено " << hour / d[i].GetItems().workTime << " шт." << endl;
		}
		else
		{
			cout << d[i].GetItems().type << " готово на " << ((double)hour / (double)d[i].GetItems().workTime) * 100 << " %" << endl;
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
		cout << "Види класу '" << category << "' у цеху номер " << department << endl;
	}
	else
	{
		cout << "Пусто або перевірте правильність написання!" << endl;
	}

	for (int i = calcType; i < calcType + 4; i++)
	{
		if (((double)hour / (double)d[i].GetItems().workTime) >= 1 && d[i].GetAddress().department == department && d[i].GetItems().classes == category)
		{
			cout << d[i].GetItems().type << " вироблено " << hour / d[i].GetItems().workTime << " шт." << endl;
		}
		else if (d[i].GetAddress().department == department && d[i].GetItems().classes == category)
		{
			cout << d[i].GetItems().type << " готово на " << ((double)hour / (double)d[i].GetItems().workTime) * 100 << " %" << endl;
		}
	}
}

void sortTypesPerHour(Data* d, int n, int hour)
{
	//тимчасові змінні
	Data buf;

	//buble sort
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (d[i].GetItems().type > d[j].GetItems().type)//умова сортування 
			{
				/*сортування*/
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
			cout << d[i].GetItems().type << " вироблено " << hour / d[i].GetItems().workTime << " шт." << endl;
		}

	}
	if (((double)hour / (double)d[n - 1].GetItems().workTime) >= 1 && d[n - 2].GetItems().type != d[n - 1].GetItems().type)
	{
		cout << d[n - 1].GetItems().type << " вироблено " << hour / d[n - 1].GetItems().workTime << " шт." << endl;
	}
	else if (((double)hour / (double)d[n - 1].GetItems().workTime) >= 1 && d[n - 2].GetItems().type == d[n - 1].GetItems().type)
	{
		cout << d[n - 1].GetItems().type << " вироблено " << hour / d[n - 1].GetItems().workTime << " шт." << endl;
	}

}
 
void specSortTypesPerHour(Data* d, int n, string category, int hour)
{
	//тимчасові змінні
	Data buf;

	//buble sort
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (d[i].GetItems().type > d[j].GetItems().type)//умова сортування 
			{
				/*сортування*/
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
			cout << d[i].GetItems().type << " вироблено " << hour / d[i].GetItems().workTime << " шт." << endl;
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

	// Виведення відсортованих даних
	wcout << L"Відсортовані дані за категорією:" << endl;
	for (int i = 0; i < g; i++)
	{
		cout << "Ім'я: " << p[i].GetWorker().name << endl;
		cout << "Прізвище: " << p[i].GetWorker().surName << endl;
		cout << "Категорія: " << p[i].GetWorker().category << endl;
		cout << "Спеціальність: " << p[i].GetWorker().speciation << endl;
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
			cout << "<-Цех/Ділянка/Начальник->" << endl;
			break;
		}
		else
		{
			cout << "Цех номер " << department << " пустий :(" << endl;
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
			// Виконати дії для збігу типу деталі
			// Наприклад, вивести дані про деталі

			cout << "Деталі, які проходять для виробу '" << item << "':" << endl;
			cout << "Цех: " << d[i].GetAddress().department << ", Ділянка: " << d[i].GetAddress().part << endl;
			cout << "Класи деталей: " << d[i].GetItems().classes << endl;
			cout << "Час роботи: " << d[i].GetItems().workTime << " годин" << endl;
			cout << "-------------------------------" << endl;
		}
	}
}
//...........................................................................SecondMenuCase_6
void departmentGroop(People* p, int g, int department)
{
	cout << "Склад бригади на ділянці " << department << ":" << endl;

	for (int i = 0; i < g; i++)
	{
		if (p[i].GetLabs().department == department)
		{
			cout << "Ім'я: " << p[i].GetWorker().name << endl;
			cout << "Прізвище: " << p[i].GetWorker().surName << endl;
			cout << "Категорія: " << p[i].GetWorker().category << endl;
			cout << "Спеціальність: " << p[i].GetWorker().speciation << endl;
			cout << endl;
		}
	}
}

void partGroop(People* p, int g, int part)
{
	cout << "Склад бригад зазначеного цеху " << part << ":" << endl;

	for (int i = 0; i < g; i++)
	{
		if (p[i].GetLabs().part == part)
		{
			cout << "Ім'я: " << p[i].GetWorker().name << endl;
			cout << "Прізвище: " << p[i].GetWorker().surName << endl;
			cout << "Категорія: " << p[i].GetWorker().category << endl;
			cout << "Спеціальність: " << p[i].GetWorker().speciation << endl;
			cout << endl;
		}
	}
}
//...........................................................................SecondMenuCase_7
void areaMasters(People* p, int g, int area)
{
	cout << "Список майстрів на ділянці " << area << ":" << endl;

	for (int i = 0; i < g; i++)
	{
		if (p[i].GetLabs().part == area)
		{
			cout << "Ім'я: " << p[i].GetWorker().name << endl;
			cout << "Прізвище: " << p[i].GetWorker().surName << endl;
			cout << "Категорія: " << p[i].GetWorker().category << endl;
			cout << "Спеціальність: " << p[i].GetWorker().speciation << endl;
			cout << endl;
		}
	}
}

void departmentMasters(People* p, int g, int department)
{
	cout << "Список майстрів у цеху " << department << ":" << endl;

	for (int i = 0; i < g; i++)
	{
		if (p[i].GetLabs().department == department)
		{
			cout << "Ім'я: " << p[i].GetWorker().name << endl;
			cout << "Прізвище: " << p[i].GetWorker().surName << endl;
			cout << "Категорія: " << p[i].GetWorker().category << endl;
			cout << "Спеціальність: " << p[i].GetWorker().speciation << endl;
			cout << endl;
		}
	}
}
//...........................................................................SecondMenuCase_8
void assemblyItemsByCategory(Data* d, int n, int department, string category)
{
	cout << "Перелік виробів категорії " << category << ", які збираються у цеху " << department << ":" << endl;

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
	cout << "Склад бригад, що беруть участь у складанні виробу " << item << ":" << endl;

	for (int i = 0; i < g; i++)
	{
		if (d[i].GetItems().type == item)
		{
			cout << "Бригада: " << p[i].GetLabs().department << " " << p[i].GetLabs().part << endl;
			cout << "Склад бригади: " << p[i].GetWorker().name << " " << p[i].GetWorker().surName << endl;
			cout << "Бригадир: " << d[i].GetStaff().foreman << endl;
			cout << endl;
		}
	}
}
//...........................................................................SecondMenuCase_10
void testLabsByItem(People* p, Data* d, int n, int g, string item)
{
	cout << "Перелік випробувальних лабораторій, що беруть участь у випробуваннях виробу " << item << ":" << endl;

	for (int i = 0; i < n; i++)
	{
		if (d[i].GetItems().type == item && p[i].GetLabs().testTime != 0)
		{
			cout << "Лабораторія: " << p[i].GetLabs().department << " " << p[i].GetLabs().part << endl;
			cout << "Час випробування: " << p[i].GetLabs().testTime << " годин" << endl;
			cout << endl;
		}
	}
}
//...........................................................................SecondMenuCase_11
void productsByLabAndPeriod(People* p, Data* d, int n, int g, int labDepartment, string category, int hour)
{
    cout << "Вироби категорії '" << category << "' у лабораторії цеху " << labDepartment << ":" << endl;

    for (int i = 0; i < n; i++)
    {
        if (d[i].GetAddress().department == labDepartment && d[i].GetItems().classes == category)
        {
            cout << d[i].GetItems().type << endl;
        }
    }

    cout << endl;

    cout << "Всі вироби, що проходили випробування у лабораторії цеху " << labDepartment << " протягом " << hour << " годин:" << endl;

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
	cout << "Список випробувачів, що брали участь у випробуваннях у лабораторії цеху " << labDepartment << " протягом " << period << " годин:" << endl;

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
	cout << "Склад обладнання, що використовувалося при випробуванні у лабораторії цеху " << labDepartment << " протягом " << period << " годин:" << endl;

	for (int i = 0; i < n; i++)
	{
		if (p[i].GetLabs().department == labDepartment && p[i].GetLabs().testTime <= period && p[i].GetLabs().testTime != 0)
		{
			cout << "Обладнання: " << d[i].GetItems().type << endl;
		}
	}
}
//...........................................................................SecondMenuCase_14
void productsByCategoryAndDepartment(People* p, Data* d, int g, int n, string category, int department)
{
	int count = 0;
	cout << "Категорія: " << category << endl;
	cout << "Цех: " << department << endl;

	for (int i = 0; i < n; i++)
	{
		if (d[i].GetAddress().department == department && d[i].GetItems().classes == category)
		{
			count++;
			cout << "- " << d[i].GetItems().type << endl;
		}
	}

	cout << "Загальна кількість виробів: " << count << endl;
}

void productsByCategoryCompanyWide(Data* d, int n, string category)
{
	int count = 0;
	cout << "Категорія: " << category << endl;
	cout << "Підприємство в цілому" << endl;

	for (int i = 0; i < n; i++)
	{
		if (d[i].GetItems().classes == category)
		{
			count++;
			cout << "- " << d[i].GetItems().type << endl;
		}
	}

	cout << "Загальна кількість виробів: " << count << endl;
}

void allProductsCompanyWide(Data* d, int n)
{
	cout << "Підприємство в цілому" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "- " << d[i].GetItems().type << endl;
	}

	cout << "Загальна кількість виробів: " << n << endl;
}
