#pragma once
#include "stdafx.h"
#include "Elephant.h"
#include "iostream"
#include "string"//for strcpy_s
#include <errno.h>//for strcpy_s
using namespace std;

Elephant::Elephant()
{
	weight = -1;//means object is empty
	color=NULL;
	name = NULL;
	age = -1;//means object is empty
}

Elephant::Elephant(double newWeight, char* newColor, char* newName, int newAge)//ctor
{
	weight = newWeight;
	age = newAge;
	setColor(newColor);
	setName(newName);
}

//The copy constructor is needed to work properly functions that use Elephant as parameter or return type
Elephant::Elephant(const Elephant &ob)
{
	weight = ob.weight;
	age = ob.age;
	setColor(ob.color);
	setName(ob.name);
}

Elephant::~Elephant()//destructor;
{
	if (color)	delete color;
	if(name) delete name;
}

void Elephant::setWeight(double newWeight)
{
	weight = newWeight;
}

double Elephant::getWeight()
{
	return weight;
}

void Elephant::setAge(int newAge)
{
	age = newAge;
}

int Elephant::getAge()
{
	return age;
}

void Elephant::setColor(char* newColor)
{
	color = new char[strlen(newColor) + 1];//allocate memory, the last character from the lines '\ 0', so the length strlen (newColor) + 1
	if (!color)//If the memory was not allocated the color = null
	{
		cout << "Memory for color error!";
		system("pause");
		exit(1);//Emergency exits from the program
	}
	strcpy_s(color, strlen(newColor) + 1, newColor);//contents of the string newColor copied to the new address color
}

char* Elephant::getColor()
{
	return color;
}

void Elephant::setName(char* newName)
{
	name = new char[strlen(newName) + 1];
	if (!name)
	{
		cout << "Memory for name error!";
		system("pause");
		exit(1);
	}
	strcpy_s(name, strlen(newName) + 1, newName);
}

char* Elephant::getName()
{
	return name;
}

//Overloading output operator through friendly function
ostream &operator<<(ostream &stream,const Elephant &ob)
{
	stream << "weight=" << ob.weight << endl;
	if (ob.color != NULL)
	{
		stream << "color=" << ob.color << endl;
	}
	else
	{
		stream << "color=NULL" << endl;
	}
	if (ob.name != NULL)
	{
		stream << "name=" << ob.name << endl;
	}
	else
	{
		stream << "name=NULL" << endl;
	}
	stream << "age=" << ob.age << endl;
	return stream;
}

//Overloading input operator through friendly function
istream &operator>>(istream &stream, Elephant &ob){
	try{
		cout << "Enter weight: ";
		stream >> ob.weight;
		char s[40];
		cout << "Enter color: ";
		stream.ignore(2, '\n');
		stream.getline(s, 39);
		if (ob.color) delete[] ob.color;
		ob.setColor(s);
		cout << "Enter name: ";
		//stream.ignore(2, '\n');
		stream.getline(s, 39);
		if (ob.name) delete[] ob.name;
		ob.setName(s);
		cout << "Enter age: ";
		stream >> ob.age;
		return stream;
	}
	catch (...)
	{
		throw;
	}
}

bool Elephant::operator<(const Elephant &ob)
{
	if ((this->name != NULL) && (ob.name != NULL))
		return  (strcmp(this->name, ob.name) < 0);//names by alphabet
	else
	{
		cout << "Error in compare <";
		system("pause");
		exit(1);
	}
}

bool Elephant::operator>(const Elephant &ob)
{
	if ((this->name != NULL) && (ob.name != NULL))
		return  (strcmp(this->name, ob.name) > 0);//later in alphabet
	else
	{
		cout << "Error in compare <";
		system("pause");
		exit(1);
	}
}

bool Elephant::operator<=(const Elephant &ob)
{
	return (!(*this > ob));
}
bool Elephant::operator>=(const Elephant &ob)
{
	return (!(*this < ob));
}

bool operator==(const Elephant& left, const Elephant& right)
{
	if (&left == &right)
		return true;
	if (left.weight != right.weight)
		return false;
	if (left.age != right.age)
		return false;
	if (strcmp(left.color, right.color) != 0)
		return false;
	if (strcmp(left.name, right.name) != 0)
		return false;
	return true;
}

bool operator!=(const Elephant& left, const Elephant& right)
{
	if (&left == &right)
		return true;
	if (left.weight != right.weight)
		return false;
	if (left.age != right.age)
		return false;
	if (strcmp(left.color, right.color) != 0)
		return false;
	if (strcmp(left.name, right.name) != 0)
		return false;
	return true;
}

Elephant& Elephant::operator=(const Elephant& right)
{
	//check for self assignment
	if (this == &right) {
		return *this;
	}
	//if (this == NULL) return new Elephant(right.weight, right.color, right.name, right.age);
	this->weight = right.weight;
	setColor(right.color);
	//strcpy(this->color, right.color);
	setName(right.name);
	//strcpy(this->name, right.name);
	this->age = right.age;
	return *this;
}

void Elephant::setElephant(double newWeight, char* newColor, char* newName, int newAge)
{
	weight = newWeight;
	age = newAge;
	setColor(newColor);
	setName(newName);
}

void Elephant::EnterElephantFromConsole()
{
	double weightNew;
	char* colorNew = new char[40];
	char* nameNew = new char[40];
	int ageNew;
	cout << "Enter weight: ";
	cin >> weightNew;
	while (!cin)
	{
		cout << "Enter only number!!! Input weight again: ";
		cin.clear();
		while (cin.get() != '\n') continue;
		cin >> weightNew;
	}

	cout << "Enter color: ";
	cin >> colorNew;

	cout << "Enter age: ";
	cin >> ageNew;
	while (!cin)
	{
		cout << "Enter only number!!! Input age again: ";
		cin.clear();
		while (cin.get() != '\n') continue;
		cin >> ageNew;
	}

	cout << "Enter name: ";
	cin >> nameNew;
	setElephant(weightNew, colorNew, nameNew, ageNew);
}



