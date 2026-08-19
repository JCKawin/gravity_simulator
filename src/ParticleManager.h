//
// Created by Asus on 19-08-2026.
//

#ifndef RAYLIBGAME_PARTICLEMANAGER_H
#define RAYLIBGAME_PARTICLEMANAGER_H
#include <vector>
#include <utility>
#include <list>
#include "Particle.h"

class ParticleManager {
private:

    ParticleManager();
    ~ParticleManager();


public:

    ParticleManager(const ParticleManager&) = delete;
    ParticleManager& operator=(const ParticleManager&) = delete;
    ParticleManager(ParticleManager&&) = delete;
    ParticleManager& operator=(ParticleManager&&) = delete;


    void source_particles(int amount);
    static ParticleManager& get_instance();
    std::vector<std::pair<int , int >> get_locations();
    std::vector<double> get_sizes();

    void update();

private:
    std::list<Particle> m_particles;
    size_t m_amount ;
    std::vector<std::pair<int , int >>  m_locations;
    std::vector<double>  m_sizes;

};


#endif //RAYLIBGAME_PARTICLEMANAGER_H
