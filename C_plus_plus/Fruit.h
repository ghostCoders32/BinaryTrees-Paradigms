#include<iostream>


#define OVAL_SHAPED 1
#define BERRY 2
#define BLACKBERRY 20
#define APPLE 10

using namespace std;

class Fruit{
    private:
        int weight;
    public:
        Fruit(int weight);
        int getWeight();
        void setWeight(int weight);
        void magnifyWeight(int addition);
        virtual int getType() = 0;   
        virtual void printFruit() = 0;
};

class OvalShaped : public Fruit{

    public:
        OvalShaped(int weight);
        void setWeight(int weight);
        virtual int getType();
        void printFruit();
};

class Berry :  public Fruit{

    public:
        Berry(int weight);
        void setWeight(int weight);
        int getType();
        void printFruit();
};

class BlackBerry : public Berry {

    public :
        BlackBerry(int weight);
        int getType();
        void printFruit();
    private:
        OvalShaped  *inst;
};

class Apple: public OvalShaped{
    public :
        Apple(int weight);
        int getType();
        void printFruit();
};




