#include<iostream>
using namespace std;

class BinaryTree{

    private:
        BinaryTree *left;
        BinaryTree *right;

        int data;

    public:
        BinaryTree(int value);
        bool contains(int value);
        void add(int value);

        int getData();
        BinaryTree* getLeft();
        BinaryTree* getRight();

};