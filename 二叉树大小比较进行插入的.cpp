
#include<iostream>
using namespace std;

class BinarySearchTreeNode
{
public:
    int key;
    BinarySearchTreeNode *leftChild;
    BinarySearchTreeNode *rightChild;
    BinarySearchTreeNode(int tempKey)
    {
        key=tempKey;
        leftChild=NULL;
        rightChild=NULL;
    }
};
class BinarySearchTree
{
private:
    BinarySearchTreeNode *Root;
public:
    BinarySearchTree();
    BinarySearchTreeNode *GetRoot();
    BinarySearchTreeNode *FindBST(int );
    void UpdataBSTNode(int,int);
    void InsertBSTNode(int);
    bool DeleteBSTNode(int);
    void DeleteNoOrOneChildBSTNode(BinarySearchTreeNode *,BinarySearchTreeNode *);
    void PreOrderBSTPrint(BinarySearchTreeNode *);
    void InOrderBSTPrint(BinarySearchTreeNode *);
    void SufOrderBSTPrint(BinarySearchTreeNode *);
    void RotateBSTPrint(BinarySearchTreeNode *,int);
};

BinarySearchTree::BinarySearchTree()
{
    Root=NULL;
}


BinarySearchTreeNode *BinarySearchTree::GetRoot()
{
    return this->Root;
}


BinarySearchTreeNode *BinarySearchTree::FindBST(int tempKey)
{
    BinarySearchTreeNode *cur=this->Root;
    while(cur!=NULL)
    {
        if(cur->key==tempKey)
            break;
        else if(cur->key>tempKey)
            cur=cur->leftChild;
        else cur=cur->rightChild;
    }
    return cur;
}


void BinarySearchTree::InsertBSTNode(int tempKey)
{
    BinarySearchTreeNode *pre=NULL,*cur=this->Root;
    while(cur!=NULL)
    {
        pre=cur;
        if(cur->key>tempKey)
            cur=cur->leftChild;
        else cur=cur->rightChild;
    }
    BinarySearchTreeNode *tempNode=new BinarySearchTreeNode(tempKey);
    if(pre==NULL)
    {
        this->Root=tempNode;
    }
    else if(pre->key>tempNode->key)
        pre->leftChild=tempNode;
    else pre->rightChild=tempNode;
}




void BinarySearchTree::UpdataBSTNode(int oldKey,int newKey)
{
    DeleteBSTNode(oldKey);
    InsertBSTNode(newKey);
}


void BinarySearchTree::DeleteNoOrOneChildBSTNode(BinarySearchTreeNode *pre,BinarySearchTreeNode *cur)
{
    if(NULL==cur->leftChild&&NULL==cur->rightChild)
    {
        if(NULL==pre)
            Root=NULL;
        else if(pre->leftChild==cur)
            pre->leftChild=NULL;
        else pre->rightChild=NULL;
        delete cur;
    }
    else if(cur->rightChild!=NULL
    {
        if(NULL==pre)
            Root=cur->rightChild;
        else if(pre->leftChild==cur)
            pre->leftChild=cur->rightChild;
        else
            pre->rightChild=cur->rightChild;
        delete cur;
    }
    else if(cur->leftChild!=NULL)
    {
        if(NULL==pre)
            Root=cur->leftChild;
        else if(pre->leftChild==cur)
            pre->leftChild=cur->leftChild;
        else
            pre->rightChild=cur->leftChild;
        delete cur;
    }
}



bool BinarySearchTree::DeleteBSTNode(int tempKey)
{
    BinarySearchTreeNode *pre=NULL,*cur=Root;
    while(cur!=NULL)
    {
        if(cur->key==tempKey)
            break;
        else
        {
            pre=cur;
            if(cur->key>tempKey)
                cur=cur->leftChild;
            else cur=cur->rightChild;
        }
    }
    if(NULL==cur)return false;
    if(NULL==cur->leftChild||NULL==cur->rightChild)
        DeleteNoOrOneChildBSTNode(pre,cur);
    else 
    {
        BinarySearchTreeNode *rPre=cur,*rCur=cur->rightChild;
        while(rCur->leftChild!=NULL)
        {
            rPre=rCur;
            rCur=rCur->leftChild;
        }
        cur->key=rCur->key;
        DeleteNoOrOneChildBSTNode(rPre,rCur);
    }
}


void BinarySearchTree::PreOrderBSTPrint(BinarySearchTreeNode *tempRoot)
{
    if(NULL==tempRoot)
        return ;
    cout<<tempRoot->key<<"    ";
    PreOrderBSTPrint(tempRoot->leftChild);
    PreOrderBSTPrint(tempRoot->rightChild);
}

void BinarySearchTree::InOrderBSTPrint(BinarySearchTreeNode *tempRoot)
{
    if(NULL==tempRoot)
        return ;
    InOrderBSTPrint(tempRoot->leftChild);
    cout<<tempRoot->key<<"    ";
    InOrderBSTPrint(tempRoot->rightChild);
}


void BinarySearchTree::SufOrderBSTPrint(BinarySearchTreeNode *tempRoot)
{
    if(NULL==tempRoot)
        return ;
    SufOrderBSTPrint(tempRoot->leftChild);
    SufOrderBSTPrint(tempRoot->rightChild);
    cout<<tempRoot->key<<"    ";
}

void BinarySearchTree::RotateBSTPrint(BinarySearchTreeNode *tempRoot,int tempColumn)
{
    if(NULL==tempRoot)
        return ;
    RotateBSTPrint(tempRoot->leftChild,tempColumn+1);
    for(int i=0;i<tempColumn;i++)
        cout<<"    ";
    cout<<"---"<<tempRoot->key<<endl;
    RotateBSTPrint(tempRoot->rightChild,tempColumn+1);
}

int main()
{
    int val;

    BinarySearchTree myBinarySearchTree;
    while (cin >> val) {
        if (val == 0)break;
        myBinarySearchTree.InsertBSTNode(val);
    }
    cout << endl << "*****************************" << endl;
    myBinarySearchTree.PreOrderBSTPrint(myBinarySearchTree.GetRoot());
    cout << endl << "=============================" << endl;
    myBinarySearchTree.InOrderBSTPrint(myBinarySearchTree.GetRoot());
    cout << endl << "=============================" << endl;
    myBinarySearchTree.SufOrderBSTPrint(myBinarySearchTree.GetRoot());
    cout << endl << "=============================" << endl;
    myBinarySearchTree.RotateBSTPrint(myBinarySearchTree.GetRoot(), 0);
    cout << endl << "*****************************" << endl;

    return 0;
}
