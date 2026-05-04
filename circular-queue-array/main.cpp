#include <iostream>
using namespace std;

class CircularQueue{
    private:
        int* arr;
        int head;
        int tail;
        int size;
        int count; // kitne elements hain
    
    public:
        CircularQueue(int s = 8){
            size = s;
            arr = new int[size];
            head = 0; 
            tail = -1;
            count = 0;
        };

        ~CircularQueue(){
            delete[] arr;
        };

        bool isEmpty(){ return count == 0;};
        bool isFull() { return count == size;};

        void enqueue(int x){
            if(isFull()){
                cout << "Queue is full \n";
                return;
            }; 
            tail = (tail + 1) % size;
            arr[tail] = x;
            count++;
        };

        int dequeue(){
            if(isEmpty()){
                cout << "Queue is empty \n";
                return -1;
            };
            int val = arr[head];
            head = (head + 1) % size;
            count--;
            return val;
        };

        int getHead(){
              if(isEmpty()){
                cout << "Queue is empty \n";
                return -1;
            };
            return arr[head];
        }

 void print() {
        if (isEmpty()) {
            cout << "Queue: (khali)\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(head + i) % size];
            if (i < count - 1) cout << " → ";
        }
        cout << "\n";
    }
};


int main(){

    CircularQueue cq(8);
    cq.enqueue(1);
    cq.enqueue(7);
    cq.enqueue(5);
    cq.enqueue(2);
    cq.print();

     cout << "Dequeue: " << cq.dequeue() << "\n"; // 1
    cout << "Dequeue: " << cq.dequeue() << "\n"; // 7
    cq.print();  // 5 → 2

     cq.enqueue(6); cq.enqueue(8); cq.enqueue(9);
    cq.enqueue(12); cq.enqueue(21); cq.enqueue(7);
    cq.print();
 cq.enqueue(99);
    return 0;   
}