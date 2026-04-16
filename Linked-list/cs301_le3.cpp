#include <iostream>
using namespace std;

class Node {
    private:
        int data;
        Node* nextNode;
    public:
        int get(){
            return data;
        };

        void set(int val){
            data = val;
        }

        Node* getNext(){
            return nextNode;
        }

        void setNext(Node* nextNode){
            this->nextNode = nextNode;
        }

};

class List{
    private:
        Node* headNode;
        Node* currentNode;
        Node* lastCurrentNode;
        int listSize;
    public:
        // Create a list with a dummy head to simplify insertion/traversal.
        List(){
            headNode = new Node;
            headNode->setNext(nullptr);
            currentNode = nullptr;
            lastCurrentNode = headNode;
            listSize = 0;
        }

        // Insert a node after currentNode. If list is empty, insert first element.
        void add(int val){
            Node* newNode = new Node();
            newNode->set(val);

            if(currentNode != nullptr){
                newNode->setNext(currentNode->getNext());
                currentNode->setNext(newNode);
                lastCurrentNode = currentNode;
                currentNode = newNode;
            } else {
                newNode->setNext(nullptr);
                headNode->setNext(newNode);
                lastCurrentNode = headNode;
                currentNode = newNode;
            }

            ++listSize;
        }

        int get(){
            if(currentNode != nullptr){
                return currentNode->get();
            }
            return -1;
        }

        void next(){
            if(currentNode == nullptr){
                return ;
            } else {
                lastCurrentNode = currentNode;
                currentNode = currentNode->getNext();
            }
        }

        int size() const {
            return listSize;
        }

        // Print all elements from first to last without changing list state.
        void traverse() const {
            Node* temp = headNode->getNext();
            int i = 0;

            while(temp != nullptr){
                cout << "Element " << i << " = " << temp->get() << "\n";
                temp = temp->getNext();
                ++i;
            }
        }
};

int main (){
    List list;

    // Add sample values to demonstrate list creation and traversal.
    list.add(2);
    list.add(6);
    list.add(8);
    list.add(7);
    list.add(1);

    cout << "List Size = " << list.size() << "\n";
    list.traverse();


    
    return 0;
}