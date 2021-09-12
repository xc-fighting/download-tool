//problem for this solution
//not consider the time

struct cacheNode {
public:
    int key;
    int value;
    int count;
    int timestamp;
    cacheNode* prev;
    cacheNode* next;
    cacheNode(int key,int value,int timestamp) {
        this->key = key;
        this->value = value;
        this->count = 1;
        this->timestamp = timestamp;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

struct cacheList {
public:
    cacheNode* head;
    cacheNode* tail;
     
    int size;
    int capacity;
    cacheList(int capacity) {
       // cout<<"constructor is called"<<endl;
        this->capacity = capacity;
        this->size = 0;
        head = new cacheNode(-1,-1);
        tail = new cacheNode(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void unlink(cacheNode* node) {
        cacheNode* preNode = node->prev;
        cacheNode* nextNode = node->next;
        node->prev = nullptr;
        node->next = nullptr;
        size--;
        preNode->next = nextNode;
        nextNode->prev = preNode;
        return;
    }
    
    void prepend(cacheNode* node) {
        cacheNode* firstNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = firstNode;
        firstNode->prev = node;
        size++;
        return;
    }
    
    void insert(cacheNode* node,cacheNode* target) {
        cacheNode* preNode = target->prev;
        preNode->next = node;
        node->prev = preNode;
        node->next = target;
        target->prev = node;
        size++;
        return;
    }
    
    void append(cacheNode* node) {
        cacheNode* lastNode = tail->prev;
        lastNode->next = node;
        node->prev = lastNode;
        node->next = tail;
        tail->prev = node;
        size++;
        return;
    }
    
    bool isFull() {
        if(size == capacity) {
            return true;
        }
        return false;
    }
    bool isEmpty() {
        if(size==0) {
            return true;
        }
        return false;
    }
    cacheNode* getHead() {
        if(size == 0) {
            return nullptr;
        }
        return head->next;
    }
    
    cacheNode* getTail() {
        if(size == 0) {
            return nullptr;
        }
        return tail->prev;
    }
    
    
    
    
};
class LFUCache {
private:
    unordered_map<int,cacheNode*> keyMap;
    cacheList cache;
    int capacity;
    int timestamp;
public:
    LFUCache(int capacity):cache(capacity) {
        
        
        keyMap = unordered_map<int,cacheNode*>();
        this->capacity = capacity;
        this->timestamp = 0;
    }
    
    int get(int key) {
        
        this->timestamp++;
       
        if(capacity == 0 || keyMap.find(key) == keyMap.end()) {
            return -1;
        }
        cacheNode* entry = keyMap[key];
        int value = entry->value;
        cache.unlink(entry);
        entry->count++;
      //  cout<<"unlink:"<<entry->key<<endl;
        int freq = entry->count;
        cacheNode* current = cache.getHead();
        if(current == nullptr) {
            cache.prepend(entry);
        }
        else {
            while( current != cache.tail && freq < current->count ) {
               current = current->next;
            }
            cache.insert(entry,current);
        }
        
        return value;
    }
    
    void put(int key, int value) {
        this->timestamp++;
        if(capacity == 0) {
            return;
        }
        if(keyMap.find(key) == keyMap.end()) {
            
            cacheNode* newNode = new cacheNode(key,value,timestamp);
            
            if(cache.isFull()) {
                cacheNode* last = cache.getTail();
                int lastkey = last->key;
              //  cout<<key<<endl;
              //  cout<<"the last key is:"<<lastkey<<endl;
                keyMap.erase(lastkey);
                cache.unlink(last);
                delete last;
                
            }
            
            cache.append(newNode);
            keyMap[key] = newNode;
            
        }
        else {
            cacheNode* entry = keyMap[key];
            cache.unlink(entry);
            entry->count++;
            entry->value = value;
            int freq = entry->count;
            cacheNode* current = cache.getHead();
            if(current == nullptr) {
               cache.prepend(entry);
            }
            else {
               while( current != cache.tail && freq < current->count ) {
                   current = current->next;
               }
               cache.insert(entry,current);
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



//TLE solution:
//O(n) for average
//totally unacceptable
struct cacheNode {
public:
    int key;
    int value;
    int count;
    int timestamp;
    cacheNode* prev;
    cacheNode* next;
    cacheNode(int key,int value,int timestamp) {
        this->key = key;
        this->value = value;
        this->count = 1;
        this->timestamp = timestamp;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

struct cacheList {
public:
    cacheNode* head;
    cacheNode* tail;
     
    int size;
    int capacity;
    cacheList(int capacity) {
       // cout<<"constructor is called"<<endl;
        this->capacity = capacity;
        this->size = 0;
        head = new cacheNode(-1,-1,-1);
        tail = new cacheNode(-1,-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void unlink(cacheNode* node) {
        cacheNode* preNode = node->prev;
        cacheNode* nextNode = node->next;
        node->prev = nullptr;
        node->next = nullptr;
        size--;
        preNode->next = nextNode;
        nextNode->prev = preNode;
        return;
    }
    
    void prepend(cacheNode* node) {
        cacheNode* firstNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = firstNode;
        firstNode->prev = node;
        size++;
        return;
    }
    
    void insert(cacheNode* node,cacheNode* target) {
        cacheNode* preNode = target->prev;
        preNode->next = node;
        node->prev = preNode;
        node->next = target;
        target->prev = node;
        size++;
        return;
    }
    
    void append(cacheNode* node) {
        cacheNode* lastNode = tail->prev;
        lastNode->next = node;
        node->prev = lastNode;
        node->next = tail;
        tail->prev = node;
        size++;
        return;
    }
    
    bool isFull() {
        if(size == capacity) {
            return true;
        }
        return false;
    }
    bool isEmpty() {
        if(size==0) {
            return true;
        }
        return false;
    }
    cacheNode* getHead() {
        if(size == 0) {
            return nullptr;
        }
        return head->next;
    }
    
    cacheNode* getTail() {
        if(size == 0) {
            return nullptr;
        }
        return tail->prev;
    }
    
    
    
    
};
class LFUCache {
private:
    unordered_map<int,cacheNode*> keyMap;
    cacheList cache;
    int capacity;
    int timestamp;
public:
    LFUCache(int capacity):cache(capacity) {
        
        
        keyMap = unordered_map<int,cacheNode*>();
        this->capacity = capacity;
        this->timestamp = 0;
    }
    
    int get(int key) {
        
        this->timestamp++;
       
        if(capacity == 0 || keyMap.find(key) == keyMap.end()) {
            return -1;
        }
        cacheNode* entry = keyMap[key];
        int value = entry->value;
        cache.unlink(entry);
        entry->count++;
        entry->timestamp = timestamp;
      //  cout<<"unlink:"<<entry->key<<endl;
        int freq = entry->count;
        cacheNode* current = cache.getHead();
        if(current == nullptr) {
            cache.prepend(entry);
        }
        else {
            while( current != cache.tail && freq < current->count ) {
               current = current->next;
            }
            cache.insert(entry,current);
        }
        
        return value;
    }
    
    void put(int key, int value) {
        this->timestamp++;
        if(capacity == 0) {
            return;
        }
        if(keyMap.find(key) == keyMap.end()) {
            
            cacheNode* newNode = new cacheNode(key,value,timestamp);
            
            if(cache.isFull()) {
                cacheNode* last = cache.getTail();
                int lastkey = last->key;
                keyMap.erase(lastkey);
                cache.unlink(last);
                delete last;
                
            }
            cacheNode* realTail = cache.getTail();
            if(realTail == nullptr) {
                cache.prepend(newNode);
                keyMap[key] = newNode;
                return;
            }
            while(realTail != cache.head && realTail->count == 1) {
                realTail = realTail->prev;
            }
            
            cache.insert(newNode,realTail->next);
            keyMap[key] = newNode;
            return;
           
            
            
        }
        else {
            cacheNode* entry = keyMap[key];
            cache.unlink(entry);
            entry->count++;
            entry->value = value;
            int freq = entry->count;
            cacheNode* current = cache.getHead();
            if(current == nullptr) {
               cache.prepend(entry);
            }
            else {
               while( current != cache.tail && freq < current->count ) {
                   current = current->next;
               }
               cache.insert(entry,current);
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


//solution
struct cacheNode {
public:
    int key;
    int value;
    int count;
    cacheNode* prev;
    cacheNode* next;
    cacheNode(int key,int value) {
        this->key = key;
        this->value = value;
        this->count = 1;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

struct cacheList {
public:
    cacheNode* head;
    cacheNode* tail;
     
    int size;
    
    cacheList() {
       // cout<<"constructor is called"<<endl;
        
        this->size = 0;
        head = new cacheNode(-1,-1);
        tail = new cacheNode(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void unlink(cacheNode* node) {
        cacheNode* preNode = node->prev;
        cacheNode* nextNode = node->next;
        node->prev = nullptr;
        node->next = nullptr;
        size--;
        preNode->next = nextNode;
        nextNode->prev = preNode;
        return;
    }
    
    void prepend(cacheNode* node) {
        cacheNode* firstNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = firstNode;
        firstNode->prev = node;
        size++;
        return;
    }
    
    void insert(cacheNode* node,cacheNode* target) {
        cacheNode* preNode = target->prev;
        preNode->next = node;
        node->prev = preNode;
        node->next = target;
        target->prev = node;
        size++;
        return;
    }
    
    void append(cacheNode* node) {
        cacheNode* lastNode = tail->prev;
        lastNode->next = node;
        node->prev = lastNode;
        node->next = tail;
        tail->prev = node;
        size++;
        return;
    }
    
   
    bool isEmpty() {
        if(size==0) {
            return true;
        }
        return false;
    }
    cacheNode* getHead() {
        if(size == 0) {
            return nullptr;
        }
        return head->next;
    }
    
    cacheNode* getTail() {
        if(size == 0) {
            return nullptr;
        }
        return tail->prev;
    }
    
    
    
    
};
class LFUCache {
private:
    unordered_map<int,cacheNode*> keyNodeMap;
    unordered_map<int,cacheList*> keyListMap;
    unordered_map<int,cacheList*> freqListMap;
    int capacity;
    int curSize;
    int minFreq;
public:
    LFUCache(int capacity) {
        
        keyNodeMap = unordered_map<int,cacheNode*>();
        keyListMap = unordered_map<int,cacheList*>();
        freqListMap = unordered_map<int,cacheList*>();
        this->capacity = capacity;
        this->curSize = 0;
        this->minFreq = -1;
    }
    
    void updateMinFreq(int freq) {
        if(minFreq == -1) {
            minFreq = freq;
        }
        else {
            minFreq = min(minFreq,freq);
        }
        return;
    }
    
    void resetMinFreq(int freq) {
        if(minFreq == freq) {
            minFreq = -1;
        }
        
    }
    
    int get(int key) {
        if(capacity==0) {
            return -1;
        }
        //no key, return -1
        if(keyNodeMap.find(key) == keyNodeMap.end()) {
            return -1;
        }
        // get the node
        cacheNode* node = keyNodeMap[key];
        
        updateMinFreq(node->count);
        
        // get the list the node in
        cacheList* nodelist = keyListMap[key];
        // unlink the node
        nodelist->unlink(node);
        // if nothing in the list
        // delete that entry for saving space
        if(nodelist->isEmpty()==true) {
            freqListMap.erase(node->count);
            resetMinFreq(node->count);
        }
        //add the frequency
        node->count++;
        int freq = node->count;
        updateMinFreq(freq);
       
        if(freqListMap.find(freq) == freqListMap.end()) {
            freqListMap[freq] = new cacheList();
            
        }
        // append the node and return
        keyListMap[key] = freqListMap[freq];
        freqListMap[freq]->append(node);
        return node->value;
       
    }
    
    void put(int key, int value) {
        if(capacity == 0) {
            return;
        }
        //first check whether key there, if exist, update the value, freq
        if(keyNodeMap.find(key) != keyNodeMap.end()) {
             // get the node
             cacheNode* node = keyNodeMap[key];
             //update
             updateMinFreq(node->count);
             // get the list the node in
             cacheList* nodelist = keyListMap[key];
             // unlink the node
             nodelist->unlink(node);
             // if nothing in the list
             // delete that entry for saving space
             if(nodelist->isEmpty()==true) {
                 freqListMap.erase(node->count);
                 resetMinFreq(node->count);
             }
             //add the frequency
             node->count++;
             node->value = value;
             int freq = node->count;
            
             updateMinFreq(freq);
            
             if(freqListMap.find(freq) == freqListMap.end()) {
                 freqListMap[freq] = new cacheList();
            
             }
             // append the node and return
             keyListMap[key] = freqListMap[freq];
             freqListMap[freq]->append(node);
             return;
        }

        if(curSize == capacity) {
            
            //get min freq list
            cacheList* minlist = freqListMap[minFreq];
            cacheNode* delNode = minlist->getHead();
            minlist->unlink(delNode);
            keyNodeMap.erase(delNode->key);
            keyListMap.erase(delNode->key);
            if(minlist->isEmpty()) {
                
                freqListMap.erase(minFreq);
                minFreq = -1;
            }
            curSize--;
            
        }
        
        cacheNode* newNode = new cacheNode(key,value);
        if(freqListMap.find(1) == freqListMap.end()) {
            freqListMap[1] = new cacheList();
        }
        freqListMap[1]->append(newNode);
        minFreq = 1;
        keyNodeMap[key] = newNode;
        keyListMap[key] = freqListMap[1];
        curSize++;
        return;  
        
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */