#include <cmath>
#include <iostream>
#include <raylib.h>
#include <vector>

static const int screen_width = 1280;
static const int screen_height = 720;
static const int particle_amount = 1000;
static const int initial_radius = 1;



struct Particle {
    double radius;
    Vector2 velocity;
    double x;
    double y;
    double mass;


    Particle(double radius, double x, double y, double mass = 5.9722e12, Vector2 velocity = Vector2(0, 0)) {
        this->radius = radius;
        this->x = x;
        this->y = y;
        this->mass = mass;
        this->velocity = velocity;

    }
};

int on_collision (std::vector<Particle>& particles ,const int p1 ,const int p2) {
    Particle particle_1 = particles.at(p1);
    Particle particle_2 = particles.at(p2);

    if (particle_1.radius > particle_2.radius) {
        particle_1.radius += particle_2.radius;
        return p2;
    }
    else  {
        particle_2.radius += particle_1.radius;
        return p1;
    }
}


Vector2 net_acceleration(
    const int particle_index,
    std::vector<Particle> &particles,
    double G = 6.67430e-11,
    double softeningSq = 1e-9) {
    Vector2 net_accel{0.0, 0.0};

    const double target_x = static_cast<double>(particles[particle_index].x);
    const double target_y = static_cast<double>(particles[particle_index].y);

    for (size_t i = 0; i < particles.size(); i++) {
        if (static_cast<int>(i) == particle_index) {
            continue;
        }
        double dx = static_cast<double>(particles[i].x) - target_x;
        double dy = static_cast<double>(particles[i].y) - target_y;
        double distSq = dx * dx + dy * dy + softeningSq;
        double invDist = 1.0 / std::sqrt(distSq);
        double invDistCube = invDist * invDist * invDist;
        double factor = G * particles[i].mass * invDistCube;
        net_accel.x += dx * factor;
        net_accel.y += dy * factor;
    }
    return net_accel;
}


int main() {
    InitWindow(screen_width, screen_height, "Gravity simulator");
    std::cout << "Init  WINDOW of (" << screen_width << " , " << screen_height << " ) px" << std::endl;

    std::cout << "Init Particles" << std::endl;
    std::vector<Particle> particles;
    particles.reserve(particle_amount);

    // rectangular placing

    double ratio = screen_width / screen_height;
    int x_number = ceil(std::sqrt(particle_amount * ratio));
    int y_number = ceil(particle_amount / x_number);
    int x_padding = screen_width / (x_number + 1);
    int y_padding = screen_height / (y_number + 1);

    int particle_alive = 0;
    for (int i = 0; i < x_number; i++) {
        for (int j = 0; j < y_number; j++) {
            particles.emplace_back(initial_radius, x_padding + i * x_padding, y_padding + j * y_padding);
            particle_alive++;
        }
    }

    std::cout << "Finished INIT " << std::endl;
    SetTargetFPS(120);

    bool running = true;
    while (!WindowShouldClose() and running) {
        double dt = GetFrameTime();

        // Process

        for (int i = 0; i < particle_alive; i++) {
            Vector2 acceleration = net_acceleration(i, particles);
            particles[i].velocity.x += acceleration.x * dt;
            particles[i].velocity.y += acceleration.y * dt;

            particles[i].x += particles[i].velocity.x * dt;
            particles[i].y += particles[i].velocity.y * dt;
        }


        // Draw
        BeginDrawing();
        ClearBackground(BLACK);
        for (auto &particle: particles) {
            DrawCircle(static_cast<int> (particle.x),
                static_cast<int>
                (
                    particle.y), particle.radius, WHITE);
        }

        // DrawText("Gravity Simulator", 190, 200, 20, LIGHTGRAY);

        DrawFPS(0, 0);

        EndDrawing();
    }
    CloseWindow();
}
