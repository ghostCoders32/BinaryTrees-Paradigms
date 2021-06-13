const OVAL_SHAPED = 1
const BERRY = 2
const BLACKBERRY = 20
const APPLE = 10


class Fruit {

    constructor(weight) {
        this.weight = weight;
    }

    getType(fun) {
        return fun();
    }
}

class OvalShaped extends Fruit {

    constructor(weight) {
        super(weight);
        this.type = 'OvalShaped';
    }

    getType() {
        // @ts-ignore
        return super(this.get_type);
    }

    get_type() {
        return this.type;
    }
}
class Berry extends Fruit {

    constructor(weight) {
        super(weight);
        this.type = 'Berry';
    }

    getType() {
        // @ts-ignore
        return super(this.get_type);
    }

    get_type() {
        return this.type;
    }
}

class BlackBerry extends Berry {
    constructor(weight) {
        super(weight);
        this.type = 'BlackBerry';
    }

    getType() {
        // @ts-ignore
        return super(this.get_type);
    }

    get_type() {
        return this.type;
    }
}

class Apple extends OvalShaped {
    constructor(weight) {
        super(weight);
        this.type = 'Apple';
    }

    getType() {
        // @ts-ignore
        return super(this.get_type);
    }

    get_type() {
        return this.type;
    }
}
class Tree {

    constructor() {
        this.root = null;
        this.list = new Array();
    }
    add(fruit) {
            if (fruit === null) {
                console.log('Fruit is null!');
                return;
            }
            if (root === null) {
                this.root = new Node(fruit);
                return;
            }
            this.root.add(fruit)
            this.list.push(fruit);
        }
        // magnifyByType(Type, Weight): a method that increases the weight of the nodes of a given fruit type by the given amount. For example, add 200 grams to all bananas in the tree.


    getSorted() {
        this.root.append(list);
    }

    Iterate() {
        if (this.root !== null)
            this.root.order(x => console.log(this.fruit.weight));
    }
    filterByType(type) {
        this.root.order(this.filterType, type);
    }

    filterByWeight(weight) {
        this.list = this.inOrderTraverse(weight);
        let list = []
        for (let i of list) {
            if (i.weight > weight)
                list.push(i);
        }
        return list;
    }
    findHeaviest() {
        this.list = this.inOrderTraverse(weight);
        return this.list[this.list.length - 1];
    }
    findLightest() {
        this.list = this.inOrderTraverse(weight);
        return this.list[0];
    }
    inOrderTraverse() {
        list = [];
        let x = function(list) {
            list.push(this.fruit);
        };
        this.order(x, list);
        return this.list;
    }

    filterType(type) {
        if (this.fruit.getType() === type)
            console.log(this.fruit.weight);
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

    order(f, args) {
        if (this.left !== null)
            this.left.order(f, args);
        f(args);
        if (this.right !== null)
            this.right.order(f, args);
    }
}


let X = new Tree();