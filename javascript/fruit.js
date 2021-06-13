const OVAL_SHAPED = 1
const BERRY = 2
const BLACKBERRY = 20
const APPLE = 10


export class Fruit {

    constructor(weight) {
        this.weight = weight;
    }

    getType(fun) {
        return fun();
    }
}

export class OvalShaped extends Fruit {

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
export class Berry extends Fruit {

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

export class BlackBerry extends Berry {
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

export class Apple extends OvalShaped {
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