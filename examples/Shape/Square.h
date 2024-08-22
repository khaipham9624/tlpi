#pragma once
#include "Shape.h"

class Square: public Shape {
    private:
        float a;
    public:
        Square(float a){
            this->a = a;
        }

        ~Square(){
            
        }

        float getArea() override {
            return a * a;
        }
};
