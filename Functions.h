#pragma once
#include "DataSet.h"

/*��������� �������*/
//..........................................................�������� ������ ���������
void DataEntry(Data* (&d), int& n);
//..........................................................�������� ������ ��������� ���������
void PeopleEntry(People* (&p), int& n);
//..........................................................���������� ������ � �����
void DataReading(Data* (&d), int& n, string fileName);
//..........................................................��������� � �������
void Print(Data* d, int n);
//..........................................................������ ������
void DataChange(Data* d, int n);
//..........................................................���� ������ ������
void Copy(Data* d_n, Data* d_o, int n);
//..........................................................��������� ������
void AddData(Data* (&d), int& n);
//..........................................................��������� ������
void DeleteData(Data* (&d), int& n);
//..........................................................���������� ������
void SortingData(Data* d, int n);
//..........................................................���������� ������
void SaveData(Data* d, int n, string fileName);
//..........................................................���������� ������ ��� �����
void SavePeople(People* p, Data* (&d), int g, string fileName4P);
//..........................................................���������� ������ � ����� ��� �����
void PeopleReading(People* (&p), int& g, string fileName4P);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//..........................................................���� ���� ������ � ������, ���������� �����
void Types(Data* d, int n, int department);
//..........................................................���� ���� ������ ������ �������, ���������� �����
void specialTypes(Data* d, int n, int department, string category);
//..........................................................���� ���� ������ � ������, �����������
void sortTypes(Data* d, int n);
//..........................................................���� ���� ������ ������ �������, �����������
void specSortTypes(Data* d, int n, string category);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//..........................................................���� ���� ������ � ������, ���������� ����� �� ������ ������ ����
void TypesPerHour(Data* d, int n, int department, int hour);
//..........................................................���� ���� ������ ������ �������, ���������� ����� �� ������ ������ ����
void specialTypesPerHour(Data* d, int n, int department, string category, int hour);
//..........................................................���� ���� ������ � ������, ����������� �� ������ ������ ����
void sortTypesPerHour(Data* d, int n, int hour);
//..........................................................���� ���� ������ ������ �������, ����������� �� ������ ������ ����
void specSortTypesPerHour(Data* d, int n, string category, int hour);
//..........................................................
void sortPeopleTypes(People* p, int g);

void Area(Data*, int n, int department);

void workItem(Data* (&d), int n, string item);

void departmentGroop(People* p, int g, int department);

void partGroop(People* p, int g, int part);

void areaMasters(People* p, int g, int area);

void departmentMasters(People* p, int g, int department);

void assemblyItemsByCategory(Data* d, int n, int department, string category);

void assemblyCrewsByItem(People* p, Data* d, int n, int g, string item);

void testLabsByItem(People* p, Data* d, int n, int g, string item);

void productsByLabAndPeriod(People* p, Data* d, int n, int g, int labDepartment, string category, int hour);

void testersByLabAndPeriod(People* p, Data* d, int g, int n, int labDepartment, int period);

void equipmentByLabAndPeriod(People* p, Data* d, int g, int n, int labDepartment, int period);

void productsByCategoryAndDepartment(People* p, Data* d, int g, int n, string category, int department);

void productsByCategoryCompanyWide(Data* d, int n, string category);

void allProductsCompanyWide(Data* d, int n);