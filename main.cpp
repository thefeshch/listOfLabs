#include <iostream>
#include "HeapInt.h"

using namespace std;

void swap(HeapInt& a, HeapInt& b) {
    HeapInt temp = std::move(b);
    b = std::move(a);
    a = std::move(temp);
}

void constructors()
{
    HeapInt a{5}; // 8
    HeapInt b{a}; // 9
    HeapInt c{std::move(a)}; // 10
    HeapInt d = b; // 11
    HeapInt e = std::move(b); // 12
    d = std::move(c); // 13
    d = e; // 14
	HeapInt f{1};
    swap(f, d); // 15     1, 5 -> 5, 1
    cout << "f: " << f.asRef() << endl;
    cout << "d: " << d.asRef() << endl;
}

int main()
{
    constructors();
}