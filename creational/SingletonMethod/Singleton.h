#pragma once

#include <iostream>
#include <string>
#include <mutex>

using namespace std;

// Менеджер уведомлений (шаблон одиночка)
class NotificationManager {
private:
    // Приватный конструктор для предотвращения создания экземпляров извне
    NotificationManager() {}

    // Статический экземпляр самого себя
    static NotificationManager* instance;

    // Для синхронизации доступа к созданию экземпляра
    static mutex mtx;

public:
    // Метод для получения единственного экземпляра
    static NotificationManager* getInstance() {
        lock_guard<mutex> lock(mtx);
        if (!instance) {
            instance = new NotificationManager();
        }
        return instance;
    }

    // Отправка уведомления
    void sendNotification(const string& message) {
        cout << "Отправлено уведомление: " << message << endl;
    }

    // Запрещаем копирование и перемещение экземпляра
    NotificationManager(const NotificationManager&) = delete;
    NotificationManager& operator=(const NotificationManager&) = delete;
};

// Инициализация статического члена класса
NotificationManager* NotificationManager::instance = nullptr;
mutex NotificationManager::mtx;