#include <iostream>
#include "Character.h"

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

    

    // —оздаем персонажей использу€ фабрику
    Dialog* hero1 = Application::initialize("warrior");
    hero1->fight();    
    cout << endl;

    Dialog* hero2 = Application::initialize("archer");
    hero2->fight();    
    cout << endl;

    Dialog* hero3 = Application::initialize("wizard");
    hero3->fight();   
    cout << endl;

    delete hero1;
    delete hero2;
    delete hero3;

	system("pause");
}