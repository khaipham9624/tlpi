#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>

int main(){
    Shape *s1 = new Rectangle(4.0, 2.0);
    Shape *s2 = new Square(5.0);
    Shape *s3 = new Circle(10.0);

    std::cout << "Rectangle area = " << s1->getArea() << std::endl;
    std::cout << "Square area = " << s2->getArea() << std::endl;
    std::cout << "Circle area = " << s3->getArea() << std::endl;

    delete s1;
    delete s2;
    delete s3;
}