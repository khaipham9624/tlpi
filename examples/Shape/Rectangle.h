#pragma once
#include "Shape.h"

class Rectangle: public Shape {
    private:
        float a, b;
    public:
        Rectangle(float a, float b){
            std::cout << "Rectangle constructor" << std::endl;
            this->a = a;
            this->b = b;
        }

        ~Rectangle(){
            std::cout << "Rectangle destructor" << std::endl;
        }

        float getArea() override {
            return a * b;
        }
};
