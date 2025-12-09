#include <iostream>
#include "Bridge.h"

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	University univ1(make_unique<Students>());
	univ1.holidays(); //какое-то кол-во выходных дней у студента
	univ1.promotion(); //студент зачисляется на след курс

	University univ2(make_unique<Teachers>());
	univ2.holidays(); //какое-то кол-во выходных дней у учителя
	univ2.promotion(); //учитель зачисляется на след работу

	system("pause");
}