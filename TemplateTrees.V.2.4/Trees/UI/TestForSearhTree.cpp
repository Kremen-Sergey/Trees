#pragma once
#include "stdafx.h"
#include "TestForSearhTree.h"
#include "..\SearhTree\SearhTree.h"
#include "..\SearhTree\SearhTree.cpp"
#include "..\BinaryTree\IBinaryTree.hpp"

void AddElementToTree(IBinaryTree<int, Elephant> *tree);
int compareForInt(int x, int y);
int KeyGenElephantAge(Elephant value);
void PreOrderPrintTree(IBinaryTree<int, Elephant> *tree);
void PostOrderPrintTree(IBinaryTree<int, Elephant> *tree);
void InOrderPrintTree(IBinaryTree<int, Elephant> *tree);
void SearchValueByKeyInTree(IBinaryTree<int, Elephant> *tree);

TestForSearhTree::TestForSearhTree()
{
}


TestForSearhTree::~TestForSearhTree()
{
}

void TestForSearhTree::Run()
{
	ConsoleMenu* cMenu = new ConsoleMenu();
	SearhTree<int, Elephant> searhTree(KeyGenElephantAge, compareForInt);//before while!
	Node<int, Elephant> *x;
	Elephant *el;
	int variant;
	system("cls");
	while (true){
		variant = cMenu->getMenuForSearhTree();
		cout << endl;
		system("cls");
		Elephant elephant;

		double weight;
		char* color = new char[40];
		char* name = new char[40];
		int age;
		vector<Elephant> v;

		switch (variant)
		{

		case 1:{
			AddElementToTree(&searhTree);
			break;
		}
		case 2:{
			PreOrderPrintTree(&searhTree);
			break;
		}
		case 3:{
			InOrderPrintTree(&searhTree);
			break;
		}
		case 4:{
			PostOrderPrintTree(&searhTree);
			break;
		}
		case 5:{
			SearchValueByKeyInTree(&searhTree);
			break;
		}
		case 6:{
			cout << "Get as sorted array" << endl << endl;
			v=searhTree.GetAsSortedArray();
			if (v.size() == 0)
				cout << "Tree is empty" << endl << endl;
			else
				cout << "Tree as sorted array" << endl << endl;

			for (int i = 0; i < v.size(); i++)
			{
				cout << v[i] << endl;
			}
			system("pause");
			break;
		}
		case 7: {
			return;
		}
		}
	}
	//system("pause");
}



