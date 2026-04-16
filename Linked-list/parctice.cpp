#include <iostream>
using namespace std;

class Node{
    public:
     int data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }
};

class List{
    private:
        Node* head;
        Node* tail;
    public:
        List(){
            head = NULL;
            tail = NULL;
        }

    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
            return;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        if(head == NULL){
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int val, int pos){
        if(pos < 0){
            cout << "Invalid Position\n";
            return;
        }
        if(pos == 0){
            push_front(val);
            return;
        }

        Node* temp = head;
        for(int i; i<pos-1 ; i++){
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int search(int key){
    Node* temp = head;
    int index = 0;

    while(temp != NULL){
        if(temp->data == key){
            return index;
        }
        temp = temp->next;
        index++;
    }

    return -1;  // not found
}

    void print(){
        Node* temp = head;

        while(temp !=NULL){
            cout << temp->data << " " ;
            temp = temp->next;
        }

        cout << endl;
    }
};


int main (){
    List list;
    list.push_front(3);
    list.push_front(6);
    list.push_front(7);
    list.push_back(9);
    list.pop_front();
    list.pop_back();
    list.insert(5, 2);
    cout << list.search(5) << endl;
    list.print();
    return 0;
}