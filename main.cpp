
#include <iostream>
using namespace std;

class node {
public:
    node() {
        next = NULL;
        val = 0;
    }
    node *next;
    int val;
};

class myList {
public:
    node *head;
    node *tail;

    myList();

    ~myList();

    void addItem(int x);

    void show();

    void deleteItem(int position);

    void insertItem(int x, int position);

    void modifyItem(int x, int target);

    int findItem(int x);

    int indexof(int x);

    void sort();

    int Max(node * temp );

    int length(node * temp );

    int avarage_number(node *temp );
};

myList::myList() {
    head = tail = new node();
}

myList::~myList() {
    node *tempptr;
    while (head->next != NULL) {
        tempptr = head->next;
        delete head;
        head = tempptr;
    }
    delete head;

}

void myList::addItem(int x) {
    node *temp = new node();
    temp->val = x;
    temp->next = NULL;
    if (temp) {

        tail->next = temp;
        tail = temp;
    } else {
        cout << "内存申请失败" << endl;
    }
}

void myList::show() {
    node *temp = head->next;
    while (temp) {
        cout << temp->val << "," << endl;
        temp = temp->next;
    }
    delete temp;
}

int myList::findItem(int x) {
    node *temptr = head->next;
    while (temptr != nullptr) {
        if (temptr->val == x) {
            return temptr->val;
        }
        temptr = temptr->next;
    }
    if (temptr == nullptr) {
        return 999;
    }
}

int myList::indexof(int x) {
    node *temp = head->next;
    int count = 0;
    while (temp) {
        if (temp->val == x) {
            return count + 1; //这样不是从０开始的
        }
        temp = temp->next;
        count++;
    }
    return -1;
}

void myList::insertItem(int x, int position) {
    node *temp = head;
    int count = 0;
    while (temp) {
        if (position == count + 1) {
            break;
        }
        count++;
        temp = temp->next;
    }
    node *temp2 = temp->next;
    node *temp_node = new node();
    temp_node->val = x;
    temp->next = temp_node;
    temp_node->next = temp2;
}

void myList::deleteItem(int position) {
    node *temp = head;
    int count = 0;
    while (temp) {
        if (position == count + 1) {
            break;
        }
        count++;
        temp = temp->next;
    }
    node *temp2 = temp->next;
    temp->next = temp->next->next;
    delete temp2;
}

void myList::modifyItem(int x, int target) {
    node *temptr = head->next;
    while (temptr != nullptr) {
        if (temptr->val == target) {
            temptr->val = x;
        }
        temptr = temptr->next;
    }
    if (temptr == nullptr) {
        return;
    }
}

void myList::sort() {
    node *temp = head->next;
    node *temp2 = head->next->next;
    int temp_number = 0;
    while (temp->next) {
        if (temp->val < temp->next->val) {
            temp_number = temp->val;
            temp->val = temp->next->val;
            temp->next->val = temp_number;
        }
        temp = temp->next;
    }

}

int myList::Max(node *temp ) {
    int max;
    if (temp -> next == nullptr) {
        return temp -> val;
    }else{
        max = Max(temp -> next);
        if(max > temp -> val){
            return max;
        }else{
            return temp -> val;
        }
    }
}

int myList::length(node *temp) {
    if (temp -> next == nullptr) {
        return 0;
    }else{
        return 1 + length(temp -> next);
    }
}

int myList::avarage_number(node *temp) {
    if(temp -> next == nullptr){
        return (temp -> val) / length(head);
    }else{
        return (avarage_number(temp -> next) + (temp -> val) / length(head));
    }
}

node* mergeTwoLists(myList* list1, myList* list2) {
    node *temp_head = new node();
    node *pre = temp_head;
    node *l1 = list1 -> head -> next;
    node *l2 = list2 -> head -> next;
    while (l1 && l2){
        if (l1->val > l2->val){
            pre->next = l1;
            l1 = l1->next;
        }
        else{
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
    }
    if (l1){
        pre->next = l1;
    }
    if (l2){
        pre->next = l2;
    }
    return temp_head;
}


int main() {
    myList list;
    cout << "第一次添加的链表" << endl;
    list.addItem(2);
    list.addItem(29);
    list.addItem(1000);
    list.addItem(100);
    list.show();
    cout << "******************************" << endl;
    cout << "插入操作" << endl;
    list.insertItem(26, 2);
    list.show();
    cout << "******************************" << endl;
    cout << "删除操作" << endl;
    list.deleteItem(2);
    list.show();
    cout << "******************************" << endl;
    cout << "替换操作" << endl;
    list.modifyItem(12, 2);
    list.show();
    cout << "******************************" << endl;
    cout << "最大值" << endl;
    cout << list.Max(list.head) << endl;
    cout << "******************************" << endl;
    cout << "此时长度" << endl;
    cout << list.length(list.head) << endl;
    cout << "******************************" << endl;
    cout << "此时平均值" << endl;
    cout << list.avarage_number(list.head) << endl;
    cout << "******************************" << endl;
    cout << "排序操作" << endl;
    list.sort();
    list.show();
    cout << "******************************" << endl;
    cout << "第二个链表 (直接就排序了)" << endl;
    myList list2;
    list2.addItem(22);
    list2.addItem(-1);
    list2.addItem(40);
    list2.sort();
    list2.show();
    cout << "******************************" << endl;
    cout << "此时平均值" << endl;
    cout << list2.avarage_number(list2.head) << endl;
    cout << "******************************" << endl;
    cout << "第二个链表的最大值" << endl;
    cout << list2.Max(list2.head) << endl;
    cout << "******************************" << endl;
    cout << "合并两个有序链表" << endl;
    list.head = mergeTwoLists(&list , &list2);
    list.show();
    cout << "******************************" << endl;
    cout << "此时长度" << endl;
    cout << list.length(list.head) << endl;
    cout << "******************************" << endl;
    cout << "Hello world!" << endl;
    return 0;
}
