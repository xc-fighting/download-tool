struct cacheNode {
public:
    int key;
    int value;
    cacheNode* prev;
    cacheNode* next;
    cacheNode(int k,int v) {
        this->key = k;
        this->value = v;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

struct linkList {
public:
    cacheNode* head;
    cacheNode* tail;
    int capacity;
    int size;
    linkList(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        head = new cacheNode(-1,-1);
        tail = new cacheNode(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    bool isEmpty() {
        if(size == 0) {
            return true;
        }
        return false;
    }
    bool isFull() {
        if(size == capacity) {
            return true;
        }
        return false;
    }
    
    void append(cacheNode* node) {
        cacheNode* last = tail->prev;
        last->next = node;
        node->prev = last;
        node->next = tail;
        tail->prev = node;
        size++;
        return;
    }
    
    void unlink(cacheNode* node) {
        cacheNode* prevNode = node->prev;
        cacheNode* nextNode = node->next;
        node->prev = nullptr;
        node->next = nullptr;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
        return;
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
class LRUCache {
private:
    unordered_map<int,cacheNode*> keyNodeMap;
    linkList nodelist;
    int capacity;
public:
    LRUCache(int capacity): nodelist(capacity) {
        this->capacity = capacity;
        keyNodeMap = unordered_map<int,cacheNode*>();
    }
    
    int get(int key) {
        if(keyNodeMap.find(key) == keyNodeMap.end()) {
            return -1;
        }
        cacheNode* target = keyNodeMap[key];
        int ret = target->value;
        nodelist.unlink(target);
        nodelist.append(target);
        return ret;
    }
    
    void put(int key, int value) {
        //key present
        if(keyNodeMap.find(key) != keyNodeMap.end()) {
            cacheNode* target = keyNodeMap[key];
            // value update
            target->value = value;
            // newest operation, append to end of list
            nodelist.unlink(target);
            nodelist.append(target);
            return;
        }
        else {
            //new key, insert
            cacheNode* newNode = new cacheNode(key,value);
            if(nodelist.isFull() == true) {
            //    cout<<key<<value<<endl;
                //evict the first element from nodelist
                cacheNode* head = nodelist.getHead();
                int headKey = head->key;
              //  cout<<headKey<<endl;
                //delete the entry from keynode map
                keyNodeMap.erase(headKey);
                nodelist.unlink(head);
                //delete head;
            }
            //append it to list
            nodelist.append(newNode);
            //update the keyNodeMap
            keyNodeMap[key] = newNode;
            return;
            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */