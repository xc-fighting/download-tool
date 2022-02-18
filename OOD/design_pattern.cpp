#include <iostream>
#include <string>

using namespace std;
/*
  basic knowledge
*/
class Base {
public:
	Base() {
		cout<<"base constructor"<<endl;
	}

	virtual ~Base() {
		cout<<"destroy base"<<endl;
	}

	virtual void functest() {
		cout<<"this is base"<<endl;
		return;
	}

	virtual int getVal() = 0;
};

class Child: public Base {
public:
	Child() {
		cout<<"child contructor"<<endl;
	}

	~Child() {
		cout<<"destroy child"<<endl;
	}

	void functest() {
		cout<<"override function"<<endl;
		return;
	}

	int getVal() {
		return 0;
	}
};

/*
  Singleton pattern

*/

class Singleton {
private:

	Singleton() {
       cout<<"should only called once"<<endl;
	}

  
    static Singleton* instance;
public:

	

	static Singleton* getInstance() {
        if(instance != nullptr) {
        	cout<<"return here"<<endl;
        	return instance;
        }
        instance = new Singleton();
	}
};


Singleton* Singleton::instance = nullptr;


/*
  factory pattern
*/
class Button {
public:
	Button() {

	}

	virtual void render() = 0;
	virtual void onClick() = 0;
};

class WindowsButton: public Button {
public:
	WindowsButton() {

	}

	void render() {
		cout<<"redner a windows button"<<endl;
	}

	void onClick() {
		cout<<"click on windows button"<<endl;
	}
};

class Diaglog {
private:
	Button* button;
public:

	Diaglog() {

	}

	void render() {
       button = createButton();
       button->onClick();
       button->render();
	}

	virtual Button* createButton() = 0; 

};

class WindowsDiaglog: public Diaglog {
public:
	WindowsDiaglog() {

	}

	Button* createButton() {
		return new WindowsButton();
	}

};

/*
decorator pattern
I don't like this pattern actually
*/

class Coffee {
public:
	Coffee() {

	}

	virtual ~Coffee() {
		cout<<"destroy coffee"<<endl;
	}

	virtual int getCost() = 0;
};

class Expresso: public Coffee {
public:
	Expresso() {

	}

	~Expresso() {
		cout<<"destroy expresso"<<endl;
	}

	int getCost() {
		return 3;
	}
};

class CoffeeDecorator: public Coffee {
protected:
	Coffee* baseCoffee;
public:
	CoffeeDecorator(Coffee* other) {
		this->baseCoffee = other;
	}
    
    virtual ~CoffeeDecorator() {
    	cout<<"destroy CoffeeDecorator"<<endl;
        //put the delete operation here
    	delete baseCoffee;
    }

	virtual int getCost() {
		return baseCoffee->getCost();
	}


};

class AddMilk: public CoffeeDecorator {

public:
    AddMilk(Coffee* other):CoffeeDecorator(other) {

    }
    
    ~AddMilk() {
    	cout<<"destroy add milk"<<endl;
    	

    }

    int getCost() {
    	int basePrice = this->baseCoffee->getCost();
    	return basePrice + 1;
    }
};

class AddMocha: public CoffeeDecorator {
public:
	AddMocha(Coffee* other): CoffeeDecorator(other) {

	}

	~AddMocha() {
		cout<<"destroy add mocha"<<endl;
		
	}

	int getCost() {
		int basePrice = this->baseCoffee->getCost();
		return 2 + basePrice;
	}
};



int main() {
   Base* instance = new Child();
   instance->functest();
   delete instance;

   Singleton* test = Singleton::getInstance();
   Singleton* test2 = Singleton::getInstance();

   Diaglog* diag = new WindowsDiaglog();
   diag->render();

   delete diag;

   Coffee* coffee = new Expresso();
   cout<<"expresso price:"<<coffee->getCost()<<endl;

   coffee = new AddMilk(coffee);
   cout<<"expresso add milk price:"<<coffee->getCost()<<endl;

   coffee = new AddMocha(coffee);
   cout<<"expresso add milk and mocha price:"<<coffee->getCost()<<endl;

   delete coffee;

}