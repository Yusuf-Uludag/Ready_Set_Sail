#include "game.hpp"
#include <raylib.h>

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

const int screenWidth = 640;
const int screenHeight = 576;

int main()
{

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Ready, Set, Sail!");
    SetWindowMinSize(160, 144);

    InitGame();

#if defined(PLATFORM_WEB)

    emscripten_set_main_loop(GameLoop, 0, 1);

#else

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        GameLoop();
    }

#endif

    DeinitGame();
    CloseWindow();

    return 0;
}