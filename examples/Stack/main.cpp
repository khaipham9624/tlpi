#include "Stack.h"

int main(){
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    stack.display();
    std::cout << "Peek: " << stack.peek() <<  std::endl;
    std::cout << "After poped: ";
    stack.pop();
    stack.display();
}
