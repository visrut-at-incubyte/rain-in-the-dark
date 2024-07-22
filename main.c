#include "raylib.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Real Rain");

    SetTargetFPS(60);


    while(!WindowShouldClose()) {
        if(IsKeyDown(KEY_Q)) {
            break;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}