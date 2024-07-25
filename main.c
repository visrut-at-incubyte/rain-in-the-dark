#include <math.h>
#include <stdio.h>

#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Real Rain");

  Texture2D dummy = LoadTexture("dummy.png");
  Rectangle frameRec = {0.0f, 0.0f, (float)dummy.width / 3,
                        (float)dummy.height};
  Vector2 position = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};

  SetTargetFPS(30);

  int currentFrame = 0;
  int framesCounter = 0;

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_Q)) {
      break;
    }

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT)) {
      framesCounter++;

      if (framesCounter >= (60 / 10)) {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 5) currentFrame = 0;

        frameRec.x = (float)currentFrame * (float)dummy.width / 3;
      }

      if (IsKeyDown(KEY_RIGHT)) {
        position.x += 2;
      } else {
        position.x -= 2;
      }
    } else {
      framesCounter = 0;
      currentFrame = 0;
      frameRec.x = (float)currentFrame * (float)dummy.width / 3;
    }

    printf("frame time: %f\n", GetFrameTime());

    BeginDrawing();
    ClearBackground(BLACK);

    DrawTextureRec(dummy, frameRec, position, WHITE);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}

float CovertDegreeToRadian(float degree) { return degree * (PI / 180); }