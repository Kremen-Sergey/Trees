#pragma once
#include "stdafx.h"
#include "TestForCompareFunction.h"



int compareElephantForName(Elephant x, Elephant y);//!!
int compareForInt(int x, int y);//!!

TestForCompareFunction::TestForCompareFunction()
{
}


TestForCompareFunction::~TestForCompareFunction()
{
}

void TestForCompareFunction::Run()
{
	ConsoleMenu* cMenu = new ConsoleMenu();
	int variant;
	system("cls");
	while (true){
		variant = cMenu->getMenuForComparators();
		cout << endl;
		system("cls");
		Elephant elephant2(98.6, "pink", "Bao", 25);//In switch do not define variables!
		Elephant elephant3(108.6, "green", "Alex", 28);
		switch (variant)
		{

		case 1:{
			cout << "Test comparator: two Elefants compare for Name (functionint compareElephantForName(Elephant x, Elephant y)) " << endl << endl;
			cout << "elephant2" << endl << endl << elephant2 << endl << endl;
			cout << "elephant3" << endl << endl << elephant3 << endl << endl;
			if (compareElephantForName(elephant2, elephant3)<0)
				cout << "elephant2 < elephant3";
			else cout << "elephant2 >= elephant3";
			cout << endl;
			system("pause");
			break;
		}
		case 2:{
			cout << "Test comparator: two iteger compare (functionint int compareForInt(int x, int y)) " << endl << endl;
			if (compareForInt(2, 3)<0)
				cout << "2 < 3";
			else cout << "3 >= 2";
			cout << endl;
			system("pause");
			break;
		}
		
		case 3: {
			return;
		}
		}
	}
	//system("pause");
}


