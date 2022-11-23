#pragma once

#include <iostream>

class Player
{
public:
    int health;
    int armor;
    bool isDead = false;

    std::string name;

    Player();

    friend std::ostream& operator<<(std::ostream &stream, const Player& player);

    int GetHealth();
    void SetHealth(int newHealth);
};