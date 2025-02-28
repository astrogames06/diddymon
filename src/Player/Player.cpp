#include "Player.hpp"

#include <iostream>

 int PLAYER_SIZE = 50;
 float MOVE_SPEED = 200.0f;

extern Game game;

void Player::Init()
{
    Entity::Init();
    std::cout << "Player loaded!\n";
}

void CheckCollisions(Player &player, bool horizontal)
{
    for (const auto &rec : game.obstacles)
    {
        Rectangle playerRect = {player.position.x, player.position.y, (float)PLAYER_SIZE, (float)PLAYER_SIZE};
        if (CheckCollisionRecs(playerRect, rec))
        {
            if (horizontal)
            {
                if (player.velocity.x > 0)
                    player.position.x = rec.x - PLAYER_SIZE;
                else if (player.velocity.x < 0)
                    player.position.x = rec.x + rec.width;
            }
            else
            {
                if (player.velocity.y > 0)
                    player.position.y = rec.y - PLAYER_SIZE;
                else if (player.velocity.y < 0)
                    player.position.y = rec.y + rec.height;
            }
        }
    }
}
void Player::Update()
{
    velocity = {0, 0};
    
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
        velocity.y -= MOVE_SPEED * GetFrameTime();
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
        velocity.y += MOVE_SPEED * GetFrameTime();
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
        velocity.x -= MOVE_SPEED * GetFrameTime();
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
        velocity.x += MOVE_SPEED * GetFrameTime();
    
    position.x += velocity.x;
    CheckCollisions(*this, true);
    position.y += velocity.y;
    CheckCollisions(*this, false);
}

void Player::Draw()
{
    std::cout << "Player drawn!\n";
    DrawRectangleV(position, {(float)PLAYER_SIZE, (float)PLAYER_SIZE}, RED);
}