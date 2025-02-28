#include "Game.hpp"

void Game::Init()
{
    ToggleFullscreen();
    for (Entity& entity : entities)
    {
        entity.Init();
    }
}

void Game::Update()
{
    for (Entity& entity : entities)
    {
        entity.Update();
    }
}

void Game::Draw()
{
    for (Entity& entity : entities)
    {
        entity.Draw();
    }
    for (const auto &rec : obstacles)
    {
        DrawRectangleRec(rec, GRAY);
    }
}