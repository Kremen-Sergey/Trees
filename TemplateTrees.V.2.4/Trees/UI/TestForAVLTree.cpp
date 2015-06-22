#pragma once
#include "stdafx.h"
#include <math.h>
#include "TestForAVLTree.h"
#include "..\BalanceTree\AVLTree.h"
#include "..\BalanceTree\AVLTree.cpp"
#include "..\BinaryTree\IBinaryTree.hpp"

int compareForInt(int x, int y);
int KeyGenElephantAge(Elephant value);
void AddElementToTree(IBinaryTree<int, Elephant> *tree);
void PreOrderPrintTree(IBinaryTree<int, Elephant> *tree);
void PostOrderPrintTree(IBinaryTree<int, Elephant> *tree);
void InOrderPrintTree(IBinaryTree<int, Elephant> *tree);
void SearchValueByKeyInTree(IBinaryTree<int, Elephant> *tree);

TestForAVLTree::TestForAVLTree()
{
}


TestForAVLTree::~TestForAVLTree()
{
}

bool IsBalancedCheck(int elementsNumber)
{
	AVLTree<int, Elephant> avlTreeForBalanceCheck(KeyGenElephantAge, compareForInt);
	int expectedHeight=-1;
	int actualHeight=-1;
	bool result;

	//fill AVLTree with elementsNumber of random elephants
	for (int i = 0; i < elementsNumber; i++)
	{
		Elephant *el = new Elephant(rand(), "SomeColor", "SomeName", rand());
		avlTreeForBalanceCheck.Add(*el);
	}

	const int arrayLength = 20;
	int numberOfElementsArray[arrayLength];
	int heightArray[arrayLength];
	//numberOfElementsArray[i]=2^0+2^1+2^2+...+2^i
	for (int i = 0; i < arrayLength; i++)
	{
		int sum=0;
		sum = sum + pow(2, i+1)-1;
	/*	for (int j = 0; j <= i; j++)
		{
			sum = sum + pow(2, j);
		}*/
		numberOfElementsArray[i] = sum;
	}
	//if number of elements in tree is > numberOfElementsArray[i] and <= numberOfElementsArray[i+1] height of tree is i+2 
	int expectedTreeHeight = 0;
	for (int i = 0; i < arrayLength-1; i++)
	{
		if ((elementsNumber>numberOfElementsArray[i])&&(elementsNumber<=numberOfElementsArray[i+1]))
		{
			cout << "i=" << i << endl;
			expectedHeight = i + 2;
		}
	}
	actualHeight = avlTreeForBalanceCheck.Height();
	result = (abs(actualHeight - expectedHeight)<=2) ? true : false;
	cout << endl << "expected height: " << expectedHeight << endl << endl << "actual height: " << actualHeight << endl << "result=" << result << endl << endl;
	return result;
}


void TestForAVLTree::Run()
{
	ConsoleMenu* cMenu = new ConsoleMenu();
	AVLTree<int, Elephant> avlTree(KeyGenElephantAge, compareForInt);//before while!
	Node<int, Elephant> *x;
	int variant;
	system("cls");
	while (true){
		variant = cMenu->getMenuForAVLTree();
		cout << endl;
		system("cls");
		Elephant elephant;

		double weight;
		char* color = new char[40];
		char* name = new char[40];
		int age;
		int elementsNumber;//!!!

		switch (variant)
		{

		case 1:{
			AddElementToTree(&avlTree);
			break;
		}
		case 2:{
			PreOrderPrintTree(&avlTree);
			break;
		}
		case 3:{
			InOrderPrintTree(&avlTree);
			break;
		}
		case 4:{
			PostOrderPrintTree(&avlTree);
			break;
		}
		case 5:{SearchValueByKeyInTree(&avlTree);
			break;
		}
		case 6:{
			cout << "Check if tree is balanced" << endl << endl;
			cout << "Enter number of elements: ";
			cin >> elementsNumber;
			if (IsBalancedCheck(elementsNumber))
			{
				cout << "Tree is balanced" << endl << endl;
			}
			else
			{
				cout << "Tree is not balanced" << endl << endl;
			}
			
			system("pause");
			break;
		}
		case 7: {
			return;
		}
		}
	}
}



