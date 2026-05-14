#include <iostream>
using namespace std;

template <class T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T data) : data(data), left(nullptr), right(nullptr) {}

    bool isLeaf(){
        return left == nullptr && right == nullptr;
    }
};


template <class T>
struct BST {
    TreeNode<T>* root;
    BST() : root(nullptr) {}

    void insert(T value){
        TreeNode<T>* newNode = new TreeNode<T>(value);

        if(!root){
            root = newNode;
            return;
        }

        TreeNode<T>* p = root; // tails behind
        TreeNode<T>* q = root; // walks forward

        while(q != nullptr && value != q->data){
            p = q;
            if(value < q->data){
                q = q->left;
            } else {
                q = q->right;
            }

            // duplicate value, do not insert
            if(q != nullptr && value == q->data){
                cout << "Duplicate value: " << value << endl;
                delete newNode; // clean up the allocated node
                return;
            } else if (value < p->data){
                p->left = newNode;
                return;
            } else {
                p->right = newNode;
                return;
            }
        }
    }


    bool find(T value){
    TreeNode<T>* curr = root;
    while(curr != nullptr){
        if(value == curr->data){
            return true;
        } else if(value < curr->data){
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return false;
};
};


int main(){
    BST<int> tree;
    int nums[] = {14,15,4,9,7,18,3,5,16,4,20,17,9,14,5};

    for (int n : nums)
        tree.insert(n);

    cout << "Find 17: " << (tree.find(17) ? "Yes" : "No") << "\n"; // Yes
    cout << "Find 99: " << (tree.find(99) ? "Yes" : "No") << "\n"; // No
    return 0;
}