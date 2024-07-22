#include <math.h>
#include <stdio.h>

#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define RAIN_ANGLE 75

float CovertDegreeToRadian(float degree);

typedef struct Particle {
  Vector2 startPosition;
  int length;
} Particle;

Vector2 getEndPosition(Vector2 startPosition, float angle, int length) {
  Vector2 endPosition;
  endPosition.x = startPosition.x + length * cos(CovertDegreeToRadian(angle));
  endPosition.y = startPosition.y + length * sin(CovertDegreeToRadian(angle));
  return endPosition;
}

int main() {
  float speedX = 0;
  float speedY = 0;
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Real Rain");

  SetTargetFPS(60);

  Particle particle;
  particle.startPosition = (Vector2){SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
  particle.length = GetRandomValue(5, 30);

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_Q)) {
      break;
    }

    BeginDrawing();
    ClearBackground(BLACK);

    Vector2 startPosition = particle.startPosition;
    Vector2 endPosition =
        getEndPosition(particle.startPosition, RAIN_ANGLE, particle.length);

    DrawLine(startPosition.x + speedX, startPosition.y + speedY,
             endPosition.x + speedX, endPosition.y + speedY, WHITE);

    speedX += cos(CovertDegreeToRadian(RAIN_ANGLE));
    speedY += sin(CovertDegreeToRadian(RAIN_ANGLE));

    EndDrawing();
  }

  CloseWindow();
  return 0;
}

float CovertDegreeToRadian(float degree) { return degree * (PI / 180); }