#pragma once
#include "stdafx.h"
#include "TestForBinaryTree.h"
#include "..\BinaryTree\BinaryTree.h"
#include "..\BinaryTree\BinaryTree.cpp"
#include "..\BinaryTree\IBinaryTree.hpp"
#include "..\ValueClasses\KeyGenFunction.hpp"
#include "..\ValueClasses\CompareFunctions.hpp"
#include "TestFunctions.hpp"


void AddElementToTree(IBinaryTree<int, Elephant> *tree);
int compareForInt(int x, int y);
int KeyGenElephantAge(Elephant value);
void PreOrderPrintTree(IBinaryTree<int, Elephant> *tree);
void PostOrderPrintTree(IBinaryTree<int, Elephant> *tree);
void InOrderPrintTree(IBinaryTree<int, Elephant> *tree);
void SearchValueByKeyInTree(IBinaryTree<int, Elephant> *tree);


TestForBinaryTree::TestForBinaryTree()
{
}


TestForBinaryTree::~TestForBinaryTree()
{
}

void TestForBinaryTree::Run()
{
	ConsoleMenu* cMenu = new ConsoleMenu();
	
	BinaryTree<int, Elephant> binaryTree(KeyGenElephantAge);//before while!
	int variant;
	system("cls");
	while (true){
		variant = cMenu->getMenuForBinaryTree();
		cout << endl;
		system("cls");
		Elephant elephant;
		Elephant *el;
		int age;

		switch (variant)
		{

		case 1:{
			AddElementToTree(&binaryTree);
			break;
		}
		case 2:{
			PreOrderPrintTree(&binaryTree);
			break;
		}
		case 3:{
			InOrderPrintTree(&binaryTree);
			break;
		}
		case 4:{
			PostOrderPrintTree(&binaryTree);
			break;
		}
		case 5:{
			SearchValueByKeyInTree(&binaryTree);
			break;
		}
		case 6: {
			return;
		}
		}
	}
	//system("pause");
}



