#pragma once
#include "stdafx.h"
#include "..\BinaryTree\IBinaryTree.hpp"
#include "..\ValueClasses\Elephant.h"
#include <iostream>
using namespace std;

void AddElementToTree(IBinaryTree<int, Elephant> *tree)
{
	Elephant elephant;
	cout << "Add Elephant to BinaryTree<int, Elephant> " << endl << endl;
	elephant.EnterElephantFromConsole();
	tree->Add(elephant);
	cout << endl << endl;
	system("pause");
}

void PreOrderPrintTree(IBinaryTree<int, Elephant> *tree)
{
	cout << "Pre-order print tree" << endl << endl;
	tree->PreOrder();
	system("pause");
}

void PostOrderPrintTree(IBinaryTree<int, Elephant> *tree)
{
	cout << "Post-order print tree" << endl << endl;
	tree->PostOrder();
	system("pause");
}

void InOrderPrintTree(IBinaryTree<int, Elephant> *tree)
{
	cout << "In-order print tree" << endl << endl;
	tree->InOrder();
	system("pause");
}

void SearchValueByKeyInTree(IBinaryTree<int, Elephant> *tree)
{
	Elephant *el;
	int age;
	cout << "Enter age as key: ";
	cin >> age;
	while (!cin)
	{
		cout << "Enter only integer!!! Input age as key again: ";
		cin.clear();
		while (cin.get() != '\n') continue;
		cin >> age;
	}
	el = tree->SearchValueByKey(age);
	if (el != NULL)
	{
		cout << "Find:" << endl;
		cout << *el << endl;
		cout << endl << endl;
	}
	else cout << "No such element!" << endl;
	system("pause");
}