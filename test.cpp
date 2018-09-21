#include <iostream>
#include <stdio.h>
using namespace std;

class node{
    friend class myList;
public:
    node(){
        next = NULL;
        val = 0;
    }
private:
    node * next;
    int val;
};

class myList{
private:
    node *head;
    node *tail;
public:
    myList();
    ~myList();
    void addItem(int x);
    void show();
    void deleteItem(int position);
    void insertItem(int x , int position);
    void modifyItem(int x , int target);
    int findItem(int x);
    int indexof(int x);
};

myList::myList(){
    head = tail = new node();
}

myList::~myList(){
	node *tempptr;
	while(head->next!=NULL)
	{
		tempptr=head->next;
		delete head;
		head=tempptr;
	}
	delete head;

}

void myList::addItem(int x){
    node * temp = new node();
    temp -> val = x;
    temp -> next = NULL;
    if(temp){

        tail -> next = temp;
        tail = temp;
    }else{
        cout << "内存申请失败" << endl;
    }
}

void myList::show(){
    node * temp = head -> next;
    while(temp){
        cout << temp -> val << "," << endl;
        temp = temp -> next;
    }
    delete temp;
}

int myList::findItem(int x){
    node * temptr = head -> next;
    while(temptr != nullptr){
        if(temptr -> val == x){
            return temptr -> val;
        }
        temptr = temptr -> next;
    }
    if(temptr == nullptr){
        return 999;
    }
}

int myList::indexof(int x){
    node * temp = head -> next;
    int count = 0;
    while(temp){
        if(temp -> val == x){
            return count + 1; //这样不是从０开始的
        }
        temp = temp -> next;
        count++;
    }
    return -1;
}

void myList::insertItem(int x , int position){
    node * temp = head;
    int count = 0;
    while(temp){
        if(position == count + 1){
            break;
        }
        count ++;
        temp = temp -> next;
    }
    node * temp2 = temp -> next;
    node * temp_node = new node();
    temp_node -> val = x;
    temp -> next = temp_node;
    temp_node -> next = temp2;
}
void myList::deleteItem(int position){
    node * temp = head;
    int count = 0;
    while(temp){
        if(position == count + 1){
            break;
        }
        count ++;
        temp = temp -> next;
    }
    node * temp2 = temp -> next;
    temp -> next = temp -> next -> next;
    delete temp2;
}

void myList::modifyItem(int x , int target){
    node * temptr = head -> next;
    while(temptr != nullptr){
        if(temptr -> val == target){
            temptr -> val = x;
        }
        temptr = temptr -> next;
    }
    if(temptr == nullptr){
        return;
    }
}
int main()
{
    myList list;
    list.addItem(1);
    list.addItem(2);
    list.addItem(29);
    list.show();
    cout << "******************************" << endl;
    list.insertItem(26 , 2);
    list.show();
    cout << "******************************" << endl;
    list.deleteItem(2);
    list.show();
    cout << "******************************" << endl;
    list.modifyItem(12 , 2);
    list.show();
    cout << "******************************" << endl;
    cout << "Hello world!" << endl;
    return 0;
}
