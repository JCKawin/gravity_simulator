//
// Created by Asus on 19-08-2026.
//

#include "Particle.h"


Particle::Particle(double radius, int locx , int locy) {
    m_radius = radius;
    m_locx = locx;
    m_locy = locy;
}


Particle::~Particle() {
}


void Particle::set_pos(int locx, int locy) {
    m_locx = locx;
    m_locy = locy;
}

void Particle::move(int x, int y) {
    m_locx += x;
    m_locy += y;
}
