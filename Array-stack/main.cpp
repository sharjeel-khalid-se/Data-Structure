#include <iostream>
#include <stdexcept>
using namespace std;

class Stack{
    private:
        int A[10];
        int top;
        int size;
    
    public:
        Stack(){
            size = 10;
            top = -1;
        }

        bool isEmpty(){
           return (top == -1);
        }

        bool isFull(){
            return (top == size -1);
        }

        void push(int x){
            if(isFull()){
                cout << "Stack is full!" << endl;
                return;
            }

            A[++top] = x;
        }

        int pop(){
            if(isEmpty()){
                cout << "Stack is Empty" << endl;
            };
            return A[top--];
        }

        int getTop(){
            if(isEmpty()){
                cout << "Stack is Empty" << endl;
            }
            return A[top];
        }

        void print(){
            if(isEmpty()){
                cout << "Stack is Empty" << endl;
                return;
            };
            cout << "Stack (from top) : ";
            for(int i = top; i >= 0; i--){
                    cout << A[i];
                    if(i == 0) cout << "->";
            }
            cout << endl;
        }
};

int main(){
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.print();


     cout << "Top: " << stack.getTop() << "\n";

      cout << "Pop: " << stack.pop() << "\n";  // 1
    cout << "Pop: " << stack.pop() << "\n";  // 7
    stack.print();       // Stack (top se): 5 → 2

     Stack stack2;
    for (int i = 0; i < 12; i++)
        stack2.push(i);
    // "Stack Full!" 2 baar aayega
    return 0;
}