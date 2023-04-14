#include "raylib.h"

struct Tile {
    Vector3 position;
    Vector3 size;
    Color color;
    Color wire_color;
};

void draw_tile(struct Tile *tile) {
    DrawCubeV(tile -> position, tile -> size, tile -> color);
    DrawCubeWiresV(tile -> position, tile -> size, tile -> wire_color);
}

int main(void) {
    const int screenWidth = 1400;
    const int screenHeight = 850;

    InitWindow(screenWidth, screenHeight, "c-raylib-shenanigans");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 20.0f, 16.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Tile tile = Tile {
        { 1.0f, 0.1f, 1.0f },
        { 2.0f, 0.2f, 2.0f },
        RED,
        BLACK
    };
    Tile tile2 = Tile {
        { 3.0f, 0.75f, 1.0f },
        { 2.0f, 1.5f, 2.0f },
        GREEN,
        BLACK
    };
    Tile tile3 = Tile {
        { -1.0f, 0.75f, 1.0f },
        { 2.0f, 1.5f, 2.0f },
        BLUE,
        BLACK
    };

    DisableCursor();

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        DrawFPS(5, 5);

        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                
                draw_tile(&tile);
                draw_tile(&tile2);
                draw_tile(&tile3);

                DrawGrid(20, 2.0f);

            EndMode3D();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
