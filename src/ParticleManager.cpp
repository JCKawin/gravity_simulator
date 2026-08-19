//
// Created by Asus on 19-08-2026.
//

#include "ParticleManager.h"
#include <list>

#include "Particle.h"

ParticleManager::ParticleManager() {
    std::list<Particle> m_particles;
    m_amount = 0;
}

ParticleManager::~ParticleManager() {

}

void ParticleManager::source_particles(int amount) {
    m_amount += amount;
}

ParticleManager& ParticleManager::get_instance() {
    static ParticleManager instance;
    return instance;
}

std::vector<std::pair<int, int> > ParticleManager::get_locations() {
    return m_locations;
}

std::vector<double> ParticleManager::get_sizes() {
    return m_sizes;
}

void ParticleManager::update() {

    for (auto &particle: m_particles) {
    }
}
