#include <string.h>
#include <iostream>

struct TwoInts  
{
	int a;
	int b;
};               // memory: a_ _ _ _  b_ _ _ _

struct StructWithArray
{
	int arr[4];
	int* someNumber;
};				 // memory: arr_ _ _ _  _ _ _ _  _ _ _ _  _ _ _ _  someNumber_ _ _ _  _ _ _ _

int main()
{
	TwoInts i2 = { };   // memory: i2  a_ _ _ _  b_ _ _ _
	i2.a = 5;
	i2.b = 7;			// memory: i2  a_ _ _ 5  b_ _ _ 7
	
	std::cout << i2.a <<std::endl;           // 5
	std::cout << i2.b <<std::endl;			 // 7
	
	StructWithArray s = { };
	s.arr[0] = 10; 			// memory: s  arr _ _ _ 10  _ _ _ 0  _ _ _ 0  _ _ _ 0  someNumber_ _ _ _  _ _ _ 0
	
	StructWithArray s1 = { };
	s1.arr[0] = 15;			// memory: s1  arr _ _ _ 15  _ _ _ 0  _ _ _ 0  _ _ _ 0  someNumber_ _ _ _  _ _ _ 0
	
	StructWithArray* sPointer = &s;     // memory: sPointer _ _ _ _  _a_d_r_e_s_s of "s"
	sPointer->arr[0] =20;				// memory: s  arr_ _ _ 20  _ _ _ 0  _ _ _ 0  _ _ _ 0  someNumber_ _ _ _  _ _ _ 0
	
	std::cout << s.arr[0] <<std::endl;	//20
	s.arr[0] = 25;
	std::cout << s.arr[0] <<std::endl;	//25
	sPointer->arr[0] = 30;
	std::cout << s.arr[0] <<std::endl;	// memory: s  arr_ _ _ 30  _ _ _ 0  _ _ _ 0  _ _ _ 0  someNumber_ _ _ _  _ _ _ 0
	
	sPointer = &s1;						// memory: sPointer _ _ _ _  _a_d_r_e_s_s of "s1"
	sPoiner->arr[0] = 35;				// memory: s1  arr_ _ _ 35  _ _ _ 0  _ _ _ 0  _ _ _ 0  someNumber_ _ _ _  _ _ _ 0
	std::cout << s.arr[0] <<std::endl;	//30
	std::cout << s1.arr[0] <<std::endl;	//35
	
	StructWithArray structArray[2] = {};	// memory: structArray arr_ _ _ 0  _ _ _ 0  _ _ _ 0  _ _ _ 0  someNumber_ _ _ _  _ _ _ 0  arr_ _ _ 0  _ _ _ 0  _ _ _ 0  _ _ _ 0  someNumber_ _ _ _  _ _ _ 0
	structArray[0].arr[3] = 77;				// memory: structArray arr_ _ _ 0  _ _ _ 0  _ _ _ 0  _ _ _ 77  someNumber_ _ _ _  _ _ _ 0  arr_ _ _ 0  _ _ _ 0  _ _ _ 0  _ _ _ 0  someNumber_ _ _ _  _ _ _ 0
	structArray[1].someNumber = &structArray[0].arr[3];	
	// memory: structArray arr_ _ _ 0  _ _ _ 0  _ _ _ 0  _ _ _ 77  someNumber_ _ _ _  _ _ _ 0   arr_ _ _ 0  _ _ _ 0  _ _ _ 0  _ _ _ 0  someNumber_ _ _ _  _a_d_r_e_s_s of "structArray[0].arr[3]" (77)
	
	sPoiner = &s;							// memory: sPointer _ _ _ _  _a_d_r_e_s_s of "s"
	int* pointer = &sPointer->arr[3];		// memory: pointer _ _ _ _  _a_d_r_e_s_s of "s.arr[3]"
	s.arr[3] = 72;							// memory: s  arr_ _ _ 30  _ _ _ 0  _ _ _ 0  _ _ _ 72  someNumber_ _ _ _  _ _ _ 0
	std::cout << *pointer;					//72
	
	StructWithArray memory;							// memory: memory arr_ _ _ 0  _ _ _ 0  _ _ _ 0  _ _ _ 0  someNumber_ _ _ _  _ _ _ 0	
	memset(&memory, 0, sixeof(StructWithArray));
	return 0;
}