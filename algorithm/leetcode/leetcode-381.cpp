//this one need to summarize, too many possible problems

class RandomizedCollection {
private:
    
    vector<int> dataSet;
    
    unordered_map<int,unordered_set<int>> numIndexMap;
    
    int curSize;
    
public:
    RandomizedCollection() {
        this->curSize = 0;
        //this function should be called only once
        srand(time(NULL));
    }

    //debugging function
    void print() {
        for( int index = 0; index < curSize; index++) {
            cout<<dataSet[index]<<" ";
        }
        cout<<endl;
    }
    
    bool insert(int val) {
    //    cout<<"insert:"<<val<<endl;
     //   print();
        // this is a critical part easy to make mistake
        // understand when to push_back, when to use existing position is important
        if( this->curSize == dataSet.size() ) {
            dataSet.push_back(val);
        }
        else {
            dataSet[curSize] = val;
        }
        bool flag = false;
        if( numIndexMap.find(val) == numIndexMap.end() ) {
           // dataSet.push_back(val);
            numIndexMap[val] = unordered_set<int>();
            flag = true;
        }
         numIndexMap[val].insert(curSize);
        
         this->curSize++;
        // cout<<"after insert"<<endl;
      //   print();
         return flag;
    }
    
    bool remove(int val) {
        // val can not find
      //  cout<<"remove value:"<<val<<endl;
        if( numIndexMap.find(val) == numIndexMap.end() ) {
            return false;
        }
        // do not use indexSet, any changes in that will not reflect back to numIndexMap, it is not java
        // unless use reference in c++
        unordered_set<int> indexSet = numIndexMap[val];
        auto itr = numIndexMap[val].begin();
        int index = *itr;
        //small trick here to remove
        numIndexMap[val].erase(numIndexMap[val].begin());
        if( numIndexMap[val].size() == 0 ) {
        //    cout<<"erase"<<endl;
            numIndexMap.erase(val);
        }
        
        if( index == curSize - 1 ) {
            curSize--;
      //      cout<<"after remove one"<<endl;
      //      print();
            return true;
        }
        
        int lastElem = dataSet[curSize - 1];
    //    cout<<"replace index:"<<index<<endl;
        dataSet[index] = lastElem;
        numIndexMap[lastElem].erase(curSize-1);
        numIndexMap[lastElem].insert(index);
        curSize--;
     //   cout<<"after remove two"<<endl;
      //  print();
        return true;
    }
    
    int getRandom() {
        
        
        int index = rand() % curSize;
      //  cout<<curSize<<" "<<index<<endl;
        return dataSet[index];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */