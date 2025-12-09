#include <iostream>
#include "Prototype.h"

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

    // Создаём прототип метки
    unique_ptr<MapMarker> prototype = make_unique<MapMarker>("ЮФУ", "Мехмат", "ул. Мильчакова 8А");

    // Клонирование первой метки
    unique_ptr<MapMarker> marker1 = prototype->clone();
    marker1->update("Парковка", "Бесплатная парковка", "ул.Пушкина дом Колотушкина");
    marker1->printInfo();

    // Клонирование второй метки
    unique_ptr<MapMarker> marker2 = prototype->clone();
    marker2->update("Магазин", "Продуктовый Магазин Тройка", "2-я Краснодарская 129/2");
    marker2->printInfo();

	system("pause");
}