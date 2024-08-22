#include "List.h"
#include <exception>



class Stack:public List{
    public:
    Stack(){}
    ~Stack(){}
    
    NodeData peek(){
        if (getSize() == 0) {
            throw std::overflow_error("Stack is empty. Cannot peek");
        }
        return getHead()->data;
    }
    void pop(){
        if (getSize() == 0){
            throw std::underflow_error("Stack is empty. Cannot pop");
        }
        removeHead();
    }

    void push(NodeData data){
        insertHead(data);
    }
};