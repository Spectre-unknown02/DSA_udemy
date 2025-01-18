#include<iostream>
using namespace std;

class node{
    public:
    int value;
    node *left;
    node *right;
    node(int value){
        this->value = value;
        this->left = nullptr;
        this->right = nullptr; 
    }
};

class BST{
    // private:
    // node *root;
    // public:
    // BST(int value){
    //     node *newNode = new node(value);
    //     root = newNode;
    // }

    //directly initalize the BST without root
    public:
    node *root;
    BST(int value){
        node *newNode = new node(value);
        root = newNode;
    }

    void BST_insert(int value){
        node *newNode = new node(value);
        if(root == nullptr){root = nullptr;}
        else{
            if(value>root->value){
                right = newNode;
            }
        }

    }
};
