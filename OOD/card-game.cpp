#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum COLOR {
   BLACK,
   BLUE,
   GREEN,
   WHITE
};

class Money {
private:
	COLOR color;
	int value;
public:
	Money(COLOR c, int v) {
		this->color = c;
		this->value = v;
	}

	int getValue() {
		return this->value;
	}

	void setValue(int v) {
		this->value = v;
	}

	COLOR getColor() {
		return this->color;
	}

	void setColor(COLOR c) {
		this->color = c;
	}


};

class Card {
private: 
	int moneyRequired;

	bool canPurchaseHelper(vector<Money>& moneys, int curIdx, int requiredRemain) {
         if(curIdx == moneys.size()) {
         	if(requiredRemain == 0) {
         		return true;
         	}
         	return false;
         }

         int curVal = moneys[curIdx].getValue();
         if(requiredRemain >= curVal) {
         	 bool use = canPurchaseHelper(moneys, curIdx+1, requiredRemain - curVal);
         	 if(use) {
         	 	return true;
         	 }
         }

         bool notUse = canPurchaseHelper(moneys, curIdx+1, requiredRemain);
         if(notUse) {
         	return true;
         }
         return false;
	}

public:
	Card(int m) {
		this->moneyRequired = m;
	}
    

	bool canPurchase(vector<Money>& moneys) {
        return canPurchaseHelper(moneys, 0, this->moneyRequired);
	}
};


class CardGame {
private:
	vector<Card> cards;
	vector<Money> moneys;
public:
	CardGame() {
       cards = vector<Card>();
       moneys = vector<Money>();
	}

    void addCard(int required) {
    	cards.push_back(Card(required));
    }

    void addMoney(COLOR c, int v) {
    	moneys.push_back(Money(c,v));
    }


    

};

int main() {

}