#pragma once
#include "iostream"
using namespace std;

template<class Tkey, class Tvalue>
class RBNode
{
public:
	Tvalue	value;
	//int color;
	RBNode<Tkey, Tvalue> *left;
	RBNode<Tkey, Tvalue> *right;
	RBNode<Tkey, Tvalue> *parent;
	RBNode(){}//Default constructor
	RBNode(/*Tkey newKey, */Tvalue newValue)//constructor with parameters
	{
		//key = newKey;
		value = newValue;
		left = NULL;
		right = NULL;
		parent=NULL ;
	}
	//key is not stored
	Tkey getKey(Tkey(*f)(Tvalue value)) const //Tkey (*f)(Tvalue value) function pointer-const
	{
		Tkey key = f(value);
		return key;
	}
	void print(Tkey(*f)(Tvalue value))
	{
		cout << "=======RBNode=======" << endl;
		cout << "key: " << getKey(f) << endl;//For this output in Tkey should be redefined
		cout << "value: " << endl;
		cout << value;//For this output in Tvalue should be redefined
		cout << "==================" << endl;
	}
};

//Overload << through friendly templated function
template<class Tkey, class Tvalue>
ostream &operator<<(ostream &stream, const RBNode<Tkey, Tvalue> ob)
{
	ob.getKey(KeyGenElephantAge);
	stream << "=======RBNode=======" << endl;
	stream << "key: " << ob.getKey(KeyGenElephantAge) << endl;//For this output in Tkey should be redefined
	stream << "value: " << endl;
	stream << ob.value;//For this output in Tvalue should be redefined
	stream << "==================" << endl;
	return stream;
}



