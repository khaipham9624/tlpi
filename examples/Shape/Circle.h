#pragma once
#include "Shape.h"


class Circle : public Shape
{
private:
    float r;
public:
    constexpr static float getPI(){
        return 3.14;
    }
    Circle(float r) {
        std::cout << "Circle constructor" << std::endl;
        this->r = r;
    }

    ~Circle(){
        std::cout << "Circle destructor" << std::endl;
    }

    float getArea() override {
        return r * r * getPI();
    }
};
