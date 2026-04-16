#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyList{
    private:
        Node* head;
        Node* current;
        int size;
    
    public:
        DoublyList(){
            head = nullptr;
            current = nullptr;
            size = 0;
        }

    void add(int val){
        Node* newNode = new Node(val);
        if(current == nullptr){
            head = newNode;
            current = newNode;
            size++;
        } else {
            newNode->next = current->next;
            newNode->prev = current;
             
            if(current->next != nullptr){
                current->next->prev = newNode;
            }

            current->next = newNode;
            current = newNode;
            size++;
        }
         
    }

    void remove(){
        if(current == nullptr) return;
        Node* prevNode = current->prev;
        Node* nextNode = current->next;

        if(prevNode != nullptr){
            prevNode->next = nextNode;
        } else {
            head  = nextNode;
        }

        if(nextNode != nullptr){
            nextNode->prev = prevNode;
        }

        delete current;
        current = (nextNode != nullptr) ? nextNode : prevNode;
        size--;
    }

    bool next(){
        if(current == nullptr || current->next == nullptr){
            return false;
        } 
        current = current->next;
        return true;
    }

    bool back(){
        if(current == nullptr || current->prev == nullptr){
            return false;
        }
        current = current->prev;
        return true;
    }

    int get(){
        if(current != nullptr){
            return current->data;
        }
        return -1;
    }

    void start() {current = head;}
    int length(){return size;}

    void print(){
        Node* temp = head;
        cout << "List : " ;
        while (temp != nullptr){
            cout << temp->data ;
            if(temp->next != nullptr){
                cout << " ⇄ ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

};


int main(){
    DoublyList dl;
    dl.add(4);
    dl.add(7);
    dl.add(2);
    dl.add(8);

    dl.print();

    dl.back();
    dl.back();
    cout << "Current: " << dl.get() << endl; 

    // 9 insert karo current ke baad
    dl.add(9);
    dl.print(); 

    return 0;
}