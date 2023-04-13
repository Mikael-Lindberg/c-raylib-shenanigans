#include "raylib.h"

struct Box {
    int x;
    int y;
    int width;
    int height;

    int min_force;
    int cur_force;
    int max_force;
};

int main(void)
{
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    Box box = {100, 100, 50, 50, -300, 0, 600};

    int decrementValue = 10;
    float timeCounter = 0.0f;

    while (!WindowShouldClose())
    {
        timeCounter -= GetFrameTime();
        box.cur_force += decrementValue;

        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawRectangle(box.x, box.y, box.width, box.height, RED);

            DrawText("this is DEFINITELY gonna work!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
