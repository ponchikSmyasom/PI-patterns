#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Order {
private:
    vector<string> items_;
    double discount_;          // скидка
    string deliveryAddress_;   // адрес доставки

public:
    void addItem(string item) { items_.push_back(item); }
    void setDiscount(double discount) { discount_ = discount; }
    void setDeliveryAddress(string address) { deliveryAddress_ = address; }
    friend ostream& operator<<(ostream& os, const Order& order);
};

// Интерфейс Строителя
class OrderBuilder {
protected:
    Order order_;

public:
    virtual ~OrderBuilder() {}
    virtual void buildItems() = 0;
    virtual void applyDiscount() = 0;
    virtual void specifyDeliveryAddress() = 0;
    Order getResult() { return order_; }
};

// Переопределённый оператор вывода для отображения содержимого заказа
inline ostream& operator<<(ostream& os, const Order& order) {
    os << "Заказ:\n";
    for (auto& item : order.items_) {
        os << "- " << item << "\n";
    }
    os << "Скидка: " << order.discount_ << "%\nАдрес доставки: " << order.deliveryAddress_ << "\n";
    return os;
}

// Конкретный строитель заказов №1 (для стандартных покупок)
class StandardOrderBuilder : public OrderBuilder {
public:
    void buildItems() override {
        order_.addItem("Смартфон");
        order_.addItem("Ноутбук");
    }

    void applyDiscount() override {
        order_.setDiscount(10.0); // Стандартная скидка 10%
    }

    void specifyDeliveryAddress() override {
        order_.setDeliveryAddress("Ростов-на-Дону, ул. Пушкина, д. Колотушкина");
    }
};

// Конкретный строитель заказов №2 (со специальными условиями)
class SpecialOfferOrderBuilder : public OrderBuilder {
public:
    void buildItems() override {
        order_.addItem("Умные часы");
        order_.addItem("Колонки Bluetooth");
    }

    void applyDiscount() override {
        order_.setDiscount(20.0); // Специальная акция со скидкой 20%
    }

    void specifyDeliveryAddress() override {
        order_.setDeliveryAddress("Санкт-Петербург, Невский проспект, д. 2");
    }
};

// Директор, управляющий созданием заказов
class Director {
private:
    OrderBuilder* builder_;

public:
    void setBuilder(OrderBuilder* builder) { builder_ = builder; }
    Order construct() {
        builder_->buildItems();
        builder_->applyDiscount();
        builder_->specifyDeliveryAddress();
        return builder_->getResult();
    }
};