#include "raylib.h"

int main(void) {
    InitWindow(1280, 720, "shadowRPG");
    SetTargetFPS(60);

    float x = 100.0f;
    float y = 100.0f;

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_D)) x += 3.0f;
        if (IsKeyDown(KEY_A)) x -= 3.0f;
        if (IsKeyDown(KEY_S)) y += 3.0f;
        if (IsKeyDown(KEY_W)) y -= 3.0f;

        BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangle((int)x, (int)y, 32, 32, SKYBLUE);
        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}