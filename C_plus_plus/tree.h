#include "Fruit.h"
#include <vector>

class BinaryTree{

    private:

        BinaryTree *left;
        BinaryTree *right;

        Fruit* fruit;

        void magnifyOnly(int type , int weight);
        void addNode(vector<Fruit*>* vec);

    public:
        BinaryTree(Fruit* fruit);
        bool contains(Fruit* fruit);
        void add(Fruit* fruit);

        Fruit* getFruit();
        BinaryTree* getLeft();
        BinaryTree* getRight();

        void Iterate();  //a method that prints the in-order traversal of the tree.
        void filterByType(int type); //a method that prints the nodes of a given fruit type ordered by. weight. For example, get an ordered list of all apples in the tree
        void filterByWeight(int weight);// a method that prints the nodes that have weight larger than the given amount ordered by wright. For example, get an ordered list of all fruits in the tree that are heavier than 500 grams.
        void magnifyByType(int type, int weight);// a method that increases the weight of the nodes of a given fruit type by the given amount. For example, add 200 grams to all bananas in the tree.
        Fruit* findHeaviest();  //a method that finds the node with the greatest weight in the tree. 
        Fruit* findLightest();  //a method that finds the node with the least weight in the tree
        
};