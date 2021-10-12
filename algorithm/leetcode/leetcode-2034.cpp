class StockPrice {
private:
    map<int,int> priceFreq;
    map<int,int> timePrice;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(timePrice.find(timestamp) != timePrice.end()) {
            int prevPrice = timePrice[timestamp];
            priceFreq[prevPrice]--;
            if(priceFreq[prevPrice] == 0) {
                priceFreq.erase(prevPrice);
            }
        }
        timePrice[timestamp] = price;
        if(priceFreq.find(price) == priceFreq.end()) {
            priceFreq[price] = 0;
        }
        priceFreq[price]++;
    }
    
    int current() {
        auto itr = timePrice.end();
        itr--;
        return itr->second;
    }
    
    int maximum() {
         auto itr = priceFreq.end();
         itr--;
        return itr->first;
    }
    
    int minimum() {
         auto itr = priceFreq.begin();
        
        return itr->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */