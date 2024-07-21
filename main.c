#include "raylib.h"

int main(void)
{
    int screenWidth = 800;
    int screenHeight = 450;

    Vector2 ballPosition =  { (float)screenWidth/2, (float)screenHeight/2 };

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    int radius = 50;

    while (!WindowShouldClose())
    {

        if(IsKeyDown(KEY_DOWN)) {
            ballPosition.y += 5.0f;
            radius -= 1;
        }
        if(IsKeyDown(KEY_UP)) {
            ballPosition.y -= 5.0f;
            radius += 1;
        }
        if(IsKeyDown(KEY_RIGHT)) {
            ballPosition.x += 5.0f;
            radius += 1;
        }
        if(IsKeyDown(KEY_LEFT)) {
            ballPosition.x -= 5.0f;
            radius -= 1;
        }

        if(IsKeyDown(KEY_Q)) {
            break;
        }

        BeginDrawing();

        ClearBackground(BLACK);

        DrawCircleV(ballPosition, radius, MAROON);

        

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
