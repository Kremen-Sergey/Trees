#pragma once
#include "stdafx.h"
#include "ConsoleMenu.h"
#include <iostream>
using namespace std;


ConsoleMenu::ConsoleMenu()
{
}


ConsoleMenu::~ConsoleMenu()
{
}


int ConsoleMenu::getMeinMenuItem()
{
	int v;
	do
	{
		system("cls");
		std::cout << "Input your choice:" << endl;
		cout << "1 - Test for class Elephant" << endl;
		cout << "2 - Test for comparators" << endl;
		cout << "3 - Test for class Node" << endl;
		cout << "4 - Test for class BinaryTree" << endl;
		cout << "5 - Test for class SearhTree" << endl;
		cout << "6 - Test for class AVLTree" << endl;
		cout << "7 - Quit" << endl;
		cout << "Input your choise: " << endl;
		cin >> v;
		while (!cin)
		{
			cout << "Enter only integer!!! Input your choise again: ";
			cin.clear();
			while (cin.get() != '\n') continue;
			cin >> v;
		}
	} while ((v<1) || (v>7));
	return v;
}

int ConsoleMenu::getMenuForElephant()
{
	int v;
	do
	{
		system("cls");
		cout << "Input your choice:" << endl;
		cout << "1 - Constructor without parameters " << endl;
		cout << "2 - Constructor with parameters " << endl;
		cout << "3 - Test overload operator < for names by alphabet" << endl;
		cout << "4 - Test overload operator ==" << endl;
		cout << "5 - Test overload operator >" << endl;
		cout << "6 - Test overload operator <=" << endl;
		cout << "7 - Quit" << endl;
		cout << "Input your choise: " << endl;
		cin >> v;
		while (!cin)
		{
			cout << "Enter only integer!!! Input your choise again: ";
			cin.clear();
			while (cin.get() != '\n') continue;
			cin >> v;
		}
	} while ((v<1) || (v>7));
	return v;
}

int ConsoleMenu::getMenuForComparators()
{
	int v;
	do
	{
		system("cls");
		cout << "Input your choice:" << endl;
		cout << "1 - Test comparator: two Elefants compare for Name" << endl;
		cout << "2 - Test comparator: two integers compare" << endl;
		cout << "3 - Quit" << endl;
		cout << "Input your choise: " << endl;
		cin >> v;
		while (!cin)
		{
			cout << "Enter only integer!!! Input your choise again: ";
			cin.clear();
			while (cin.get() != '\n') continue;
			cin >> v;
		}
	} while ((v<1) || (v>3));
	return v;

}


int ConsoleMenu::getMenuForNode()
{
	int v;
	do
	{
		system("cls");
		cout << "Input your choice:" << endl;
		cout << "1 - Create Node<int,Elephant> " << endl;
		cout << "2 - Node<Elephant,Elephant>" << endl;
		cout << "3 - Node<int,int>" << endl;
		cout << "4 - Quit" << endl;
		cout << "Input your choise: " << endl;
		cin >> v;
		while (!cin)
		{
			cout << "Enter only integer!!! Input your choise again: ";
			cin.clear();
			while (cin.get() != '\n') continue;
			cin >> v;
		}
	} while ((v<1) || (v>4));
	return v;

}


int ConsoleMenu::getMenuForBinaryTree()
{
	int v;
	do
	{
		system("cls");
		cout << "Input your choice:" << endl;
		cout << "1 - Add Elephant to BinaryTree<int, Elephant> " << endl;
		cout << "2 - Pre-order print tree" << endl;
		cout << "3 - In-order print tree" << endl;
		cout << "4 - Post-order print tree" << endl;
		cout << "5 - Searh element by key" << endl;
		cout << "6 - Quit" << endl;
		cout << "Input your choise: " << endl;
		cin >> v;
		while (!cin)
		{
			cout << "Enter only integer!!! Input your choise again: ";
			cin.clear();
			while (cin.get() != '\n') continue;
			cin >> v;
		}
	} while ((v<1) || (v>6));
	return v;

}


int ConsoleMenu::getMenuForSearhTree()
{
	int v;
	do
	{
		system("cls");
		cout << "Input your choice:" << endl;
		cout << "1 - Add Elephant to SearhTree<int, Elephant> " << endl;
		cout << "2 - Pre-order print tree" << endl;
		cout << "3 - In-order print tree" << endl;
		cout << "4 - Post-order print tree" << endl;
		cout << "5 - Searh element by key" << endl;
		cout << "6 - Get as sorted array" << endl;
		cout << "7 - Quit" << endl;
		cout << "Input your choise: " << endl;
		cin >> v;
		while (!cin)
		{
			cout << "Enter only integer!!! Input your choise again: ";
			cin.clear();
			while (cin.get() != '\n') continue;
			cin >> v;
		}
	} while ((v<1) || (v>7));
	return v;

}

int ConsoleMenu::getMenuForAVLTree()
{
	int v;
	do
	{
		system("cls");
		cout << "Input your choice:" << endl;
		cout << "1 - Add Elephant to AVLTree<int, Elephant> " << endl;
		cout << "2 - Pre-order print tree" << endl;
		cout << "3 - In-order print tree" << endl;
		cout << "4 - Post-order print tree" << endl;
		cout << "5 - Searh element by key" << endl;
		cout << "6 - Check if tree is balanced" << endl;
		cout << "7 - Quit" << endl;
		cout << "Input your choise: " << endl;
		cin >> v;
		while (!cin)
		{
			cout << "Enter only integer!!! Input your choise again: ";
			cin.clear();
			while (cin.get() != '\n') continue;
			cin >> v;
		}
	} while ((v<1) || (v>7));
	return v;

}




