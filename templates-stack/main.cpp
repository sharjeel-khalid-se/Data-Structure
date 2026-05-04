#include <iostream>
using namespace std;

// ══════════════════════════════════════
// TEMPLATE STACK CLASS
// ══════════════════════════════════════
template <class T>      // T koi bhi type ho sakta hai
class Stack {
private:
    static const int MAX = 50;
    T     data[MAX];    // T type ka array — int, char, float sab!
    int   top;

public:
    // Constructor
    Stack() {
        top = -1;       // khali stack
    }

    // ── isEmpty ──
    bool isEmpty() {
        return (top < 0);
    }

    // ── isFull ──
    bool isFull() {
        return (top >= MAX - 1);
    }

    // ── push ──
    bool push(T x) {         // T type ka argument leta hai
        if (isFull()) {
            cout << "Stack overflow!\n";
            return false;
        }
        data[++top] = x;
        return true;
    }

    // ── pop ──
    T pop() {                // T type return karta hai
        if (isEmpty()) {
            cout << "Stack underflow!\n";
            return T{};      // default value return karo
        }
        return data[top--];
    }

    // ── peek/top ──
    T peek() {               // sirf dekho, nikalo nahi
        if (isEmpty()) {
            cout << "Stack khali!\n";
            return T{};
        }
        return data[top];
    }
};

// ══════════════════════════════════════
// MAIN — SAME class, alag types!
// ══════════════════════════════════════
int main() {
    // Int stack
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    cout << "Int Stack: "
         << intStack.pop() << ", "   // 20
         << intStack.pop() << "\n";  // 10

    // Char stack
    Stack<char> charStack;
    charStack.push('C');
    charStack.push('D');
    cout << "Char Stack: "
         << charStack.pop() << ", "  // D
         << charStack.pop() << "\n"; // C

    // Float stack bhi ho sakta hai!
    Stack<float> floatStack;
    floatStack.push(3.14f);
    floatStack.push(2.71f);
    cout << "Float Stack: "
         << floatStack.pop() << "\n"; // 2.71

    return 0;
}