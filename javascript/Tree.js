const OVAL_SHAPED = 1
const BERRY = 2
const BLACKBERRY = 20
const APPLE = 10


export class Fruit {

    constructor(weight) {
        this.weight = weight;
        this.type = 0;
    }

    getType() {
        console.log('Fruit Called');
        return this.type;
    }
}

export class OvalShaped extends Fruit {

    constructor(weight) {
        super(weight);
        this.type = OVAL_SHAPED;
    }

    getType() {
        console.log('Oval Called');
        return this.type;
    }
}
export class Berry extends Fruit {

    constructor(weight) {
        super(weight);
        this.type = BERRY;
    }

    getType() {
        console.log('Berry Called');
        return this.type;
    }


}

export class BlackBerry extends Berry {
    constructor(weight) {
        super(weight);
        this.type = BLACKBERRY;
    }

    getType() {
        console.log('Blackberry Called');

        return this.type;
    }
}

export class Apple extends OvalShaped {
    constructor(weight) {
        super(weight);
        this.type = APPLE;
    }

    getType() {
        console.log('Apple Called');
        return this.type;
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Tree {

    constructor() {
        this.root = null;
    }
    add(fruit) {
        if (fruit === null) {
            console.log('Fruit is null!');
            return;
        }
        if (this.root === null) {
            this.root = new Node(fruit);
            return;
        }
        this.root.add(fruit)
    }
    Iterate() {
        if (this.root !== null)
            this.root.order((node) => console.log(node.fruit.weight));
    }
    filterByType(type) {
        this.root.order(this.filterType, type);
    }

    magnifyByType(type, weight) {
        let x = function(node) {
            if (node.fruit.getType() === arguments[1]) {
                node.fruit.weight += arguments[2];
            }
        }
        this.root.order(x, type, weight);
    }

    filterByWeight(weight) {
        let list = this.inOrderTraverse(weight);
        let listA = []
        for (let i of list) {
            if (i.weight > weight)
                listA.push(i);
        }
        return listA;
    }
    findHeaviest() {
        let list = this.inOrderTraverse();
        return list[list.length - 1];
    }
    findLightest() {
        let list = this.inOrderTraverse();
        return list[0];
    }

    inOrderTraverse() {
        let list = [];
        let x = function(node, list) {
            list.push(node.fruit);
        };
        this.root.order(x, list);
        return list;
    }

    filterType(node, type) {
        if (node.fruit.getType() === type)
            console.log(node.fruit.weight);
    }
}

class Node {

    constructor(fruit) {
        this.fruit = fruit;
        this.left = null;
        this.right = null;
    }

    add(fruit) {
        let value = fruit.weight;
        if (value < this.fruit.weight) {
            if (this.left !== null)
                this.left.add(fruit);
            else
                this.left = new Node(fruit);
            return;
        }
        if (this.right !== null)
            this.right.add(fruit);
        else
            this.right = new Node(fruit);
    }

    order(f, args1, args2) {
        if (this.left !== null)
            this.left.order(f, args1, args2);
        f(this, args1, args2);
        if (this.right !== null)
            this.right.order(f, args1, args2);
    }
}


let X = new Tree();
let apple1 = new Apple(10);
let blackBerry1 = new BlackBerry(25);
let apple2 = new Apple(30);
let berry1 = new Berry(200);

X.add(apple1);
X.add(blackBerry1);
X.add(apple2);
X.add(berry1);
X.Iterate();
console.log("-----------------------")
X.filterByType(APPLE);

console.log(X.findHeaviest().weight)
console.log(X.findLightest().weight)

X.magnifyByType(APPLE, 500);
console.log('----------')
X.Iterate();
console.log('----------------------')
console.log(X.filterByWeight(30));