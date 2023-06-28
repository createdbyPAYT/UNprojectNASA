#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <iomanip>

using namespace std;


/*
:
:         ����:
:         1.  ����� ���� �� ������...........Shop and area number
:         2.  ��������(�����)................Items(detailes)
:         3.  ��������........................Stuff
:
*/

struct Address
{
	int department = 0,//..........���
		part = 0;//................ĳ�����
};

struct Items
{
	string classes,//..............����� �������
		   type;//.................���� �������
	int    workTime = 0;//.........��� ������
};

struct Staff 
{
	string team,//.................�������
		   teamComposition,//......����� �������
		   foreman;//..............��������
};

class Data
{


	//.....................................������� ������� �����
private:
	Address  address;
	Items    items;
	Staff    staff;


	//.....................................������� ������� ����
public:
	//.....................................����'����� ������ �����
	 Data();//���������� �� �������������. ������� ������ ��'��
	 Data(Address address_, Items items_, Staff staff_);//����������� � �����������. ������� ��'��� � �����������.
	~Data();//���������� �� �������������. ������� ��'���
	
	//.....................................�� ����'����� ������
	void Print();
	void DataEntry(Address address_, Items items_, Staff staff_);
	//.....................................���� ������ � �����
	Address   GetAddress() { return address; }; 
	Items     GetItems()   { return items; };
	Staff     GetStaff()   { return staff; };

	//.....................................�������������� ���������
	Data& operator = (Data d_o);
};


/*
:
:         ����:
:         1.  ���������
:         2.  ��������
:
*/



struct Labs
{
	int department = 0,//..........���
		part = 0,//................ĳ�����
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


	//.....................................������� ������� �����
private:
	Labs labs;
	Worker worker;


	//.....................................������� ������� ����
public:
	//.....................................����'����� ������ �����
	People();//���������� �� �������������. ������� ������ ��'��
	People(Labs labs_, Worker worker_);//����������� � �����������. ������� ��'��� � �����������.
	~People();//���������� �� �������������. ������� ��'���

	//.....................................�� ����'����� ������
	void PeoplePrint();
	void PeopleEntry(Labs labs_, Worker worker_);
	//.....................................���� ������ � �����
	Labs       GetLabs() { return labs; };
	Worker     GetWorker() { return worker; };

	//.....................................�������������� ���������
	People& operator = (People p_o);
};