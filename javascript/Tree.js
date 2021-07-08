const OVAL_SHAPED = 1
const BERRY = 2
const BLACKBERRY = 20
const APPLE = 10


let Fruit = {

    weight: 0,
    type: 0,
    getType() {
        // console.log('Fruit Called');
        return this.type;
    },
    setWeight(weight) {
        this.weight = weight;
    }
};

let OvalShaped = {
    __proto__: Fruit,
    type: OVAL_SHAPED,
    // constructor(weight) {
    //     super(weight);
    //     this.type = OVAL_SHAPED;
    // },

}
let Berry = {
    __proto__: Fruit,
    type: BERRY,
}

let BlackBerry = {
    __proto__: Berry,
    type: BLACKBERRY,
}

let Apple = {
        __proto__: OvalShaped,
        type: APPLE,
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////

let Tree = {
    root: null,

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
    },
    Iterate() {
        if (this.root !== null)
            this.root.order((node) => console.log(node.fruit.weight));
    },
    filterByType(type) {
        this.root.order(this.filterType, type);
    },

    magnifyByType(type, weight) {
        let x = function(node) {
            if (node.fruit.getType() === arguments[1]) {
                node.fruit.weight += arguments[2];
            }
        }

        this.root.order(x, type, weight);
        let list = this.inOrderTraverse();
        this.root = null;
        for (let i = 0; i < list.length; i++)
            this.add(list[i]);
    },

    filterByWeight(weight) {
        let list = this.inOrderTraverse(weight);
        let listA = []
        for (let i of list) {
            if (i.weight > weight)
                listA.push(i);
        }
        return listA;
    },
    findHeaviest() {
        let list = this.inOrderTraverse();
        return list[list.length - 1];
    },
    findLightest() {
        let list = this.inOrderTraverse();
        return list[0];
    },

    inOrderTraverse() {
        let list = [];
        let x = function(node, list) {
            list.push(node.fruit);
        };
        this.root.order(x, list);
        return list;
    },

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


let X = Object.create(Tree);

let apple1 = Object.create(Apple);
apple1.setWeight(10);

let blackBerry1 = Object.create(BlackBerry);
blackBerry1.setWeight(25);

let apple2 = Object.create(Apple);
apple2.setWeight(30);

let berry1 = Object.create(Berry);
berry1.setWeight(200);

X.add(apple1);
X.add(blackBerry1);
X.add(apple2);
X.add(berry1);
X.Iterate();
console.log("-----------------------")
X.filterByType(APPLE);
console.log('////////////////')
console.log(X.findHeaviest().weight)
console.log(X.findLightest().weight)
console.log('//////////////////')
X.magnifyByType(APPLE, 500);
console.log('----------')
X.Iterate();
console.log('----------------------')
console.log(X.filterByWeight(30));