#pragma once
#include "stdafx.h"
#include "Elephant.h"

//For class write function wich generates key from value. Function is not included in class. Such functions may be many. They can be written later.
//function template: template<class Tkey, class Tvalue> Tkey KeyGen(Tvalue value)
int KeyGenElephantAge(Elephant value){
	int key;
	key = value.getAge();
	return key;
}

char* KeyGenElephantName(Elephant value){
	char* key;
	key = value.getName();
	return key;
}

Elephant KeyGenElephant(Elephant value){
	Elephant key;
	key = value;
	key.setName("key****");
	return key;
}

int KeyGenInt(int value){
	return value;
}

