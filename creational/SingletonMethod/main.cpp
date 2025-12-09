#include <iostream>
#include "Singleton.h"

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

    // Получаем единственный экземпляр менеджера уведомлений
    NotificationManager* manager = NotificationManager::getInstance();

    // Отправляем первое уведомление
    manager->sendNotification("Добро пожаловать!");

    // Попытка отправить второе уведомление через тот же самый экземпляр
    manager->sendNotification("Ваш аккаунт успешно активирован.");


	system("pause");
}