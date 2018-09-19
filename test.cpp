#include <iostream>
using namespace std;

template <class T>
struct node{
    T val;
    node *next;
};

template <class T>
class List{
private:
    struct node<T> * head;
    int length;
public:
    List();
    ~List();
    bool addItem(T x);
    void show();
    bool isEmpty();
};

template <class T>
bool List<T>::isEmpty() {
    return (length == 0);
}

template <class T>
List<T>::List() {
    head = new struct node<T>;
    head -> next = NULL;
    head -> val = 0;
    length = 0;
}


template <class T>
void List<T>::show() {
    struct node<T>* temp = head;
    while(temp){
        cout << temp -> val;
        temp = temp -> next;
    }
    delete temp;
}

template <class T>
List<T>::~List() {
    cout << "it is finshed" << endl;
    struct node<T>* temp =  head;
    while(head){
        head = head -> next;
        delete head;
    }
    delete temp;
}

template <class T>
bool List<T>::addItem(T x) {
    struct node<T>* temp = head;
    while(temp -> next){
        temp = temp -> next;
    }
    temp -> next -> val = x;
    temp -> next -> next = NULL;

    return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    List<int> newlist;
    cout << newlist.isEmpty();
    newlist.addItem(1);
    newlist.addItem(2);
    newlist.addItem(3);
    newlist.show();
    return 0;
}
