// Std template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <tuple>
#include <utility>
using namespace std;
template <typename T>
pair<T, T> maxMin(const initializer_list<T> & list) {
	T min = *list.begin();
	for (size_t i = 1; i < list.size(); i++)
	{
		if (*(list.begin()+i)<min)
		{
			min = *(list.begin() + 1);
		}
	}
	T max = *list.begin();
	for (size_t i = 1; i < list.size(); i++)
	{
		if (*(list.begin() + i) > max)
		{
			max = *(list.begin() + i);
		}
	}
	pair<T, T> result(min,max);
	return result;
}
int main()
{
	initializer_list<int> list = { 2,3,5,6,7 };
	cout<<maxMin<int>(list).first<<" "<< maxMin<int>(list).second <<endl;
	/*const int width = 5;
	const int height = 3;
	for (int i = 0; i <= width; i++)
	{
		cout << "-";
	}
	for (int i = 0; i < width; i++)
	{
		for (size_t j = 0; j < height; j++)
		{

		}
		cout << endl;
	}
    cerr<< "test"<< endl;
    std::cout << "Hello World!\n";*/

}

