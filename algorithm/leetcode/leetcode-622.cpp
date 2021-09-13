struct Node {
public:
    int val;
    Node* next;
    Node(int v) {
        this->val = v;
        this->next = nullptr;
    }
};
class MyCircularQueue {
private:
    int capacity;
    int curSize;
    Node* front;
    Node* rear;
public:
    MyCircularQueue(int k) {
        this->capacity = k;
        this->curSize = 0;
        this->front = nullptr;
        this->rear = nullptr;
    }
    
    bool enQueue(int value) {
        if(curSize == capacity) {
            return false;
        }
        Node* newNode = new Node(value);
        if(rear == nullptr) {
            front = newNode;
            rear = newNode;
            rear->next = front;
        }
        else {
            rear->next = newNode;
            rear = rear->next;
            rear->next = front;
        }
        this->curSize++;
        return true;
    }
    
    bool deQueue() {
        if(front==nullptr) {
            return false;
        }
        if(front == rear) {
            front = nullptr;
            rear = nullptr;
            curSize--;
            return true;
        }
        Node* nextFront = front->next;
        front->next = nullptr;
        rear->next = nextFront;
        front = nextFront;
        curSize--;
        return true;
    }
    
    int Front() {
        if(front == nullptr) {
            return -1;
        }
        return front->val;
    }
    
    int Rear() {
        if(rear == nullptr) {
            return -1;
        }
        return rear->val;
    }
    
    bool isEmpty() {
        if(curSize == 0) {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(curSize == capacity) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */