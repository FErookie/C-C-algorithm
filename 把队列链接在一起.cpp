#include <iostream>
using namespace std;

template <class T>
class LinkNode{
public:
    T data;
    LinkNode<T> *link;
    LinkNode(const T&el , LinkNode<T> * ptr = 0){
        data = el;
        link = ptr;
    }
};

template <class T>
class Queue{
public:
    void clear();
    bool EnQueue(const T item);
    bool DeQueue();
    bool isEmpty();
    bool isFull();
    T getFront();
};

template <class T>
class LinkQueue:public Queue<T>{
public:
    int size;
    LinkNode<T> *front;
    LinkNode<T> *rear;
    LinkQueue(){
        size = 0;
        front = rear = NULL;
    }
    ~LinkQueue(){
        clear();
    }
    void clear(){
        while(front != NULL){
            rear = front;
            front = front -> link;
            delete rear;
        }
        rear = NULL;
        size = 0;
    };
    bool EnQueue(const T item){
        if(rear == NULL){
            front = rear = new LinkNode<T>(item , NULL);
        }else{
            rear -> link = new LinkNode<T>(item , NULL);
            rear = rear -> link;
        }
        size ++;
        return true;
    }
    bool DeQueue(){
        LinkNode<T> *temp;
        if(size == 0){
            cout << "队列为空" << endl;
            return false;
        }
        temp = front;
        front = front -> link;
        delete temp;
        if(front == NULL){
            rear = NULL;
        }
        size --;
        return true;
    }
    T getFront(){
        if(size == 0){
            cout << "队列为空" << endl;
            return NULL;
        }
        return front -> data;
    }
};

int main(){
    LinkQueue<int> queue_list[10];
    int temp = 0;
    cout << "请输入 10 以内的数据 否则将会退出" << endl;
    cin >> temp;
    while(temp >= 0 && temp < 10){
        queue_list[temp].EnQueue(temp);
        cin >> temp;
    }
    for(int i = 1 ; i < 9 ; i++){
        if(queue_list[i].size == 0){
            continue;
        }
        LinkNode <int> * temp = queue_list[i].rear;
        queue_list[0].rear -> link = queue_list[i].front;
        queue_list[0].rear = temp;
    }
    if(queue_list[9].size != 0){
        LinkNode <int> * temp = queue_list[9].rear;
        queue_list[0].rear -> link = queue_list[9].front;
        queue_list[0].rear = temp;
    }
    while(queue_list[0].rear){
        cout << queue_list[0].rear->data;
        queue_list[0].rear = queue_list[0].rear->link;
    }
    return 0;
}
