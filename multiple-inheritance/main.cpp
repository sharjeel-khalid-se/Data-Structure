#include <iostream>
using namespace std;

class Fish{
    public:
        void eat(){
            cout << "\n Fish Eat";
        }
};
class Human{
    public:
        void eat(){
            cout << "\n Human Eat";
        }
};

class Mermaid : public Fish, public Human{
    public:
      void eat(){
        Human::eat();
        Fish::eat();
      }
};

int main(){
    Mermaid mermaid;
    mermaid.eat();
    return 0;
}

