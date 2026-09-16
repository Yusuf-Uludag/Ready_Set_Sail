#include <cmath>
#include <raylib.h>
#include "game.hpp"

const int targetWidth = 160;
const int targetHeight = 144;

RenderTexture2D target;
void InitGame()
{
    target = LoadRenderTexture(targetWidth, targetHeight);
    SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);
}

void DeinitGame()
{
    UnloadRenderTexture(target);
}

void UpdateGame()
{
}

void DrawGame()
{
    BeginTextureMode(target);

    {
        ClearBackground(WHITE);
        DrawText("Ready, Set, Sail!", 10, 60, 10, BLACK);
    }

    EndTextureMode();

    BeginDrawing();

    {
        ClearBackground(BLACK);

        int scale = static_cast<int>(std::fminf((float)GetScreenWidth() / targetWidth, (float)GetScreenHeight() / targetHeight));

        DrawTexturePro(target.texture,
                       // invert y since texture origin = bottom-left, window origin = top-left
                       (Rectangle){0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height},
                       (Rectangle){
                           (GetScreenWidth() - ((float)targetWidth * scale)) * 0.5f,
                           (GetScreenHeight() - ((float)targetHeight * scale)) * 0.5f,
                           (float)targetWidth * scale,
                           (float)targetHeight * scale,
                       },
                       (Vector2){0, 0},
                       0.0f,
                       WHITE);
    }

    EndDrawing();
}

void GameLoop()
{
    UpdateGame();
    DrawGame();
}
