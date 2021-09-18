#include <iostream>

using namespace std;

class Coffee {
public:
	virtual float cost() = 0;
	virtual string getDescription() = 0;
};

class CoffeeDecorator:public Coffee {

public:
	Coffee* coffee;
};

class addMilk:public CoffeeDecorator {
public:
   addMilk(Coffee* other) {
   	  this->coffee = other;
   }
   float cost() {
   	  return coffee->cost() + 0.5f;
   }
   string getDescription() {
   	  return coffee->getDescription()+",add milk";
   }
};

class Mocha:public CoffeeDecorator {
public:
   Mocha(Coffee* other) {
   	  this->coffee = other;
   }
   float cost() {
   	  return coffee->cost() + 0.4f;
   }
   string getDescription() {
   	  return coffee->getDescription() +",add mocha";
   }
};

class Decaf:public Coffee {
public:
   string getDescription() {
   	   return "Decaf";
   }
   float cost() {
       return 4.5f;
   }
};

class Expresso:public Coffee {
public:
   string getDescription() {
   	   return "Expresso";
   }
   float cost() {
   	  return 2.5f;
   }
};

int main() {
   Coffee* expresso = new Expresso();
   Coffee* milkExpresso = new addMilk(expresso);
   cout<<milkExpresso->getDescription()<<endl;
   cout<<milkExpresso->cost()<<endl;
   return 0;
}