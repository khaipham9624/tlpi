#include <iostream>

class Singleton {
    private:
        Singleton(){};
        ~Singleton(){};
    public:
        Singleton(const Singleton &source) = delete;
        Singleton(Singleton &&source) = delete;
        Singleton& operator=(Singleton &source) = delete;

        static Singleton& getInstance(){
            static Singleton instance;
            return instance;
        }

        void doSomething(){
            std::cout << "do something" << std::endl;
        }
};
