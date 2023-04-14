#include "raylib.h"

static float PLACE_AT_FLOOR(float input) {
    return input / 2.0f;
}

struct Tile {
    Vector3 position;
    Vector3 size;
    Color color;
    Color wire_color;
};

void draw_tile(struct Tile *tile) {
    DrawCube(tile -> position, tile -> size.x, tile -> size.y, tile -> size.z, tile -> color);
    DrawCubeWires(tile -> position, tile -> size.x, tile -> size.y, tile -> size.z, tile -> wire_color);
}

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera free");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 4.0f, 8.0f, 16.0f };
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
    //ToggleFullscreen();

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        //UpdateCamera(&camera, CAMERA_FREE);
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
