#pragma once

#include <iostream>
#include <string>

using namespace std;

// Интерфейс команды, ожидаемый игрой
class GameCommandInterface {
public:
    virtual void jump() = 0;
    virtual void hit() = 0;
    virtual void moveForward() = 0;
    virtual void moveBackward() = 0;
};

// Контроллер Xbox с собственным интерфейсом
class XboxController {
public:
    void xboxJump() { cout << "Xbox Controller: Jump executed.\n"; }
    void xboxHit() { cout << "Xbox Controller: Hit executed.\n"; }
    void xboxMoveForward() { cout << "Xbox Controller: Move forward executed.\n"; }
    void xboxMoveBackward() { cout << "Xbox Controller: Move backward executed.\n"; }
};

// Адаптер для Xbox-контроллера
class XboxAdapter : public GameCommandInterface {
private:
    XboxController controller;

public:
    void jump() override { controller.xboxJump(); }
    void hit() override { controller.xboxHit(); }
    void moveForward() override { controller.xboxMoveForward(); }
    void moveBackward() override { controller.xboxMoveBackward(); }
};

// Контроллер PlayStation с собственным интерфейсом
class PlayStationController {
public:
    void psJump() { cout << "PlayStation Controller: Jump executed.\n"; }
    void psHit() { cout << "PlayStation Controller: Hit executed.\n"; }
    void psMoveForward() { cout << "PlayStation Controller: Move forward executed.\n"; }
    void psMoveBackward() { cout << "PlayStation Controller: Move backward executed.\n"; }
};

// Адаптер для PlayStation-контроллера
class PlayStationAdapter : public GameCommandInterface {
private:
    PlayStationController controller;

public:
    void jump() override { controller.psJump(); }
    void hit() override { controller.psHit(); }
    void moveForward() override { controller.psMoveForward(); }
    void moveBackward() override { controller.psMoveBackward(); }
};

// Игра, использующая команду
void playGame(GameCommandInterface* command) {
    command->jump();
    command->hit();
    command->moveForward();
    command->moveBackward();
}