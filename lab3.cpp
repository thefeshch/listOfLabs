struct Leg	//тип Leg
{
    int length; //объект типа int
};

struct Arm	//тип Arm
{
    int power;	//объект типа int
};

struct Person	//тип Person
{
    std::array<Leg, 2> legs;	// 2 объекта типа Leg 
    Arm arms[2];		// 2 объекта типа Arm, arms - константный указатель, тоже объект
};

int main()
{
    Person person;	// объект типа Person
}