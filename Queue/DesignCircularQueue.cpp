class MyCircularDeque {
public:
    int *arr;
    int front,rear;
    int n;
    int maxsize;
    MyCircularDeque(int k) {
        arr= new int[k];
        maxsize=k;
        front=0;
        n=0;
        rear=maxsize-1;
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        front=((front-1)+maxsize)%maxsize;
        arr[front]=value;
        n++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        rear=(rear+1)%maxsize;
        arr[rear]=value;
        n++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        front=(front+1)%maxsize;
        n--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        rear=((rear-1)+maxsize)%maxsize;
        n--;
        return true;
    }
    
    int getFront() {
        return isEmpty()? -1:arr[front];
    }
    
    int getRear() {
        return isEmpty() ? -1: arr[rear];
    }
    
    bool isEmpty() {
        return n==0;
    }
    
    bool isFull() {
        return n==maxsize;
    }
};