#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    };

};

class CricularList{
    private:
        Node* head;
        Node* current;
        int size;
    
    public:
        CricularList(){
            head = nullptr;
            current = nullptr;
            size = 0;
        };

        void add(int val){
            Node* newNode = new Node(val);
            if(head == nullptr){
                head = newNode;
                current = newNode;
                newNode->next  = newNode;
            } else {
                newNode->next = current->next;
                current->next = newNode;
                current = newNode;
            }
            size++;
        }

        void next(){
            if(head != nullptr){
                current = current->next;
            }
        };

        void remove(){
            if(head == nullptr){
                return;
            };

            if(size == 1){
                delete current;
                head = nullptr;
                size = 0;
                return;
            }

            Node* prev = current;
            while(prev->next != current){
                prev = prev->next;
            }

            prev->next = current->next;
            if(current == head){
                head  = current->next;
            }

            Node* toDelete = current;
            current = prev->next;
            delete toDelete;
            size--;
        }

        int  get()    { return current ? current->data : -1; }
    int  length() { return size; }
    void start()  { current = head; }

};

int main(){

    CricularList list;

    int  N = 10;
    int M = 3;

    for(int i = 1; i<= N; i++){
        list.add(i);
    };

    list.start();

    cout << "=== Josephus Problem === " << endl;
    cout << "log: " << N << ", cout : " << M << endl;
    cout << '====' << endl;
    int round = 1;

    while(list.length() >  0){
        for(int i = 1; i <= M ; i++){
            list.next();
        };

        cout << "Round " << round << " Nikala  -> " << list.get() << endl;

        list.remove();
        round++;
          
    }
    return 0;
}