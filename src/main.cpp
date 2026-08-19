#include <cmath>
#include <iostream>
#include <raylib.h>
#include <vector>
#include "Particle.h"
static const int screen_width = 600;
static const int screen_height = 400;
static const int particle_amount = 1000;
static const int initial_radius = 1;


int main() {
    InitWindow(screen_width , screen_height ,"Gravity simulator");
    std::cout << "Init  WINDOW of (" << screen_width << " , " << screen_height << " ) px" << std::endl;

    std::cout << "Init Particles" <<std::endl;
    std::vector<Particle> particles;
    particles.reserve(particle_amount);

    // rectangulating

    double ratio = screen_width / screen_height;
    int x_number = ceil(std::sqrt(particle_amount * ratio));
    int y_number = ceil(particle_amount / x_number);
    int x_padding = screen_width / (x_number + 1);
    int y_padding = screen_height / (y_number + 1);


    for (int i = 0; i < x_number ; i++) {
        for (int j = 0 ; j < y_number ; j++) {
             particles.emplace_back(1 , 10 + i * x_padding  , 10 + j * y_padding );
        }
    }


    SetTargetFPS(120);

    bool running = true;
    while (!WindowShouldClose() and running) {
        // Process


        // Draw
        BeginDrawing();
        ClearBackground(BLACK);
        for (auto & particle : particles) {
            DrawCircle(particle.get_x() , particle.get_y() , particle.get_r() , WHITE);
        }
        // DrawText("Gravity Simulator", 190, 200, 20, LIGHTGRAY);

        DrawFPS(0 , 0);

        EndDrawing();
    }
    CloseWindow();

}
