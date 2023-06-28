#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <iomanip>

using namespace std;


/*
:
:         Данні:
:         1.  Номер цеха та ділянки...........Shop and area number
:         2.  Предмети(деталі)................Items(detailes)
:         3.  Персонал........................Stuff
:
*/

struct Address
{
	int department = 0,//..........Цех
		part = 0;//................Ділянка
};

struct Items
{
	string classes,//..............Класи деталей
		   type;//.................Види деталей
	int    workTime = 0;//.........Час роботи
};

struct Staff 
{
	string team,//.................Бригада
		   teamComposition,//......Склад бригади
		   foreman;//..............Бригадир
};

class Data
{


	//.....................................закрита частина класу
private:
	Address  address;
	Items    items;
	Staff    staff;


	//.....................................відкрита частина касу
public:
	//.....................................обов'язкові методи класу
	 Data();//Констуктор за замовчуванням. Створює пустий об'єт
	 Data(Address address_, Items items_, Staff staff_);//Конструктор з параметрами. Створюе об'єкт з параметрами.
	~Data();//Деструктор за замовчуванням. Видаляє об'єкт
	
	//.....................................не обов'язкові методи
	void Print();
	void DataEntry(Address address_, Items items_, Staff staff_);
	//.....................................вивід данних з класу
	Address   GetAddress() { return address; }; 
	Items     GetItems()   { return items; };
	Staff     GetStaff()   { return staff; };

	//.....................................перевантаження оператора
	Data& operator = (Data d_o);
};


/*
:
:         Данні:
:         1.  Лабораторії
:         2.  Робітники
:
*/



struct Labs
{
	int department = 0,//..........Цех
		part = 0,//................Ділянка
		testTime = 0;
};

struct Worker
{
	string name,
		   surName,
		   category,
		   speciation;
	bool   laboratory;
};

class People
{


	//.....................................закрита частина класу
private:
	Labs labs;
	Worker worker;


	//.....................................відкрита частина касу
public:
	//.....................................обов'язкові методи класу
	People();//Констуктор за замовчуванням. Створює пустий об'єт
	People(Labs labs_, Worker worker_);//Конструктор з параметрами. Створюе об'єкт з параметрами.
	~People();//Деструктор за замовчуванням. Видаляє об'єкт

	//.....................................не обов'язкові методи
	void PeoplePrint();
	void PeopleEntry(Labs labs_, Worker worker_);
	//.....................................вивід данних з класу
	Labs       GetLabs() { return labs; };
	Worker     GetWorker() { return worker; };

	//.....................................перевантаження оператора
	People& operator = (People p_o);
};