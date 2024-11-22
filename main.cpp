#include <iostream>

using namespace std;

//Simple example

//int hello(int number){return 2;}
//
//int main()
//{
//	cout<< hello(1) << endl;
//}



//Two files
static int hello(int number){return number + 2;}

int main()
{
	cout<< hello(1) << endl;
}