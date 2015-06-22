// Trees.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "BinaryTree\BinaryTree.h"
#include "BinaryTree\BinaryTree.cpp"
#include "ValueClasses\Elephant.h"
#include "Nodes\Node.hpp"			//if class in .h & .cpp, we need include .h, and .cpp files
#include "SearhTree\SearhTree.h"
#include "SearhTree\SearhTree.cpp"
#include "BalanceTree\AVLTree.h"
#include "BalanceTree\AVLTree.cpp"
#include "UI\ConsoleMenu.h"
#include "UI\TestForElephant.h"
#include "UI\TestForCompareFunction.h"
#include "UI\TestForNode.h"
#include "UI\TestForBinaryTree.h"
#include "UI\TestForSearhTree.h"
#include "UI\TestForAVLTree.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	ConsoleMenu* cm = new ConsoleMenu();
	int variant;
	system("cls");
	while (true){
		variant = cm->getMeinMenuItem();
		cout << endl;
		system("cls");
		switch (variant)
		{

		case 1:{	
			TestForElephant::Run();
			cout << endl;
			system("pause");
			break;
		}
		case 2:{
			TestForCompareFunction::Run();
			cout << endl;
			system("pause");
			break;
		}
		case 3:{
			TestForNode::Run();
			cout << endl;
			system("pause");
			break;
		}
		case 4:{
			TestForBinaryTree::Run();
			cout << endl;
			system("pause");
			break;
		}
		case 5:{
			TestForSearhTree::Run();
			cout << endl;
			system("pause");
			break;
		}
			   case 6:{
			TestForAVLTree::Run();
			cout << endl;
			system("pause");
			break;
		}
		case 7: {
			system("pause");
			exit(0);
		}
		}
	}
	system("pause");
	return 0;
}

