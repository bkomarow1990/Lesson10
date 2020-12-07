#pragma once
#include <iostream>
#include <string>
using namespace std;
template <typename T1,typename T2>
struct Pair
{
	T1 first;
	T2 second;
	void print()const;

};

template<typename T1, typename T2>
inline void Pair<T1, T2>::print() const
{
	cout << this->first << " " << this->second<< endl;
}
