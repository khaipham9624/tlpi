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
        this->r = r;
    }

    ~Circle(){

    }

    float getArea() override {
        return r * r * getPI();
    }
};
