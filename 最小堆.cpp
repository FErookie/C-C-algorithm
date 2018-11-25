#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
class MinHeap{
public:
    T * heapArray;
    int CurrentSize;
    int MaxSize;
    MinHeap(T * array , int num , int max){
        this -> heapArray = new T[num];
        for(int i = 0 ; i < num ; i++){
            this -> heapArray[i] = array[i];
        }
        this -> CurrentSize = num;
        this -> MaxSize = max;
    }
    bool Remove(int pos, T& node);
    int leftchild(int pos) const;
    int rightchild(int pos) const;
    bool isLeaf(int pos) const;
    virtual  ~MinHeap(){
        delete [] heapArray;
    };
    int parent(int pos) const;
    void BuildHeap();
    void SiftDown(int left);
    void SiftUp(int position);
    int getCurrentSize();
    T *getMinHeap();
};
template<class T>
bool MinHeap<T>::isLeaf(int pos) const
{
    if (2 * pos + 1 > CurrentSize - 1)
        return true;
    else
        return false;
}

template <class T>
int MinHeap<T>::getCurrentSize() {
    return CurrentSize;
}

template <class T>
T* MinHeap<T>::getMinHeap() {
    return heapArray;
}

template<class T>
int MinHeap<T>::leftchild(int pos) const
{
    int leftchild;
    if (!isLeaf(pos))
    {
        leftchild = 2 * pos + 1;
        cout << pos << "号结点的左孩子为" << leftchild << "号" << endl;
    }
    else
        cout << pos << "号结点是叶子结点，没有左孩子" << endl;
    return leftchild;
}

template<class T>
int MinHeap<T>::rightchild(int pos) const
{
    int rightchild = 2 * pos + 2;
    if (rightchild < CurrentSize)
        cout << pos << "号结点的右孩子为" << rightchild << "号" << endl;
    else
        cout << pos << "号结点没有右孩子" << endl;

    return rightchild;
}

template <class T>
void MinHeap<T>::SiftDown(int left) {
    int i = left;
    int j = 2 * i + 1;
    T temp = heapArray[i];

    while(j < CurrentSize){
        if((j < CurrentSize - 1) && (heapArray[j] > heapArray[j + 1])){
            j++;
        }
        if(temp > heapArray[j]){
            heapArray[i] = heapArray[j];
            i = j;
            j = 2 * j + 1;
        } else{
            break;
        }
    }
    heapArray[i] = temp;
}

template<class T>
int MinHeap<T>::parent(int pos) const
{
    int parent = 0;
    if (pos > 0)
    {
        parent = (pos - 1) / 2;
        cout << pos << "号结点的父结点为" << parent << "号" << endl;
    }
    else
        cout << pos << "号位置无父结点" << endl;
    return parent;
}

template <class T>
void MinHeap<T>::SiftUp(int position) {
    int i = position;
    int j = parent(position);
    T temp = heapArray[i];
    while (j >= 0) {
        if (temp > heapArray[j]) {
            heapArray[i] = heapArray[j];
            i = j;
            j = parent(i);
        }
        else break;
    }
    heapArray[i] = temp;
}

template <class T>
void MinHeap<T>::BuildHeap() {
    for(int i = CurrentSize / 2 - 1 ; i >= 0 ; i--){
        SiftDown(i);
    }
}

int main(){

    return 0;
}
