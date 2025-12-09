#pragma once

#include <iostream>
#include <string>
using namespace std;

// Базовый класс персонажа
class Character {
public:
    virtual void attack() = 0;
    virtual void dodge() = 0;
    virtual void deceive() = 0;
};

// Конкретные классы персонажей

// Мечник
class Warrior : public Character {
public:
    void attack() override { cout << "Warrior attacks with a sword." << endl; }
    void dodge() override { cout << "Warrior dodges using shield." << endl; }
    void deceive() override { cout << "Warrior uses feigned retreat to confuse the enemy." << endl; }
};

// Лучник
class Archer : public Character {
public:
    void attack() override { cout << "Archer shoots an arrow from afar." << endl; }
    void dodge() override { cout << "Archer jumps aside quickly." << endl; }
    void deceive() override { cout << "Archer creates decoy targets to mislead enemies." << endl; }
};

// Волшебник
class Wizard : public Character {
public:
    void attack() override { cout << "Wizard casts fireball spell." << endl; }
    void dodge() override { cout << "Wizard teleports away from danger." << endl; }
    void deceive() override { cout << "Wizard creates illusions to trick opponents." << endl; }
};

class Dialog
{
public:
    void fight()
    {
        Character* character = createCharacter();
        character->attack();
        character->dodge();
        character->deceive();
    }
    virtual Character* createCharacter() const = 0;
};

class WarDialog : public Dialog
{
    Character* createCharacter() const override { return new Warrior(); }
};

class ArchDialog : public Dialog
{
    Character* createCharacter() const override { return new Archer(); }
};

class WizDialog : public Dialog
{
    Character* createCharacter() const override { return new Wizard(); }
};

class Application {
public:
    static Dialog* initialize(const string& type) {
        if (type == "warrior") return new WarDialog();
        else if (type == "archer") return new ArchDialog();
        else if (type == "wizard") return new WizDialog();
        else throw invalid_argument("Invalid character type");
    }
};