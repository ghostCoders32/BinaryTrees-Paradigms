#include<iostream>
#include "tree.h"



int main(){

    Fruit* fruit = new BlackBerry(10);
    BinaryTree tree(fruit);

    Fruit* apple = new Apple(25);
    Fruit* smallerApple = new Apple(5);
    Fruit* black = new BlackBerry(100);
    Fruit* anotherApple = new Apple(852);
    Fruit* orange1 = new Orange(1000);
    Fruit* orange2 = new Orange(-1000);

    tree.add(apple);
    tree.add(smallerApple);
    tree.add(black);
    tree.add(anotherApple);
    tree.add(orange1);
    tree.add(orange2);
    tree.findHeaviest()->printFruit();
    tree.findLightest()->printFruit();
    tree.magnifyByType(APPLE , 270);
    cout<<"---------------------------------------------------"<<endl;
    tree.Iterate();

    cout<<"ENDED"<<endl;
    tree.findHeaviest()->printFruit();
    tree.findLightest()->printFruit();
    

    return 0;
}

BinaryTree::BinaryTree(Fruit* fruit){
    this->fruit = fruit;
    this->right = NULL;
    this->left = NULL;
}
void BinaryTree::add(Fruit* fruit){
    if(fruit == NULL){
        cout<<"Fruit is NULL!"<<endl;
        return;
    }
    int value = fruit->getWeight();

    if(value < this->fruit->getWeight()){ // Left
        if(this->left == NULL){
            this->left = new BinaryTree(fruit);
            cout<<value<<" Added to the left of node "<<this->fruit->getWeight()<<endl;
        }
        else
            this->left->add(fruit);    
    }
    else{//Right
        if(this->right == NULL){
            this->right = new BinaryTree(fruit);
            cout<<value<<" Added to the right of node "<<this->fruit->getWeight()<<endl;
        }
        else
            this->right->add(fruit);     
    }
}
bool BinaryTree::contains(Fruit* fruit){
    int value = fruit->getWeight();
    if(this->fruit->getWeight() == value)
        return true;
    if(value <this->fruit->getWeight() && this->left != NULL)
        return this->left->contains(fruit);
    else if(value >=this->fruit->getWeight() &&this->right != NULL)
        return this->right->contains(fruit);        
    return false;    
}


Fruit* BinaryTree::getFruit(){
    return this->fruit;
}
BinaryTree* BinaryTree::getLeft(){
    return this->left;
}
BinaryTree* BinaryTree::getRight(){
return this->right;
}


void BinaryTree::Iterate(){//a method that prints the in-order traversal of the tree.
    if(this->left != NULL)
        this->left->Iterate();
    this->fruit->printFruit();
    if(this->right !=NULL)
        this->right->Iterate();    
}  
void BinaryTree::filterByType(int type){ //a method that prints the nodes of a given fruit type ordered by. weight. For example, get an ordered list of all apples in the tree
    if(this->left != NULL)
        this->left->filterByType(type);
    if(this->fruit->getType() == type)    
        this->fruit->printFruit();
    if(this->right !=NULL)
        this->right->filterByType(type);    
}
void BinaryTree::filterByWeight(int weight){// a method that prints the nodes that have weight larger than the given amount ordered by weight. For example, get an ordered list of all fruits in the tree that are heavier than 500 grams.
    if(weight<this->fruit->getWeight()){
        if(this->left != NULL)
            this->left->filterByWeight(weight);
        this->fruit->printFruit();
        if(this->right != NULL)
            this->right->Iterate(); //All on right are bigger.    
        return;    
    }
    //Now on Right
    if(this->right != NULL)
        this ->right->filterByWeight(weight);
}

void BinaryTree::magnifyByType(int type, int weight){// a method that increases the weight of the nodes of a given fruit type by the given amount. For example, add 200 grams to all bananas in the tree.
    this->magnifyOnly(type,weight);
    vector<Fruit*> vec;
    this->addNode(&vec);

     for (auto i = vec.begin(); i != vec.end(); ++i){
        if(i == vec.begin())
            continue;
        this->add(*i);    
     }
}
void BinaryTree::magnifyOnly(int type , int weight){
    if(this->fruit->getType() == type)
        this->fruit->magnifyWeight(weight);
    if(this->left != NULL)
        this->left->magnifyOnly(type , weight);
    if(this->right != NULL)
        this->right->magnifyOnly(type , weight);
}

Fruit* BinaryTree::findHeaviest(){  //a method that finds the node with the greatest weight in the tree. 
    if(this->right == NULL)
        return this->fruit;
    return this->right->findHeaviest();    
}
Fruit* BinaryTree::findLightest(){  //a method that finds the node with the least weight in the tree
    if(this->left == NULL)
        return this->fruit;
    return this->left->findLightest();    
}

void BinaryTree::addNode(vector<Fruit*> *vector){
    vector->push_back(this->fruit);
    if(this->left != NULL){
        this->left->addNode(vector);
        this->left = NULL;
    }

    if(this->right!=NULL){
        this->right->addNode(vector);
        this->right = NULL;
    }    

}







