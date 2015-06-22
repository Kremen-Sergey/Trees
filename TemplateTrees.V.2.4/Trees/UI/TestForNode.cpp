#pragma once
#include "stdafx.h"
#include "TestForNode.h"

//#include "header.h"


int KeyGenElephantAge(Elephant value);
char* KeyGenElephantName(Elephant value);
Elephant KeyGenElephant(Elephant value);
int KeyGenInt(int value);

TestForNode::TestForNode()
{
}


TestForNode::~TestForNode()
{
}

void TestForNode::Run()
{
	ConsoleMenu* cMenu = new ConsoleMenu();
	int variant;
	system("cls");
	while (true){
		variant = cMenu->getMenuForNode();
		cout << endl;
		system("cls");
		Elephant elephant2(98.6, "pink", "Bao", 25);//In switch do not define variables!
		Elephant elephant3(108.6, "green", "Alex", 28);
		Node<int, Elephant>* node1;
		Node<Elephant, Elephant>* node2;
		Node<int, int>* node3;
		switch (variant)
		{

		case 1:{
			cout << "test for Node: create Node<int,Elephant>" << endl << endl;
			node1 = new Node<int, Elephant>(elephant3);
			node1->print(KeyGenElephantAge);
			cout << endl << endl;
			system("pause");
			break;
		}
		case 2:{
			cout << "test for Node: create Node<Elephant,Elephant>" << endl << endl;
			node2 = new Node<Elephant, Elephant>(elephant3);
			node2->print(KeyGenElephant);
			cout << endl << endl;
			system("pause");
			break;
		}
		case 3:{
			cout << "test for Node: create Node<int,int>" << endl << endl;
			node3 = new Node<int, int>(10);
			node3->print(KeyGenInt);
			cout << endl << endl;
			system("pause");
			break;
		}
		case 4: {
			return;
		}
		}
	}
	//system("pause");
}



