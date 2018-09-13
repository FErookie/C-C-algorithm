#include<iostream>
using namespace std;
template <class T>
class listLine{
private:
    int length;
    int maxLength;
    T *content_head;

  public:
    listLine(){
      length = 0;
      content_head = NULL;
      maxLength = 0;
    }
    bool init(){
        cout << "input the max length";
        cin >> maxLength;
        content_head = new T[maxLength];
        if(content_head == NULL){
          return false;
        }
        return true;
    }
    bool modify(T &num1 , T &num2);
    bool insert(T x , int p);
    bool empty();
    T find(T &element);
    bool clear();
    void show();
    void add(T x);
    void showContentpre();
    ~listLine();
};
template <class T>
void listLine<T>::showContentpre(){
  cout << content_head;
}
template <class T>
bool listLine<T>::empty(){
  return length == 0;
}
template <class T>
bool listLine<T>::insert(T x , int p){
  if(empty()){
    content_head = &x;
    length++;
    return true;
  }

  if(p < 0 || p > length){
    cout << "the length should > 0 & < length";
    return false;
  }

  for(int i = length ; i > p ; i--){
      content_head[i + 1] = content_head[i];
  }

  length ++;
  return true;
}

template <class T>
T listLine<T>::find(T &element){

  int i = 0 ;
  for(i = 0 ; i < length ; i++){
    if(content_head[i] == element){
      return content_head[i];
    }
  }
  if(i == length){
    return NULL;
  }

}

template <class T>
void listLine<T>::show(){
  for(int i = 0 ; i < length ; i++){
    cout << content_head[i];
  }
  cout << '\n';
}
template <class T>
listLine<T>::~listLine(){
  delete content_head;
}

template <class T>
bool listLine<T>::clear(){
  delete content_head;
  if(content_head == NULL){
    return true;
  }
  return true;
}

template <class T>
bool listLine<T>::modify(T &num1 , T &num2){
  int i = 0 ;
  for(i = 0 ; i < length ; i++){
    if(content_head[i] == num1){
      content_head[i] = num2;
      return true;
    }
  }
  if(i == length){
    return false;
  }
}
template <class T>
void listLine<T>::add(T x){
  content_head[length] = x;
  length++;
}

int main(){
  listLine<int> list;
  list.init();
  list.show();
  list.add(1);
  list.add(1);
  list.add(2);
  list.show();
  list.insert(1 , 2);
  list.show();
  list.clear();
  list.showContentpre();
  return 0;
}
