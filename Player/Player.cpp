#include "Player.h"

void Player::SetHealth(int newHealth)
{
    health += newHealth;
}

int Player::GetHealth()
{
    return health;
}

Player::Player()
{
    this->health = 100;
    this->armor = 100;
    this->isDead = false;
}

std::ostream& operator<<(std::ostream& stream, const Player &player)
{
    const char* deadStatus = player.isDead ? "Yes" : "No";
    stream << "Health: " 
    << player.health 
    << " Armor: " 
    << player.armor 
    << " Dead: " 
    << deadStatus 
    << " Name: "
    << player.name
    << std::endl;
    return stream;
}