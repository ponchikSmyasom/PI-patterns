#pragma once
#include <memory>

using namespace std;

class University
{
	unique_ptr<Person> person_;
public:
	University(unique_ptr<Person> person) : person_(move(person)) {};

	void ToBeOrNotToBe()
	{ 
		if (person_->getStatus())
			person_->expelled();
		else
			person_->enrolled();
	}

	void promotion() { person_->promotionUp(); }
	void holidays() { person_->holidaysInMonth(); }
	//...
};

class Person
{
public:
	virtual bool getStatus() const = 0; //зачислен или отчислен
	virtual void enrolled() = 0; //зачислен
	virtual void expelled() = 0; // отчислен
	virtual bool canPromotion() const = 0; //претендует ли на повышение
	virtual void promotionUp() const = 0;
	virtual int holidaysInMonth() const = 0;
	//...
};

class Students : public Person
{
	bool status_;
	int holidays_;
public:
	Students(bool status, int holidays) : status_(status), holidays_(holidays) {};
	void status(bool stat) { status_ = stat; }
	bool getStatus() const override { return status_; } //зачислен или отчислен
	void enrolled() override { if (!getStatus()) { status(true); } } //зачислен
	void expelled() override { if (getStatus()) { status(false); } }; // отчислен
	bool canPromotion() const override; //претендует ли на повышение
	void promotionUp() const override;
	int holidaysInMonth() const override;
	//... реализация методов Person. И индивидуальная логика класса
};

class Teachers : public Person
{
	bool status_;
	int holidays_;
public:
	Teachers(bool status, int holidays) : status_(status), holidays_(holidays) {};
	bool getStatus() const override; //зачислен или отчислен
	void enrolled() override; //зачислен
	void expelled() override; // отчислен
	bool canPromotion() const override; //претендует ли на повышение
	void promotionUp() const override;
	int holidaysInMonth() const override;
	//... реализация методов Person. И индивидуальная логика класса
};