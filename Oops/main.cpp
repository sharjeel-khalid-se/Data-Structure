#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int rollNo;
};

class Teacher{
    public:
        string subject;
        double salary;
};

class TA : public Student, public Teacher{
    string reasearhArea;
};

int main(){
    TA ta1;
    ta1.name = "Sharjeel";
    ta1.salary = 2439;

    cout << ta1.name << ta1.salary ;
}