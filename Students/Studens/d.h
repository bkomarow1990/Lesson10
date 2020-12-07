#pragma once
class Student
{
public:
	enum class Gender {MALE, FEMALE, UNDEFINED};
	void setName(const char* name);
	const char* getName() const;
	void addMark(size_t  mark);
	void print() const;
	void setGender(Gender  gender);
	Gender getGender() const;
	const  char *  getGenderStr() const;
	size_t getId() const;
	Student(const char* name, Gender gender = Gender::UNDEFINED); // 2 in one
	Student();
	~Student(); // деструктор
	static size_t getCountOfStudents(); // static method ! не  отримує вказівника this 
	static int compareStudentByRate(const Student& one, const Student& two); //
	double getAverageMark() const;
	static int compareByName(const Student& one, const Student& two);
 private:
	size_t id = 0;
	char* name = nullptr;
	size_t qtyMarks = 0;
	size_t * marks = 0;
	Gender gender = Gender::UNDEFINED;
	static size_t countStudents; // статичне поле, одне для всіх обєктів класів, ТРЕБА його визначати за межами класу на  глобальному рівні(.cpp)
};

inline size_t Student::getCountOfStudents()
{
	return countStudents;
}
inline 	const char* Student::getName() const
{
	return name;
}



inline void Student::setGender(Gender gender)
{
	if (gender >= Gender::MALE && gender <= Gender::UNDEFINED)
	{
		this->gender = gender;
	}
	else
	{
		this->gender = Gender::UNDEFINED;
	}
}

inline Student::Gender Student::getGender() const
{
	return gender;
}
inline size_t Student::getId() const
{
	return id;
}
