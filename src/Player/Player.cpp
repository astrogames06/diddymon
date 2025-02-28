#include "Player.hpp"

#include <iostream>

void Player::Init()
{
    Entity::Init();
    std::cout << "Player loaded!\n";
}
void Player::Update()
{
    std::cout << "Player updated!\n";
}
void Player::Draw()
{
    std::cout << "Player drawn!\n";
    DrawRectangle(200, 200, 50, 50, RED);
}