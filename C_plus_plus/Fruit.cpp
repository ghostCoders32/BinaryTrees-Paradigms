#include "Fruit.h"


Fruit::Fruit(int weight){
    this->weight = weight;
}
int Fruit::getWeight(){
    return this->weight;
}
void Fruit::setWeight(int weight){
    this->weight = weight;
}
void Fruit::magnifyWeight(int addition){
    if (addition>0)
        this->weight += addition;
    else
        cout<<"ERROR"<<endl;    
}

OvalShaped::OvalShaped(int weight) : Fruit(weight){
}
void OvalShaped::setWeight(int weight){
    Fruit::setWeight(weight);
}
int OvalShaped::getType(){
    return OVAL_SHAPED;
}
string OvalShaped::printFruit(){
    return "OvalShaped -> "+to_string(Fruit::getWeight());
}

Berry::Berry(int weight):Fruit(weight){
}
void Berry::setWeight(int weight){
    Fruit::setWeight(weight);
}
int Berry::getType(){
    return BERRY;
}
string Berry::printFruit(){
    return "Berry->"+to_string(Fruit::getWeight());
}

Citrus::Citrus(bool isFruit){
    this->isFruitt = isFruit;
}
string Citrus::printCitrus(){
    if(this->isFruitt)
        return"Citrus";
    else
        return "Citrus but not a fruit";    
}



BlackBerry::BlackBerry(int weight):Berry(weight){
    this->inst = new OvalShaped(weight); //DELEGATION.
}
int BlackBerry::getType(){
    return BLACKBERRY;
}
string BlackBerry::printFruit(){
    return "Blackberry -> "+Berry::printFruit();
}

Apple::Apple(int weight):OvalShaped(weight){
}
int Apple::getType(){
    return APPLE;
}
string Apple::printFruit(){
    return "Apple ->"+OvalShaped::printFruit(); 
}

Orange::Orange(int weight):Fruit(weight), Citrus(true){
}
int Orange::getType(){
    return ORANGE;
}
string Orange::printFruit(){
    return "Orange -> "+Citrus::printCitrus()+" -> "+to_string(Fruit::getWeight());
}
bool Orange::isFruit(){
    return true;
}










