#pragma once
#include "DataSet.h"

/*прототипи функцій*/
//..........................................................введення данних власноруч
void DataEntry(Data* (&d), int& n);
//..........................................................введення данних персоналу власноруч
void PeopleEntry(People* (&p), int& n);
//..........................................................зчитування данних з файлу
void DataReading(Data* (&d), int& n, string fileName);
//..........................................................виведення в консоль
void Print(Data* d, int n);
//..........................................................замінна данних
void DataChange(Data* d, int n);
//..........................................................копія данних масиву
void Copy(Data* d_n, Data* d_o, int n);
//..........................................................додавання данних
void AddData(Data* (&d), int& n);
//..........................................................видалення данних
void DeleteData(Data* (&d), int& n);
//..........................................................сортування данних
void SortingData(Data* d, int n);
//..........................................................збереження данних
void SaveData(Data* d, int n, string fileName);
//..........................................................збереження данних про людей
void SavePeople(People* p, Data* (&d), int g, string fileName4P);
//..........................................................зчитування данних з файлу про людей
void PeopleReading(People* (&p), int& g, string fileName4P);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//..........................................................вивід видів виробів в цілому, зазначеним цехом
void Types(Data* d, int n, int department);
//..........................................................вивід видів виробів окремої категорії, зазначеним цехом
void specialTypes(Data* d, int n, int department, string category);
//..........................................................вивід видів виробів в цілому, підприємством
void sortTypes(Data* d, int n);
//..........................................................вивід видів виробів окремої категорії, підприємством
void specSortTypes(Data* d, int n, string category);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//..........................................................вивід видів виробів в цілому, зазначеним цехом за певний відпізок часу
void TypesPerHour(Data* d, int n, int department, int hour);
//..........................................................вивід видів виробів окремої категорії, зазначеним цехом за певний відпізок часу
void specialTypesPerHour(Data* d, int n, int department, string category, int hour);
//..........................................................вивід видів виробів в цілому, підприємством за певний відпізок часу
void sortTypesPerHour(Data* d, int n, int hour);
//..........................................................вивід видів виробів окремої категорії, підприємством за певний відпізок часу
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