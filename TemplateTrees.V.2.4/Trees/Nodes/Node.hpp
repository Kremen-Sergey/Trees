#pragma once//file include in assembly only once
#include "iostream"
using namespace std;

//Tree node have Tkey key and TValueValue
//For node should be redegined next operations
//1) << (output) needed in print

template<class Tkey, class Tvalue>
class Node
{
public:
	//Tkey key;
	Tvalue	value;
	Node<Tkey, Tvalue> *left;
	Node<Tkey, Tvalue> *right;
	Node(){}//Default constructor
	Node(/*Tkey newKey, */Tvalue newValue)//Constructor with parameters
	{
		//key = newKey;
		value = newValue;
		left = NULL;
		right = NULL;
	}
	~Node()	{}
	//Key is not stored
	Tkey getKey(Tkey(*f)(Tvalue value)) const //Tkey (*f)(Tvalue value) function pointer-const
	{
		Tkey key = f(value);
		return key;
	}
	void print(Tkey(*f)(Tvalue value))
	{	
		cout << "=======Node=======" << endl;
		cout << "key: " << getKey(f) << endl;	//For this output in Tkey should be redefined
		cout << "value: " << endl;
		cout << value << endl;					//For this output in Tvalue should be redefined
		cout << "==================" << endl;
	}
};

//Overload << through friendly templated function
template<class Tkey, class Tvalue>
ostream &operator<<(ostream &stream, const Node<Tkey, Tvalue> ob)
{
	ob.getKey(KeyGenElephantAge);
	stream << "=======Node=======" << endl;
	stream << "key: " << ob.getKey(KeyGenElephantAge) << endl;//For this output in Tkey should be redefined
	stream << "value: " << endl;
	stream << ob.value;//For this output in Tvalue should be redefined
	stream << "==================" << endl;
	return stream;
}




