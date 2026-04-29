#include <iostream>
using namespace std;

template <class T>
class Stack{
    public:
        int push(T &);
        T pop(void);
    
    private:
        int top;
        T* Nodes;
};

int main(){
    Stack <int> intStack;
    Stack <char> charStack;
    return 0;
}