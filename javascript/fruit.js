class Fruit {

    constructor(weight) {
        this.weight = weight;
    }

    getType(fun) {
        return fun();
    }
}

class Apple extends Fruit {

    constructor(weight) {
        super(weight);
        this.type = 'Apple';
    }

    getType() {
        return super(this.get_type);
    }

    get_type() {
        return this.type;
    }
}