#include<iostream>
using namespace std;
class Node{
public:
    Node *left;
    Node *right;
    int data;
    Node(int input){
        left = nullptr;
        right = nullptr;
        data = input;
    }
};
void printpre(Node *root){
    if(root == nullptr){
        return;
    }
    cout << root -> data << " ";
    printpre(root -> left);
    printpre(root -> right);
}
void printTree(Node *root , int level){
    if(root == nullptr){
        return;
    }
    printTree(root -> left , level + 1);
    for(int i = 0 ; i < level ; i++){
        cout << "*";
    }
    cout << root -> data << endl;
    printTree(root -> right , level + 1);
}

void printMid(Node *root){
    if(root == nullptr){
        return;
    }
    printMid(root -> left);
    cout << root -> data << endl;
    printMid(root -> right);
}

void printBeh(Node *root){
    if(root == nullptr){
        return;
    }
    cout << root -> data << endl;
    printBeh(root -> left);
    printBeh(root -> right);
}
int main(){
    Node root(2);
    Node node1(1);
    Node node2(22);
    Node node3(221);
    Node node4(1111);
    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node1.right = &node4;
    printpre(&root);
    return 0;
}
