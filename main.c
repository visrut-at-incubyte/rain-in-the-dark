#include "raylib.h"

int main(void)
{
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("Congrats! You created your first window!", 190, 200, 20, RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
