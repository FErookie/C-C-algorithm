#include <iostream>
using namespace std;

template <class T>
class Stack{
public:
    bool isEmpty();
    bool isFull();

    bool pop();
    bool push_back(const T element);

    T top_element();
    void clear();
};

template <class T>
class arrayStack:public Stack<T>{
private:
    int top;
    int maxsize;
    T * st;
public:
    arrayStack(int num);
    ~arrayStack();

    bool isEmpty();
    bool isFull();

    bool pop();
    bool push_back(const T element);

    T top_element();
    void clear();
};

template <class T>
arrayStack<T>::arrayStack(int num) {
    maxsize = num;
    st = new T(maxsize);
    top = -1;
}

template <class T>
arrayStack<T>::~arrayStack() {
    delete []st;
}

template <class T>
void arrayStack<T>::clear(){
    top = -1;
}

template <class T>
bool arrayStack<T>::isEmpty(){
    return (top == -1);
}

template <class T>
bool arrayStack<T>::isFull() {
    return (top == maxsize - 1);
}

template <class T>
T arrayStack<T>::top_element(){
    if(top == -1){
        return -1;
    }
    return st[top];
}

template <class T>
bool arrayStack<T>::push_back(const T element) {
    if(isFull()){
        cout << "这个顺序的栈已经是满的了" << endl;
        return false;
    }
    else{
        top ++;
        st[top] = element;
        return true;
    }
}

template <class T>
bool arrayStack<T>::pop() {
    if(isEmpty()){
        cout << "现在已经是空的栈" << endl;
        return false;
    }else{
        top --;
        return true;
    }
}

int main() {
    arrayStack<int> *a1 = new arrayStack<int>(10);
    a1 -> push_back(19);
    a1 -> push_back(10);
    a1 -> push_back(40);
    a1 -> push_back(120);
    a1 -> push_back(1110);
    cout << a1 ->top_element() << endl;
    a1 -> pop();
    cout << a1 ->top_element() << endl;
    a1 -> clear();
    cout << a1 -> isEmpty() << endl;
    a1 -> push_back(19);
    a1 -> push_back(10);
    a1 -> push_back(19);
    a1 -> push_back(10);
    a1 -> push_back(19);
    a1 -> push_back(10);
    a1 -> push_back(19);
    a1 -> push_back(10);
    a1 -> push_back(19);
    a1 -> push_back(10);
    a1 -> push_back(10);
    cout << a1 -> isFull() << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
