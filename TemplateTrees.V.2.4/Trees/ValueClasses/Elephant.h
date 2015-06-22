#pragma once
#include "iostream"
using namespace std;
//Custom class Elephant
//Can be used as key and/or value
//For fields should be redefined operations:
//1)  >> (input), not necessary;
// << (output), needed in Node for redefining output, and node output will be used in inOrder, preOrder, postOrder
// != (not equals) - not necessary;
// == (equals), needed in BinarySearchTree, в searchByValue used in searc by key if (key == leaf->key) if elephant will be key 
// = (assignment), used BinarySearchTree, in add
//<(less), >(more), <=,>=, понадобится в BinarySearchTree, в add

class Elephant//not ref !!!
{

private:
	double weight;
	char* color;
	char* name;
	int age;

public:
	Elephant();//ctor
	Elephant(double weight, char* color, char* name, int age);//ctor
    Elephant(const Elephant &ob);
	~Elephant();//destructor;
	void setWeight(double newWeight);
	double getWeight();
	void setAge(int newAge);
	int getAge();
	void setColor(char* newColor);
	char *getColor();
	void setName(char* newName);
	char *getName();
	void Elephant::setElephant(double newWeight, char* newColor, char* newName, int newAge);
	void Elephant::EnterElephantFromConsole();

	friend ostream &operator<<(ostream &stream, const Elephant &ob);
	friend istream &operator>>(istream &stream, Elephant &ob);
	friend bool operator==(const Elephant& left, const Elephant& right);
	friend bool operator!=(const Elephant& left, const Elephant& right);		
	bool operator<(const Elephant &ob);
	bool operator>(const Elephant &ob);
	bool operator<=(const Elephant &ob);
	bool operator>=(const Elephant &ob);
	Elephant& operator=(const Elephant& right);
};



