#include<iostream>


#define OVAL_SHAPED 1
#define BERRY 2
#define BLACKBERRY 20
#define APPLE 10
#define CITRUS 3
#define ORANGE 30

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
        virtual string printFruit() = 0;
};

class OvalShaped : public Fruit{

    public:
        OvalShaped(int weight);
        void setWeight(int weight);
        virtual int getType();
        string printFruit();
};

class Berry :  public Fruit{

    public:
        Berry(int weight);
        void setWeight(int weight);
        int getType();
        string printFruit();
};

class Citrus {
    private :
        bool isFruitt;
    public :
        Citrus(bool isFruit);
        virtual bool isFruit() =0; 
        string printCitrus();   
};

class BlackBerry : public Berry {

    public :
        BlackBerry(int weight);
        int getType();
        string printFruit();
    private:
        OvalShaped  *inst;
};

class Apple: public OvalShaped{
    public :
        Apple(int weight);
        int getType();
        string printFruit();
};

class Orange: public Fruit , public Citrus{
    public:
        Orange(int weight);
        int getType();
        string printFruit();
        bool isFruit();
};






