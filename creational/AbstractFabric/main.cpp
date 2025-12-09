#include <iostream>
#include "Museum.h"


int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	MinimalismFactory minFac;
	Application app(make_unique<MinimalismFactory>());
	app.look();

	system("pause");
}