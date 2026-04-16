#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int* ptr = &a;
    int** ptr2ptr = &ptr;

    cout << "Value of a is: " << a << endl;
    cout << "The Address of a: " << ptr << endl;

    cout << "Defre of PTR is: " << *ptr << endl;
    
    cout << "Address of PTR is: " << ptr2ptr << endl;
    cout << "Defre of PTR2 is: " << *ptr2ptr << endl; 
    cout << "Double Defre of PTR2: " << **ptr2ptr << endl; 
    return 0;
}