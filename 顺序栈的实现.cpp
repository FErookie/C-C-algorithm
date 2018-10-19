#include <iostream>
using namespace std;
template <class T>
class Queue{
public:
    void clear();
    bool EnQueue(const T item);
    bool DeQueue();
    bool isEmpty();
    bool isFull();
    T getFront(T & item);
};

template <class T>
class ArrayQueue:public Queue<T>{
public:
    int maxsize;
    int front;
    int rear;
    int *queue;
    ArrayQueue(int size){
        maxsize = size + 1;
        queue = new T[maxsize];
        front = rear = 0;
    }
    void clear(){
        front = rear;
    }
    bool isEmpty(){
        return front == rear;
    }
    bool isFull(){
        return (rear + 1)%maxsize == front;
    }
    ~ArrayQueue(){
        delete []queue;
    }
    bool EnQueue(const T item){
        if(isFull()){
            cout << "此队列已经是满的了" << endl;
            return false;
        }

        queue[rear] = item;
        rear = (rear + 1) % maxsize;
        return true;
    }
    bool DeQueue(){
        if(isEmpty()){
            cout << "这个队列是空的" << endl;
            return false;
        }
        front = (front + 1) % maxsize;
        return true;
    }
    bool getFront(T & item){
        if(isEmpty()){
            return false;
        }
        item = queue[front];
        return true;
    }
};
int main(){
    ArrayQueue<int> myQueue(10);
    cout << "--------------------------------" << endl;
    cout << myQueue.isEmpty() << endl;
    myQueue.EnQueue(1);
    myQueue.EnQueue(4);
    myQueue.EnQueue(8);
    int number = 0;
    myQueue.getFront(number);
    cout << "此时的队首元素为" << number << endl;

    return 0;
}
