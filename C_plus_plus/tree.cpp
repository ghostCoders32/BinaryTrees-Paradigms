#include<iostream>
#include "tree.h"



int main(){

    BinaryTree tree(10);
    cout<<"Value is "<<tree.getData()<<endl;
    tree.add(55);
    tree.add(5);
    tree.add(60);
    tree.add(0);
    cout<<"ENDED"<<endl;


    return 0;
}

BinaryTree::BinaryTree(int value){
    this->data = value;
    this->right = NULL;
    this->left = NULL;
}
void BinaryTree::add(int value){
    if(value < this->data){ // Left
        if(this->left == NULL){
            this->left = new BinaryTree(value);
            cout<<value<<" Added to the left of node "<<this->data<<endl;
        }
        else
            this->left->add(value);    
    }
    else{//Right
        if(this->right == NULL){
            this->right = new BinaryTree(value);
            cout<<value<<" Added to the right of node "<<this->data<<endl;
        }
        else
            this->right->add(value);     
    }
}
bool BinaryTree::contains(int value){
    if(this->data == value)
        return true;
    if(value <this->data && this->left != NULL)
        return this->left->contains(value);
    else if(value >=this->data &&this->right != NULL)
        return this->right->contains(value);        
    return false;    
}


int BinaryTree::getData(){
    return this->data;
}
BinaryTree* BinaryTree::getLeft(){
    return this->left;
}
BinaryTree* BinaryTree::getRight(){
return this->right;
}




