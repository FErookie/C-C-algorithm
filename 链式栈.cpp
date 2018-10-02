#include<iostream>
using namespace std;

template <class T>
class ListNode {
public:
	T data;
	ListNode <T> *next;
	ListNode(T value ,  ListNode <T> * ptr = nullptr) {
		data = value;
		next = ptr;
	}
};

template <class T>
class StackList {
private:
	ListNode <T> *top;
	int size;
public:
	StackList(int s = 0) {
		top = nullptr;
		size = s;
	}
	~StackList() {
		clear();
	}
	void clear() {
		while (top != nullptr) {
			ListNode<T> * temp = top;
			top = top->next;
			delete temp;
		}
		size = 0;
	}
	bool push(const T Item) {
		ListNode<T> * temp = new ListNode<T>(Item, top);
		top = temp;
		size++;
		return true;
	}
	bool pop() {
		ListNode <T> * tmp;
		if (size == 0) {
			cout << "栈为空 不能执行出栈操作" << endl;
			return false;
		}
		tmp = top->next;
		delete top;
		top = tmp;
		size--;
		return true;
	}

	T Top() {
		T item;
		if (size == 0) {
			cout << "栈为空 无法读取栈顶元素" << endl;
			return false;
		};
		item = top->data;
		return item;
	}
};


int main() {
	StackList<int> Stack1;
	Stack1.push(1);
	Stack1.push(2);
	cout << Stack1.Top() << endl;
	Stack1.push(1);
	Stack1.push(2);
	Stack1.pop();
	Stack1.push(22);
	cout << Stack1.Top() << endl;
	getchar();
}
