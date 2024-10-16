#include <iostream>

struct FruitCounts
{
	int apples;
    int pears;
    int oranges;
}

void main()
{
	FruitCounts fruit;
	
    std::cout << "Apples:";
    std::cin >> fruit.apples;

    std::cout << "Pears:";
    std::cin >> fruit.pears;

    std::cout << "Oranges:";
    std::cin >> fruit.oranges;
	
	bool common;
    {
	bool compApples = fruit.apples > 5;
	bool compPears = fruit.pears < 8;
	bool compOranges = fruit.oranges == fruit.apples * 2;
	common = compApples && compPears && compOranges;
	}
	
	if (common)
	{
		std::cout << "Hello:";
	}
}