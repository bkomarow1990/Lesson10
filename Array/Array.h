#pragma once
#include <iostream>
using namespace std;
class Array
{
public:
	Array(size_t size , int filler);
	Array(size_t size);
	Array()=default;
	Array(const Array& other); // copy ctor
	Array(Array&& other); // move ctor
	Array(const initializer_list<int>& list);
	Array& operator  =(const Array& other);
	Array& operator = (Array&& other);
	Array operator +(const Array& other);
	void operator ++();
	Array operator ++(int);
	int& operator[](int index);
	void print()const; 
	explicit operator int();
	Array operator()(int index,int howMany);
	bool operator ==(const Array& other);
	~Array();
private:
	bool isValidIndex(size_t index)const;
	size_t size = 0;
	int* array = nullptr;
};
inline bool Array::isValidIndex(size_t index)const {
	return index < size;
}
