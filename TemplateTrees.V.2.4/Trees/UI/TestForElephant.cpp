#pragma once
#include "stdafx.h"
#include "TestForElephant.h"
#include "ConsoleMenu.h"
#include <iostream>
#include "..\ValueClasses\Elephant.h"
using namespace std;		//for cin and cout

TestForElephant::TestForElephant()
{
}


TestForElephant::~TestForElephant()
{
}
void TestForElephant::Run()
{
	ConsoleMenu* cMenu = new ConsoleMenu();
	int variant;
	system("cls");
	while (true){
		variant = cMenu->getMenuForElephant();
		cout << endl;
		system("cls");
		Elephant elephant1;  //In switch do not define variables!
		Elephant elephant2(98.6, "pink", "Bao", 25);
		Elephant elephant3(108.6, "green", "Alex", 28);
		Elephant elephant33(108.6, "green", "Alex", 28);
		Elephant elephant4(115, "blue", "Zorg", 28);
		switch (variant)
		{

		case 1:{	
			cout << "Constructor without parameters" << endl << endl << "elephant1" << endl << endl << elephant1 << endl;
			system("pause");
			break;
		}
		case 2:{
			cout << "Constructor with parameters Elephant elephant2(98.6, \"pink\", \"Bao\", 25);" << endl << endl << "elephant2" << endl << endl << elephant2 << endl;
			system("pause");
			break;
		}

		case 3:{
			cout << "Test overload operator < for names by alphabet" << endl << endl;
			cout << "elephant2" << endl << endl << elephant2 << endl << endl;
			cout << "elephant3" << endl << endl << elephant3 << endl << endl;
			if (elephant2 < elephant3)
				cout << "elephant2 < elephant3";
			else cout << "elephant2 >= elephant3";
			cout << endl;
			system("pause");
			break;
		}
		case 4:{
			cout << "Test overload operator == " << endl << endl;
			cout << "elephant2" << endl << endl << elephant2 << endl << endl;
			cout << "elephant3" << endl << endl << elephant3 << endl << endl;
			cout << "elephant33" << endl << endl << elephant33 << endl << endl;
			if (elephant2 == elephant3)
				cout << "elephant2 == elephant3" << endl << endl;
			else cout << "elephant2 != elephant3" << endl << endl;

			if (elephant2 == elephant2)
				cout << "elephant2 == elephant2" << endl << endl;
			else cout << "elephant2 != elephant2" << endl << endl;

			if (elephant3 == elephant33)
				cout << "elephant3 == elephant33" << endl << endl;
			else cout << "elephant3 != elephant33" << endl << endl;

			cout << endl;
			system("pause");
			break;
		}
		case 5:{
			cout << "Test overload operator > for names by alphabet" << endl << endl;
			cout << "elephant2" << endl << endl << elephant2 << endl << endl;
			cout << "elephant4" << endl << endl << elephant4 << endl << endl;
			if (elephant4 > elephant2)
				cout << "elephant4 > elephant2" << endl << endl;
			else cout << "elephant4 <= elephant2" << endl << endl;
			cout << endl;
			system("pause");
			break;
		}
		case 6:{
			cout << "Test overload operator <= for names by alphabet" << endl << endl;
			cout << "elephant2" << endl << endl << elephant2 << endl << endl;
			cout << "elephant4" << endl << endl << elephant4 << endl << endl;
			if (elephant2 <= elephant4)
				cout << "elephant2 <= elephant4" << endl << endl;
			else cout << "elephant2 > elephant4" << endl << endl;
			cout << endl;
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

