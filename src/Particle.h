//
// Created by Asus on 19-08-2026.
//

#ifndef RAYLIBGAME_PARTICLE_H
#define RAYLIBGAME_PARTICLE_H


class Particle {
public :
    Particle(double radius, int locx, int locy);

    ~Particle();

    void set_pos(int locx, int locy);

    const int get_x() {return m_locx;}
    const int get_y() {return  m_locy;}
    const double get_r() {return  m_radius;}


    void move(int x, int y);

private:
    double m_radius;
    int m_locx;
    int m_locy;
};


#endif //RAYLIBGAME_PARTICLE_H
