#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    // Node(int val){
    //     data = val;
    //     next = nullptr;
    // };

    Node(int val) : data(val), next(nullptr) {};
};

class Queue{
    private:
        Node* head;
        Node* tail;
        int size;
    public:
        Queue(){
            head = nullptr;
            tail = nullptr;
            size = 0;
        };

        bool isEmpty(){
            return (head == nullptr);
        }

        void enqueue(int x){
            Node* newNode = new Node(x);
            if(tail == nullptr){
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            size++;
        };

        int dequeue(){
            if(isEmpty()){
                cout << "Queue is Empty \n";
                return -1;
            }

            Node* temp = head;
            int val = head->data;
            head = head->next;

            if(head == nullptr){
                tail = nullptr;
            }

            delete temp;
            size--;
            return val;
        };

        int getHead(){
            if(isEmpty()){
                cout << "Queue is Empty \n";
                return -1;
            }

            return head->data;
        };

        void print(){
            Node* temp = head;
            cout << "Queue (head -> tail) : ";
            while(temp != nullptr){
                cout << temp->data;
                if(temp->next != nullptr){
                    cout << " -> ";
                }

                temp = temp->next;
            }
            cout << "\n";
        };




};
int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.print();

    cout << "head: " << q.getHead() << endl;
    cout << "Pop: " << q.dequeue() << endl;
    cout << "Head: " << q.getHead() << endl;
    cout << "Pop: " << q.dequeue() << endl;
    q.print();

    q.enqueue(9);
    q.print();
    return 0;
}