#include <iostream>
#include "Builder.h"

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

    Director director;

    // Создание стандартного заказа
    StandardOrderBuilder standardBuilder;
    director.setBuilder(&standardBuilder);
    auto standardOrder = director.construct();
    cout << standardOrder << endl;

    // Создание специального заказа
    SpecialOfferOrderBuilder specialBuilder;
    director.setBuilder(&specialBuilder);
    auto specialOrder = director.construct();
    cout << specialOrder << endl;

	system("pause");
}