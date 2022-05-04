class MyCircularQueue {
public:
    vector<int>arr;
    int front,rear;
    int n;
    int maxsize;
    MyCircularQueue(int k) {
        arr.resize(k);
        front=0;
        rear=k-1;
        n=0;
        maxsize=k;
    }
    
    bool enQueue(int value) {
        if(isFull()==true){
            return false;
        }
        rear=(rear+1)%maxsize;
        arr[rear]=value;
        n++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()==true){
            return false;
        }
        front=(front+1)%maxsize;
        n--;
        return true;
    }
    
    int Front() {
        if(isEmpty()==true){
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()==true){
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        return n==0;
    }
    
    bool isFull() {
        return n==maxsize;
    }
};

