#include <iostream>
#include <time.h>
#include "Array.h"
using namespace std;
int main() {
	initializer_list<int>list = {1,5,7,8,4};
	Array arrfromlist(list);
	arrfromlist.print();
	return 0;
}