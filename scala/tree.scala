import scala.collection.mutable.ListBuffer

object Types{

  val APPLE:String = "Apple"
  val BERRY = "Berry"
  val BLACKBERRY = "Blackberry"
  val OVALSHAPED ="OvalShaped"

// #define BLACKBERRY 20
// #define APPLE 10
// #define CITRUS 3
// #define ORANGE 30



}
object Main{

  def main(args: Array[String]) :Unit = {
  print("HELLO WORLD")
  val tree:Tree = new Tree()
  val apple1 = new Apple(10)
  val apple2 = new Apple(5)
  val apple3 = new Apple(15)
  val apple4 = new Apple(0)  
  val apple5 = new Apple(20)

  tree.add(apple1);
  tree.add(apple2);
  tree.add(apple3);
  tree.add(apple4);
  tree.add(apple5);

  val berry1 = new Berry(1000)
  val blackBerry1 = new BlackBerry(-1000)
  val berry2 = new Berry(500)
  val blackBerry2 = new BlackBerry(750)
  val berry3 = new Berry(-500)
  val blackBerry3 = new BlackBerry(100000)
  val berry4 = new Berry(999)
  val blackBerry4 = new BlackBerry(870)
  val berry5 = new Berry(-850)
  val blackBerry5 = new BlackBerry(150)


  tree add berry1
  tree add berry2
  tree add berry3
  tree add berry4
  tree add berry5
  
  tree add blackBerry1
  tree add blackBerry2
  tree add blackBerry3
  tree add blackBerry4
  tree add blackBerry5
  
  tree.Iterate()
  println("-----------")
  tree.filterByType(Types.APPLE)
  println("-------------")
  tree.filterByWeight(500)
  println("-------------")

  tree.findHeaviest()
  tree.findLightest()
  print("---------------?---")
  tree.magnifyByWeight(Types.APPLE , 630)
  }
}

class Tree{
  
var root:Node = null

  def add(fruit:Fruit):Unit = {
    if (root == null){
      root = new Node(fruit , null , null)
      return
    }
    root.add(fruit)
  }

  def Iterate():Unit = {
    var list = new ListBuffer[Fruit]() 
    list = root.orderTraversal(list)
    list foreach((x:Fruit)=>x.printFruit())
  }

  def filterByType(fruitType:String):Unit = {
    var list = new ListBuffer[Fruit]() 
    list = root.orderTraversal(list)

    // val list2:ListBuffer[Fruit] = list.filter((x:Fruit) => x.getType == fruitType)
    // list2 foreach((x:Fruit)=>x.printFruit())

    def fun(x:Fruit):Unit = x.getType match {
      case `fruitType` => x.printFruit()
      case _ =>return
    }
    list foreach(fun)
  }

  def filterByWeight(weight:Int):Unit = {

    var list = new ListBuffer[Fruit]() 
    list = root.orderTraversal(list)
    val list2:ListBuffer[Fruit] =list.filter(x=>x.getWeight >= weight)
    list2 foreach (x =>x.printFruit())
  }

  def findHeaviest():Unit = {
    var list = new ListBuffer[Fruit]() 
    list = root.orderTraversal(list)
    list.last.printFruit()    
  }
  def findLightest():Unit={
    var list = new ListBuffer[Fruit]() 
    list = root.orderTraversal(list)
    list.head.printFruit()  
  }

  def magnifyByWeight(fruitType:String,weight:Int):Unit ={
    var list = new ListBuffer[Fruit]() 
    list = root.orderTraversal(list)

    list.filter((x:Fruit) => x.getType == fruitType).foreach((x:Fruit)=>x.setWeight(x.getWeight+weight))
    root = null
    list.foreach(add)
    println("/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\")
    Iterate()
  }

  class Node(var fruit:Fruit ,  var left:Node , var right:Node){

      def this(fruit:Fruit){
        this(fruit,null,null)
      }

      def add(x:Fruit):Unit = {
        val value = x.getWeight
        if(fruit.getWeight > value){//right
          if(right == null)
            right = new Node(x)
          else
            right.add(x)  
        }
        else{//left
            if(left == null)
              left = new Node(x)
            else
              left.add(x)  
        }
      }

      def orderTraversal(list:ListBuffer[Fruit]):ListBuffer[Fruit] ={
        if(right != null)
              right.orderTraversal(list)
        list+=fruit
        if(left != null)
              left.orderTraversal(list)
        list      
      }
  }
}


abstract class Fruit (var weight:Int){

  println("Fruit Constructor called!")

  def getWeight = weight
  def setWeight(x:Int):Unit={weight = x}

  def printFruit():Unit
  def getType():String
}

class OvalShaped(weight:Int) extends Fruit(weight){
  println("OvalShaped Constructor called!")
  
  override def setWeight(x:Int):Unit = {
    println("Set Weight Override!!!")
    super.setWeight(x)
  }

  override def printFruit(): Unit = {
    println("OvalShaped fruit!!")
  }
  override def getType() = Types.OVALSHAPED
}


class Berry(weight:Int) extends Fruit(weight){
  println("Berry Constructor called!")

  override def printFruit(): Unit = {
    println(s"Berry fruit of weight: ${getWeight}")
  }
   override def getType():String={
    Types.BERRY
  }

}
class Apple(weight:Int) extends OvalShaped(weight){

      override def printFruit(): Unit = {
        println(s"This is Apple of weight : ${getWeight}")
        
      }
      override def getType():String = Types.APPLE
}

class BlackBerry(weight:Int) extends  Berry(weight) {
      println("BlackBerry Constructor called!")
      private val oval:OvalShaped = new OvalShaped (weight)

       override def printFruit(): Unit = {
        println(s"This is BlackBerry of weight : ${getWeight}")
        }
      override def getType():String = Types.BLACKBERRY
};



/**


class Citrus {
    private :
        bool isFruitt;
    public :
        Citrus(bool isFruit);
        virtual bool isFruit() =0; 
        void printCitrus();   
};

class Orange: public Fruit , public Citrus{
    public:
        Orange(int weight);
        int getType();
        void printFruit();
        bool isFruit();
};







  */