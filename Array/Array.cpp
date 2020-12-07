#include "Array.h"
#include <iostream>
using namespace std;
Array::Array(size_t size, int filler)
{
	
	for (size_t i = 0; i < size; i++)
	{
		array[i] = filler;
	}
	this->size = size;
}

Array::Array(size_t size)
	: Array(size,0)
{
	array[0] = 1;
}

Array::~Array()
{
	delete[] array;
}

Array::Array(const Array& other)
{
	*this = other;
}

Array::Array(Array&& other)
{
	this->array = other.array;
	this->size = other.size;
	other.array = nullptr;
	other.size = 0;
}

Array::Array(const initializer_list<int>& list)
{
	this->size = list.size();
	array = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = *(list.begin() + i);
	}
}

Array& Array::operator=(const Array& other)
{
	if (this!=&other)
	{
		if (array!=nullptr)
		{
			delete[]array;
		}
		array = new int[size = other.size];
		for (size_t i = 0; i < size; i++)
		{
			array[i] = other.array[i];
		}
	}
	return *this;
}

Array& Array::operator=(Array&& other)
{
	if (this!=&other)
	{
		if (this->array!=nullptr)
		{
			delete[] array;
			this->array = other.array;
			size = other.size;
			other.array = nullptr;
			other.size = 0;
		}
	}
	else {
		return *this;
	}
}

Array Array::operator+(const Array& other)
{
	Array result(this->size + other.size); // 0*size(count)
	for (size_t i = 0; i < this->size; i++)
	{
		result.array[i] = array[i];
	}
	for (size_t i = 0; i < other.size; i++)
	{
		result.array[i + size] = other.array[i];

	}
	return result;
}

void Array::operator++()
{
	for (size_t i = 0; i < size; i++)
	{
		array[i] +=1;
	}
}

Array Array::operator++(int)
{
	Array old = *this; // copy this object in old
	++* this;
	return old;//return old value
}

int& Array::operator[](int index)
{
	static int error;
	if (isValidIndex(index))
	{
		return array[index];
	}
	cerr << "Error index"<<index<<endl; // cerr = stream for errors
	return error;
}

void Array::print() const
{
	cout << "Size: " << size << endl;
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

Array::operator int()
{
	int summ = 0;
	for (int i = 0; i < size; i++)
	{
		summ += array[i];
	}
	return summ;
}

Array Array::operator()(int index,int howMany)
{
	if (!isValidIndex(index))
	{
		return Array();
	}
	if (index+howMany>=(int)size)
	{
		howMany = size - index;
	}
	Array result(howMany);
	

	int j = 0;
	//result.array = new int[howMany - index];
	for (int i = index; i <= howMany; i++)
	{
		result.array[j] = this->array[i];
		j++;
	}
	return result;
	// 23 42 12 444
}

bool Array::operator==(const Array& other)
{
	if (size!=other.size)
	{
		return false;
	}
		for (size_t i = 0; i < size; i++)
		{
			if (array[i]=!other.array[i])
			{
				return false;
			}
		
		}
		return true;
}
