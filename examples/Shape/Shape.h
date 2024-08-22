#pragma once

class Shape {
    public:

        virtual Shape(){
            std::cout << "Shape constructor" << std::endl;
        }
        virtual ~Shape(){
            std::cout << "Shape destructor" << std::endl;
        };
        virtual float getArea() = 0;
};
