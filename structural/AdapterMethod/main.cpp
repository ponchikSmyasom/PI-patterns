#include <iostream>
#include "Adapter.h"

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

    // Используем адаптеры для обоих контроллеров
    XboxAdapter xboxAdapter;
    PlayStationAdapter playStationAdapter;

    // Игра принимает оба адаптера одинаково
    playGame(&xboxAdapter);
    playGame(&playStationAdapter);

	system("pause");
}