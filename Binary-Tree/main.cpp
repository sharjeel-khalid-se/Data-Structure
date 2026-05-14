#include <iostream>
using namespace std;

// ══════════════════════════════════
// BINARY TREE NODE
// ══════════════════════════════════
struct TreeNode {
    int       data;
    TreeNode* left;   // left child
    TreeNode* right;  // right child

    TreeNode(int val) {
        data  = val;
        left  = nullptr;
        right = nullptr;
    }
};

// ══════════════════════════════════
// SIMPLE BINARY TREE
// ══════════════════════════════════
class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    // Build tree manually for demonstration
    void buildSampleTree() {
        //         A(1)
        //        /    \
        //      B(2)   C(3)
        //      / \       \
        //    D(4) E(5)   F(6)
        //         /     / \
        //       G(7)  H(8) I(9)

        root          = new TreeNode(1);   // A
        root->left    = new TreeNode(2);   // B
        root->right   = new TreeNode(3);   // C

        root->left->left  = new TreeNode(4); // D
        root->left->right = new TreeNode(5); // E

        root->right->right         = new TreeNode(6); // F
        root->left->right->left    = new TreeNode(7); // G
        root->right->right->left   = new TreeNode(8); // H
        root->right->right->right  = new TreeNode(9); // I
    }

    // Get level of a node (recursive)
    int getLevel(TreeNode* node, TreeNode* target, int level) {
        if (!node) return -1;
        if (node == target) return level;

        int left  = getLevel(node->left,  target, level + 1);
        int right = getLevel(node->right, target, level + 1);
        return (left != -1) ? left : right;
    }

    // Check if it's a leaf
    bool isLeaf(TreeNode* node) {
        return node && !node->left && !node->right;
    }

    // Print tree info
    void printInfo() {
        cout << "Root: " << root->data << "\n";
        cout << "Root left child: "  << root->left->data  << "\n";
        cout << "Root right child: " << root->right->data << "\n";
        cout << "Is D a leaf? " << (isLeaf(root->left->left) ? "Yes" : "No") << "\n";
    }
};

int main() {
    BinaryTree tree;
    tree.buildSampleTree();
    tree.printInfo();
    return 0;
}