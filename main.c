#include <math.h>
#include <stdio.h>

#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Real Rain");

  Image image = LoadImage("T-Shirt.png");
  Texture2D texture = LoadTextureFromImage(image);
  UnloadImage(image);

  SetTargetFPS(30);

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_Q)) {
      break;
    }

    printf("frame time: %f\n", GetFrameTime());

    BeginDrawing();
    ClearBackground(BLACK);

    DrawTexture(texture, SCREEN_WIDTH / 2 - texture.width / 2,
                SCREEN_HEIGHT / 2 - texture.height / 2, WHITE);
    DrawText("this IS a texture loaded from an image!", 300, 370, 10, GRAY);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}

float CovertDegreeToRadian(float degree) { return degree * (PI / 180); }