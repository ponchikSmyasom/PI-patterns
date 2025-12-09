#pragma once

#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Метка на карте
class MapMarker {
private:
    string title_;       // Название метки
    string description_; // Описание метки
    string address_;     // Адрес местоположения

public:
    // Конструктор
    MapMarker(const string& title, const string& desc, const string& addr)
        : title_(title), description_(desc), address_(addr) {
    }

    //Копирующий конструктор

    // Метод для изменения свойств метки
    void update(const string& title, const string& desc, const string& addr) {
        title_ = title;
        description_ = desc;
        address_ = addr;
    }

    // Прототипирование - метод для создания копии текущего объекта
    unique_ptr<MapMarker> clone() const {
        return make_unique<MapMarker>(title_, description_, address_);
    }

    // Вывод информации о метке
    void printInfo() const {
        cout << "Название: " << title_ << "\nОписание: " << description_
            << "\nАдрес: " << address_ << "\n\n";
    }

    ~MapMarker() {}
};