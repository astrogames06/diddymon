#include "Player.hpp"

#include <iostream>

float MOVE_SPEED = 20.0f;

Rectangle frameRec;
int frame = 0;
float timer = 0;
int FRAMES = 9;
bool playing = false;

Texture2D right_spritesheet;
Texture2D left_spritesheet;
Texture2D up_spritesheet;
Texture2D down_spritesheet;
Texture2D current_texture;

extern Game game;

void Player::Init()
{
    Entity::Init();
    std::cout << "Player loaded!\n";
    right_spritesheet = LoadTexture("assets/player/walk_right.png");
    left_spritesheet = LoadTexture("assets/player/walk_left.png");
    up_spritesheet = LoadTexture("assets/player/walk_up.png");
    down_spritesheet = LoadTexture("assets/player/walk_down.png");
    current_texture = right_spritesheet;
    frameRec = {0, 0, (float)right_spritesheet.width / FRAMES, (float)right_spritesheet.height};
}

void CheckCollisions(Player &player, bool horizontal)
{
    for (const auto &rec : game.obstacles)
    {
        Rectangle playerRect = {player.position.x, player.position.y, frameRec.width, frameRec.height};
        if (CheckCollisionRecs(playerRect, rec))
        {
            if (horizontal)
            {
                if (player.velocity.x > 0)
                    player.position.x = rec.x - frameRec.width;
                else if (player.velocity.x < 0)
                    player.position.x = rec.x + rec.width;
            }
            else
            {
                if (player.velocity.y > 0)
                    player.position.y = rec.y - frameRec.height;
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
    {
        velocity.y -= MOVE_SPEED * GetFrameTime();
        current_texture = up_spritesheet;
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    {
        velocity.y += MOVE_SPEED * GetFrameTime();
        current_texture = down_spritesheet;
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        velocity.x -= MOVE_SPEED * GetFrameTime();
        current_texture = left_spritesheet;
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        velocity.x += MOVE_SPEED * GetFrameTime();
        current_texture = right_spritesheet;
    }
    
    if (velocity.x != 0 || velocity.y != 0)
    {
        timer += GetFrameTime();
        if (timer >= 0.1f)
        {
            frame = (frame + 1) % FRAMES;
            frameRec.x = frame * frameRec.width;
            timer = 0;
        }
    }
    
    position.x += velocity.x;
    CheckCollisions(*this, true);
    position.y += velocity.y;
    CheckCollisions(*this, false);
}

void Player::Draw()
{
    if (current_texture.id != 0)
    {
        DrawTextureRec(current_texture, frameRec, position, WHITE);
        DrawRectangleLines(position.x, position.y, frameRec.width, frameRec.height, GREEN);
    }
}