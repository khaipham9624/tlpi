#pragma once
#include "Shape.h"

class Square: public Shape {
    private:
        float a;
    public:
        Square(float a){
            std::cout << "Square constructor" << std::endl;
            this->a = a;
        }

        ~Square(){
            std::cout << "Square destructor" << std::endl;
        }

        float getArea() override {
            return a * a;
        }
};
