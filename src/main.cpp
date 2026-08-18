#include <iostream>
#include <raylib.h>

static const int screen_width = 600;
static const int screen_height = 400;

int main() {
    InitWindow(screen_width , screen_height ,"Gravity simulator");

    SetTargetFPS(60);

    bool running = true;
    while (!WindowShouldClose() and running) {
        // Process


        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Gravity Simulator", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }
    CloseWindow();

}
