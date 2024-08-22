#pragma once
#include "Shape.h"

class Rectangle: public Shape {
    private:
        float a, b;
    public:
        Rectangle(float a, float b){
            this->a = a;
            this->b = b;
        }

        ~Rectangle(){
            
        }

        float getArea() override {
            return a * b;
        }
};
