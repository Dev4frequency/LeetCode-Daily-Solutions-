class MyCircularQueue {
private:
    int* arr;
    int currsize;
    int front;
    int cap;

public:
    MyCircularQueue(int k) {
        cap = k;
        arr = new int[k];
        front = 0;
        currsize = 0;
    }
    
    bool enQueue(int value) {
        if(currsize == cap){
            return false;
        }
        int rear = (front + currsize) % cap;
        arr[rear] = value;
        currsize++;
        return true;
    }
    
    bool deQueue() {
        if(currsize == 0){
            return false;
        }
        int res = arr[front];
        front = (front + 1) % cap;
        currsize--;
        return true;
    }
    
    int Front() {
        if(currsize == 0){
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
        if(currsize == 0){
            return -1;
        }
        int rear = (front + currsize - 1) % cap;
        return arr[rear];
    }
    
    bool isEmpty() {
        if(currsize == 0)
            return true;
        return false;
    }
    
    bool isFull() {
        if(currsize == cap)
            return true;
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