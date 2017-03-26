//
// Created by august on 27.03.17.
//

#ifndef CPP_BALL_H
#define CPP_BALL_H


#include <string>

class Ball {
private:
    std::string name;
    double radius;
    bool isHollow;

public:
    Ball();
    Ball(std::string name, double radius, bool isHollow);
    double getVolume(void);
    void toString(void);
};

#endif //CPP_BALL_H
