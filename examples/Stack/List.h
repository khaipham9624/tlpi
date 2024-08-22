#include <iostream>

typedef int NodeData;

struct Node
{
    NodeData data;
    Node *next;

    Node(NodeData data){
        this->data = data;
        next = nullptr;
    }
};


class List
{
    private:
        Node* head;
        Node* tail;
        int size;

    public:
        List(){
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        Node* getHead(){
            return head;
        }
        
        void insertHead(NodeData data){
            Node *newNode = new Node(data);

            if (tail == nullptr){
                tail = newNode;
            }
            if(head != nullptr){
                newNode->next = head;
            }
            head = newNode;
            size++;
        }

        void removeHead(){
            Node *currNode;
            currNode = head;
            if (currNode == nullptr)
                return;
            head = head->next;
            delete currNode;
        }

        void insertTail(NodeData data){
            Node* newNode = new Node(data);

            if (head == nullptr) {
                head = newNode;
            }
            tail->next = newNode;
            tail = newNode;
            size++;
        }

        void display(){
            Node *currNode = head;
            while (currNode != nullptr)
            {
                std::cout << currNode->data << "->";
                currNode = currNode->next;
            }
            std::cout << "nullptr" << std::endl;
            
        }

        int getSize(){
            return size;
        }
};

