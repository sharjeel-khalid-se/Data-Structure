#include <iostream>
using namespace std;

class Node{ 
    public:
    int data;
        Node* next;
        Node(int val){
            data = val;
            next = nullptr;
        }
};

class Stack{
    private:
        Node* head;
    public:
        Stack(){
            head = nullptr;
        } 

    bool isEmpty(){
        return (head == nullptr);
    }

    void push(int val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    int pop(){
        if(head == nullptr){
            cout << "Stack is Empty \n";
            return -1; 
        }

        int val = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return val;
    }

    int top(){
        if(isEmpty()){
            cout << "Stack is Empty \n";
            return -1;
        };

        return head->data;
    }


    void print(){
        if(isEmpty()){
            cout << "Stack is Empty \n";
            return;
        };

        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data;
            if(temp->next) cout << "->";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main(){
    Stack s;
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(7);

    cout << "Top : " << s.top() << "\n";
    cout << "Pop : " << s.pop() << "\n";
    cout << "Pop : " << s.pop() << "\n";

    s.print();
        return 0;
}