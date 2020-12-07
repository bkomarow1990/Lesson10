#include <iostream>
#include <cstring>
#include <tuple>
using namespace std;
#include "Student.h"
// визначаємо стат поле
size_t Student::countStudents = 0;
// порівнює студентів по середній оцінці. 
//повертати буде 0, якщо сер бал однаковий
//повертати менша 0, якщо перший студент має менший  бал
//повертати >0, якщо перший студент має більший  бал
int Student::compareStudentByRate(const Student& one, const Student& two)
{
	double  res = one.getAverageMark() - two.getAverageMark();
	if (res < 0)
		return -1;
	if (res > 0)
		return 1;
	return 0;
}
double Student::getAverageMark() const
{
	double sum = 0;
	for (size_t i = 0; i < qtyMarks; i++)
	{
		sum += marks[i];
	}

	return sum / (qtyMarks > 0 ? qtyMarks : 1);
}
int Student::compareByName(const Student& one, const Student& two)
{
	return strcmp(one.getName(), two.getName());// Andriy Anton < 0
	// Maria Masha < 0        Denis  Dasha > 0 
}
void Student::setName(const char* name)
{
	if (name == nullptr || strlen(name) == 0)
	{
		return;
	}
	if (this->name != nullptr)
	{
		delete[] this->name;
	}
	size_t size = strlen(name) + 1; // + 1   \0
	this->name = new char[size];
	strcpy_s(this->name, size, name);// копія рядка name у рядок this->name, size= розмір буфера нового рядка
}
Student::Student(const char* name, Gender gender) // конструктор
{
	setName(name);
	setGender(gender);
	id = ++countStudents;
	cout << "<<<<< Ctor for " << name << endl;
}
Student::Student(const tuple<const char*, Gender, initializer_list<size_t>>& tup_list)
{
	setName(get<0>(tup_list));
	setGender(get<1>(tup_list));
	for (int i = 0; i < (get<2>(tup_list).size()); i++)
	{
		addMark(*(get<2>(tup_list).begin()+i));
	}
}
Student::Student()
	: Student("Noname")
{}
Student::~Student()
{

	cout << ">>>>>Dtor has worked for " << (name != nullptr ? name : "Empty") << endl;
	if (name != nullptr)
	{
		delete[] name;
		name = nullptr;
		--countStudents;
	}
	if (marks != nullptr)
	{
		delete[] marks;
		marks = nullptr;
	}
}
void Student::addMark(size_t newMark)
{
	// qtyMarks = 2    marks--->[10][11]
	size_t* tmp = new size_t[++qtyMarks]; // qtyMarks = 3    tmp[10][11][.]
	for (size_t i = 0; i < qtyMarks - 1; i++) // 
	{
		tmp[i] = marks[i];
	}
	tmp[qtyMarks - 1] = newMark; // validate mark want  tmp --->[10][11][mark]
	delete[] marks; // видалили масив з старими оцінками
	marks = tmp;// запамятали у вказівнику адресу нової ділянки
}

const  char* Student::getGenderStr() const
{
	static const  char* nameGender[]{ "Male", "Female", "Undefined" };
	return nameGender[(int)gender]; // 0 1 2
}
void Student::print() const
{
	cout << "Id :\t" << id << endl;
	cout << "Name :\t" << name << endl;
	cout << "Gender :\t" << getGenderStr() << endl;
	for (size_t i = 0; i < qtyMarks; i++)
	{
		cout << marks[i] << "\t";
	}
	cout << endl;
	cout << "Average mark : " << this->getAverageMark() << endl;

}
