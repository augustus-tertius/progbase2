#ifndef CPP_SPHERE_H
#define CPP_SPHERE_H

//#include <iostream>
#include <string>

class Ball {
    private:
        std::string name;
        double radius;
        bool isHollow;

    public:
        Ball(std::string name, double radius, bool isHollow);
        double getVolume(void);
        void toString(void);
};


#endif //CPP_SPHERE_H
