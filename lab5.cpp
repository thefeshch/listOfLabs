#include <iostream>

using namespace std;

int countChars(std::string_view line, char ch)
{
	int k = 0;
	for(int i=0; i < line.size(); i++)
	{
		if (line[i] == ch)
			k++;
	}
	return k;
}

void secondWord(std::string_view line)
{
	int i = 0;
	for(; i < line.size(); i++)
	{
		if (line[i] == ' ')
			break;
	}
	
	do
	{
		std::cout << line[i+1];
		i++;
	}
	while(line[i] != ' ' && line[i] !='\0');
}


int main()
{
	//task1
	std::string_view str = "100321001";
	std::string_view str1 = "111111";
	std::string_view str2 = "200rr33003";
	
	int result = countChars(str, '1');
	std::cout<< result << std::endl;
	
	result = countChars(str1, '1');
	std::cout<< result << std::endl;
	
	result = countChars(str2, '1');
	std::cout<< result << std::endl;
	
	//task2
	std::string_view str3 = "Hello World";
	secondWord(str3);
	std::cout << "\nend";
}