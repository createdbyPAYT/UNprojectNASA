#include "DataSet.h"

Data::Data()
{
	address.department = 0;
	address.part = 0;

	items.classes = "";
	items.type = "";
	items.workTime = 0;

	staff.team = "";
	staff.teamComposition = "";
	staff.foreman = "";
}

Data::Data(Address address_, Items items_, Staff staff_)
{
	address.department = address_.department;
	address.part = address_.part;

	items.classes = items_.classes;
	items.type = items_.type;
	items.workTime = items_.workTime;

	staff.team = staff_.team;
	staff.teamComposition = staff_.teamComposition;
	staff.foreman = staff_.foreman;
}

Data::~Data()
{
}

void Data::Print() 
{
	cout << "Розсташування: " << address.department << " " << address.part << endl;
	cout << "Класи, види, час роботи: " << items.classes << " " << items.type << " " << items.workTime << endl;
	cout << "Бригади, склад бригади, бригадир: " << staff.team << " " << staff.teamComposition << " " << staff.foreman << endl;
}

void Data::DataEntry(Address address_, Items items_, Staff staff_)
{
	address.department = address_.department;
	address.part = address_.part;

	items.classes = items_.classes;
	items.type = items_.type;
	items.workTime = items_.workTime;

	staff.team = staff_.team;
	staff.teamComposition = staff_.teamComposition;
	staff.foreman = staff_.foreman;
}

Data& Data::operator=(Data d_o)
{
	this->address.department = d_o.address.department;
	this->address.part = d_o.address.part;

	this->items.classes = d_o.items.classes;
	this->items.type = d_o.items.type;
	this->items.workTime = d_o.items.workTime;

	this->staff.team = d_o.staff.team;
	this->staff.teamComposition = d_o.staff.teamComposition;
	this->staff.foreman = d_o.staff.foreman;

	return *this;
}

//.................................................................People

People::People()
{
	labs.department = 0;
	labs.part = 0;
	labs.testTime = 0;

	worker.name = "";
	worker.surName = "";
	worker.category = "";
	worker.speciation = "";
	worker.laboratory = 0;
}

People::People(Labs labs_, Worker worker_)
{
	labs.department = labs_.department;
	labs.part = labs_.part;
	labs.testTime = labs_.testTime;

	worker.name = worker_.name;
	worker.surName = worker_.surName;
	worker.category = worker_.category;
	worker.speciation = worker_.speciation;
	worker.laboratory = worker_.laboratory;
}

People::~People()
{
}

void People::PeoplePrint()
{
	cout << "Розсташування, час тестування: " << labs.department << " " << labs.part << " " << labs.testTime << endl;
	cout << "Ім'я, Фамилия, Каатегорія, Специфікація: " << worker.name << " " << worker.surName << " " << worker.category << " " << worker.speciation << endl;
	
}

void People::PeopleEntry(Labs labs_, Worker worker_)
{
	labs.department = labs_.department;
	labs.part = labs_.part;
	labs.testTime = labs_.testTime;

	worker.name = worker_.name;
	worker.surName = worker_.surName;
	worker.category = worker_.category;
	worker.speciation = worker_.speciation;
	worker.laboratory = worker_.laboratory;
}

People& People::operator=(People p_o)
{
	this->labs.department = p_o.labs.department;
	this->labs.part = p_o.labs.part;
	this->labs.testTime = p_o.labs.testTime;

	this->worker.name = p_o.worker.name;
	this->worker.surName = p_o.worker.surName;
	this->worker.category = p_o.worker.category;
	this->worker.speciation = p_o.worker.speciation;
	this->worker.laboratory = p_o.worker.laboratory;

	return *this;
}
