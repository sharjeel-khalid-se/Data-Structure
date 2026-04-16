#include <iostream>
using namespace std;

// ══════════════════════════════════
// NODE
// ══════════════════════════════════
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// ══════════════════════════════════
// CIRCULAR LINKED LIST
// ══════════════════════════════════
class CircularList {
private:
    Node* head;     // pehla node
    Node* current;  // abhi kahan hain
    int size;

public:

    // Khali list banao
    CircularList() {
        head    = nullptr;
        current = nullptr;
        size    = 0;
    }

    // ──────────────────────────────
    // ADD
    // ──────────────────────────────
    void add(int value) {
        Node* newNode = new Node(value);

        // Case 1: List bilkul khali hai
        if (head == nullptr) {
            head          = newNode;
            current       = newNode;
            newNode->next = newNode; // apne aap ko point karo
            //  [newNode] ──┐
            //      ↑───────┘
        }
        // Case 2: List mein pehle se nodes hain
        else {
            // newNode ko current ke BAAD daalo

            newNode->next = current->next;
            // current → [X] → ...
            // newNode ────────→ [X]

            current->next = newNode;
            // current → newNode → [X]

            current = newNode;
            // ab current newNode pe
        }
        size++;
    }

    // ──────────────────────────────
    // NEXT — ek qadam aagay
    // ──────────────────────────────
    void next() {
        if (current != nullptr)
            current = current->next;
        // circular hai isliye NULL nahi aayega!
    }

    // ──────────────────────────────
    // REMOVE — current node hatao
    // ──────────────────────────────
    void remove() {
        if (head == nullptr) return; // khali list

        // Case 1: Sirf ek node bacha hai
        if (size == 1) {
            delete current;
            head    = nullptr;
            current = nullptr;
            size    = 0;
            return;
        }

        // Case 2: Ek se zyada nodes hain
        // Pehle woh node dhundo jo current ko point karta hai
        Node* prev = current;
        while (prev->next != current) {
            prev = prev->next;
        }
        // Ab prev->next == current

        prev->next = current->next;
        // current ko skip kar diya!

        // Agar head hi remove ho raha tha
        if (current == head) {
            head = current->next;
        }

        Node* toDelete = current;
        current = prev->next; // current aagay chala gaya

        delete toDelete; // memory free karo
        size--;
    }

    // Current ki value do
    int get() {
        if (current != nullptr)
            return current->data;
        return -1;
    }

    // List ki length
    int length() {
        return size;
    }

    // Current ko wapas start pe le jao
    void start() {
        current = head;
    }

    // ──────────────────────────────
    // PRINT — puri list dikhao
    // ──────────────────────────────
    void print() {
        if (head == nullptr) {
            cout << "List khali hai!" << endl;
            return;
        }

        Node* temp = head;
        cout << "List: ";
        do {
            cout << temp->data;
            if (temp->next != head)  // last node tak
                cout << " → ";
            temp = temp->next;
        } while (temp != head); // jab wapas head pe aao, ruko

        cout << " → (back to " << head->data << ")" << endl;
    }
};

int main() {
    CircularList list;

    // Nodes daalo
    list.add(2);
    list.add(6);
    list.add(8);
    list.add(7);
    list.add(1);

    list.print();
    // List: 2 → 6 → 8 → 7 → 1 → (back to 2)

    // Current kahan hai?
    cout << "Current: " << list.get() << endl; // 1

    // Aagay jao
    list.next();
    cout << "Next: " << list.get() << endl; // 2 (wapas shuru!)

    list.next();
    cout << "Next: " << list.get() << endl; // 6

    // Current node hatao
    list.remove();
    list.print();
    // List: 2 → 8 → 7 → 1 → (back to 2)

    cout << "Size: " << list.length() << endl; // 4

    return 0;
}