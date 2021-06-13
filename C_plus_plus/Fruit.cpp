#include "Fruit.h"


Fruit::Fruit(int weight){
    cout<<"Fruit Constructor Called"<<endl;
    this->weight = weight;
}
int Fruit::getWeight(){
    // cout<<"Fruit class called getWeight()"<<endl;
    return this->weight;
}
void Fruit::setWeight(int weight){
    cout<<"Fruit class called setWeight()"<<endl;
    this->weight = weight;
}
void Fruit::magnifyWeight(int addition){
    cout<<"Fruit class called magnifyWeight()"<<endl;
    if (addition>0)
        this->weight += addition;
    else
        cout<<"ERROR"<<endl;    
}

OvalShaped::OvalShaped(int weight) : Fruit(weight){
    cout<<"OvalShaped Constructor called"<<endl;
}
void OvalShaped::setWeight(int weight){
    cout<<"(Override)OvalShaped setWeight called"<<endl;
    cout<<"Now a simple delegation"<<endl;
    Fruit::setWeight(weight);
}
int OvalShaped::getType(){
    return OVAL_SHAPED;
}
void OvalShaped::printFruit(){
    cout<<"OvalShaped fruit of weight : "<<Fruit::getWeight()<<endl;
}

Berry::Berry(int weight):Fruit(weight){
    cout<<"Berry Constructor called"<<endl;
}
void Berry::setWeight(int weight){
    cout<<"(Override)Berry setWeight called"<<endl;
    cout<<"Now a simple delegation"<<endl;
    Fruit::setWeight(weight);
}
int Berry::getType(){
    return BERRY;
}
void Berry::printFruit(){
    cout<<"Berry fruit of weight : "<<Fruit::getWeight()<<endl;
}


BlackBerry::BlackBerry(int weight):Berry(weight){
     cout<<"BlackBerry Constructor called"<<endl;
    this->inst = new OvalShaped(weight); //DELEGATION.
}
int BlackBerry::getType(){
    return BLACKBERRY;
}
void BlackBerry::printFruit(){
    cout<<"Blackberry fruit: (\n\n";
    Berry::printFruit();
    this->inst->printFruit();
    cout<<"\n\n)";    
}

Apple::Apple(int weight):OvalShaped(weight){
    cout<<"Apple Constructor called"<<endl;
}
int Apple::getType(){
    return APPLE;
}
void Apple::printFruit(){
    cout<<"Apple fruit: (\n\n";
    OvalShaped::printFruit();
    cout<<"\n\n)";
}










