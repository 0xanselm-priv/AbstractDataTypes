//
// Created by Robert on 18/09/2019.
//

#include <iostream>
#include <stdio.h>
#include <array>
#include <iomanip>

using namespace std;

class BinaryTree {
private:
    typedef struct Node {
        int data;
        Node *left = nullptr;
        Node *right = nullptr;
    };
    Node *root;
public:

    BinaryTree() {
        root = new Node;
        root->data = 50;
        root->left = nullptr;
        root->right = nullptr;
        cout << "Root at: " << &root << endl;
    }

    Node *getRoot() {
        return root;
    }

    static Node *generateNode(int data) {
        Node *temp = new Node();
        temp->data = data;
        temp->left = nullptr;
        temp->right = nullptr;
        return temp;
    }

    void insert(Node *temp, int data) {
        if (temp->data > data) {
            if (temp->left != nullptr) {
                insert(temp->left, data);
            } else {
                temp->left = generateNode(data);
            }
        } else {
            if (temp->right != nullptr) {
                insert(temp->right, data);
            } else {
                temp->right = generateNode(data);
            }
        }
    }

    void inorder(Node *temp, int indent = 0) {
        if (temp == nullptr) {
            return;
        }
        inorder(temp->left, indent + 1);
        cout<< " " << indent << " "<< temp->data;
        inorder(temp->right, indent + 1);
    }
     void postorder(Node *temp, int indent = 0) {
         if (temp == nullptr) {
             return;
         }
         inorder(temp->left, indent + 1);
         inorder(temp->right, indent + 1);
         cout<< " " << indent << " "<< temp->data;
     }

    void preorder(Node *temp, int indent = 0) {
        if (temp == nullptr) {
            return;
        }
        cout<< " " << indent << " "<< temp->data;
        inorder(temp->left, indent + 1);
        inorder(temp->right, indent + 1);
    }

    int isBalanced(Node* temp, int i = 0) {
        if (temp == nullptr) {
            return 0; }
        else {
            cout << isBalanced(temp->left, i+1) << endl;
            cout << isBalanced(temp->left, i+1) << endl;
        }
    }
    int depth(Node* temp) {
        if (temp == nullptr) {
            return 0;
        } else {
            return max(depth(temp->left)+1, depth(temp->right)+1);
        }
    }
};

int main() {
    BinaryTree a = *new BinaryTree;
    a.insert(a.getRoot(), 1);
    a.insert(a.getRoot(), 55);
    a.insert(a.getRoot(), 20);
    a.insert(a.getRoot(), 56);
    a.insert(a.getRoot(), 98);

    cout << a.depth(a.getRoot()) << endl;
    a.postorder(a.getRoot());
    cout <<"\n";
    a.preorder(a.getRoot());
    cout <<"\n";
    a.isBalanced(a.getRoot(), 0);
    return 0;
}



