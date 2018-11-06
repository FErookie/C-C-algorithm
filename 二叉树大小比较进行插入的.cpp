
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class BinarySearchTreeNode
{
public:
	int key;
	BinarySearchTreeNode *leftChild;
	BinarySearchTreeNode *rightChild;
	BinarySearchTreeNode(int tempKey)
	{
		key = tempKey;
		leftChild = NULL;
		rightChild = NULL;
	}
};
class BinarySearchTree
{
private:
	BinarySearchTreeNode * Root;
public:
	BinarySearchTree();
	BinarySearchTreeNode *GetRoot();
	BinarySearchTreeNode *FindBST(int);
	void UpdataBSTNode(int, int);
	void InsertBSTNode(int);
	bool DeleteBSTNode(int);
	void levelOrderPrint(BinarySearchTreeNode *);
	void DeleteNoOrOneChildBSTNode(BinarySearchTreeNode *, BinarySearchTreeNode *);
	void PreOrderBSTPrint(BinarySearchTreeNode *);
	void InOrderBSTPrint(BinarySearchTreeNode *);
	void SufOrderBSTPrint(BinarySearchTreeNode *);
	void PreOrderBSTPrintN(BinarySearchTreeNode *);
	void InOrderBSTPrintN(BinarySearchTreeNode *);
	void RotateBSTPrint(BinarySearchTreeNode *, int);
	void SufOrderBSTPrintN(BinarySearchTreeNode *);
};

void BinarySearchTree::levelOrderPrint(BinarySearchTreeNode *root) {
	queue <BinarySearchTreeNode *> nodeQueue;
	BinarySearchTreeNode * temproot = root;
	if (root == nullptr) {
		return;
	}
	if (temproot) {
		nodeQueue.push(temproot);

	}
	while (!nodeQueue.empty()) {
		temproot = nodeQueue.front();
		cout << temproot->key << "    ";
		nodeQueue.pop();
		if (temproot->leftChild) {
			nodeQueue.push(temproot->leftChild);
		}
		if (temproot->rightChild) {
			nodeQueue.push(temproot->rightChild);
		}
	}
}

void BinarySearchTree::PreOrderBSTPrintN(BinarySearchTreeNode * root) {
	stack<BinarySearchTreeNode*> nodeStack;
	BinarySearchTreeNode * temproot = root;
	while (!nodeStack.empty() || temproot) {
		if (temproot) {
			cout << temproot->key << "    ";
			if (temproot->rightChild != nullptr) {
				nodeStack.push(temproot->rightChild);
			}
			temproot = temproot->leftChild;
		}
		else {
			temproot = nodeStack.top();
			nodeStack.pop();
		}
	}
}

void BinarySearchTree::InOrderBSTPrintN(BinarySearchTreeNode * root) {
	stack<BinarySearchTreeNode *> nodeStack;
	BinarySearchTreeNode * temproot = root;
	while (!nodeStack.empty() || temproot) {
		if (temproot) {
			nodeStack.push(temproot);
			temproot = temproot->leftChild;
		}
		else {
			temproot = nodeStack.top();
			cout << temproot->key << "    ";
			temproot = temproot->rightChild;
			nodeStack.pop();
		}
	}
}

BinarySearchTree::BinarySearchTree()
{
	Root = NULL;
}


BinarySearchTreeNode *BinarySearchTree::GetRoot()
{
	return this->Root;
}


BinarySearchTreeNode *BinarySearchTree::FindBST(int tempKey)
{
	BinarySearchTreeNode *cur = this->Root;
	while (cur != NULL)
	{
		if (cur->key == tempKey)
			break;
		else if (cur->key>tempKey)
			cur = cur->leftChild;
		else cur = cur->rightChild;
	}
	return cur;
}


void BinarySearchTree::InsertBSTNode(int tempKey)
{
	BinarySearchTreeNode *pre = NULL, *cur = this->Root;
	while (cur != NULL)
	{
		pre = cur;
		if (cur->key>tempKey)
			cur = cur->leftChild;
		else cur = cur->rightChild;
	}
	BinarySearchTreeNode *tempNode = new BinarySearchTreeNode(tempKey);
	if (pre == NULL)
	{
		this->Root = tempNode;
	}
	else if (pre->key>tempNode->key)
		pre->leftChild = tempNode;
	else pre->rightChild = tempNode;
}

void BinarySearchTree::SufOrderBSTPrintN(BinarySearchTreeNode * root) {
	stack <BinarySearchTreeNode*> nodeStack;
	BinarySearchTreeNode *temproot = root;
	BinarySearchTreeNode *pre = root;
	while (temproot) {
		for (; temproot->leftChild != nullptr; temproot = temproot->leftChild) {
			nodeStack.push(temproot);
		}
		while (temproot != nullptr && (temproot ->rightChild == nullptr || temproot -> rightChild == pre)) {
			cout << temproot->key << "    ";
			pre = temproot;
			if (nodeStack.empty()) {
				return;
			}
			temproot = nodeStack.top();
			nodeStack.pop();
		}
		nodeStack.push(temproot);
		temproot = temproot->rightChild;
	}
}



void BinarySearchTree::UpdataBSTNode(int oldKey, int newKey)
{
	DeleteBSTNode(oldKey);
	InsertBSTNode(newKey);
}


void BinarySearchTree::DeleteNoOrOneChildBSTNode(BinarySearchTreeNode *pre, BinarySearchTreeNode *cur)
{
	if (NULL == cur->leftChild&&NULL == cur->rightChild)
	{
		if (NULL == pre)
			Root = NULL;
		else if (pre->leftChild == cur)
			pre->leftChild = NULL;
		else pre->rightChild = NULL;
		delete cur;
	}
	else if (cur->rightChild != NULL)
		{
			if (NULL == pre)
			Root = cur->rightChild;
			else if (pre->leftChild == cur)
				pre->leftChild = cur->rightChild;
			else
				pre->rightChild = cur->rightChild;
	delete cur;
		}
	else if (cur->leftChild != NULL)
		{
			if (NULL == pre)
				Root = cur->leftChild;
			else if (pre->leftChild == cur)
				pre->leftChild = cur->leftChild;
			else
				pre->rightChild = cur->leftChild;
			delete cur;
		}
}



bool BinarySearchTree::DeleteBSTNode(int tempKey)
{
	BinarySearchTreeNode *pre = NULL, *cur = Root;
	while (cur != NULL)
	{
		if (cur->key == tempKey)
			break;
		else
		{
			pre = cur;
			if (cur->key>tempKey)
				cur = cur->leftChild;
			else cur = cur->rightChild;
		}
	}
	if (NULL == cur)return false;
	if (NULL == cur->leftChild || NULL == cur->rightChild)
		DeleteNoOrOneChildBSTNode(pre, cur);
	else
	{
		BinarySearchTreeNode *rPre = cur, *rCur = cur->rightChild;
		while (rCur->leftChild != NULL)
		{
			rPre = rCur;
			rCur = rCur->leftChild;
		}
		cur->key = rCur->key;
		DeleteNoOrOneChildBSTNode(rPre, rCur);
	}
}


void BinarySearchTree::PreOrderBSTPrint(BinarySearchTreeNode *tempRoot)
{
	if (NULL == tempRoot)
		return;
	cout << tempRoot->key << "    ";
	PreOrderBSTPrint(tempRoot->leftChild);
	PreOrderBSTPrint(tempRoot->rightChild);
}

void BinarySearchTree::InOrderBSTPrint(BinarySearchTreeNode *tempRoot)
{
	if (NULL == tempRoot)
		return;
	InOrderBSTPrint(tempRoot->leftChild);
	cout << tempRoot->key << "    ";
	InOrderBSTPrint(tempRoot->rightChild);
}


void BinarySearchTree::SufOrderBSTPrint(BinarySearchTreeNode *tempRoot)
{
	if (NULL == tempRoot)
		return;
	SufOrderBSTPrint(tempRoot->leftChild);
	SufOrderBSTPrint(tempRoot->rightChild);
	cout << tempRoot->key << "    ";
}

void BinarySearchTree::RotateBSTPrint(BinarySearchTreeNode *tempRoot, int tempColumn)
{
	if (NULL == tempRoot)
		return;
	RotateBSTPrint(tempRoot->leftChild, tempColumn + 1);
	for (int i = 0; i<tempColumn; i++)
		cout << "    ";
	cout << "---" << tempRoot->key << endl;
	RotateBSTPrint(tempRoot->rightChild, tempColumn + 1);
}

int main()
{
	int val;

	BinarySearchTree myBinarySearchTree;
	while (cin >> val) {
		if (val == 0)break;
		myBinarySearchTree.InsertBSTNode(val);
	}
	cout << endl << "广度优先*****************************" << endl;
	myBinarySearchTree.levelOrderPrint(myBinarySearchTree.GetRoot());
	cout << endl << "前序递归=============================" << endl;
	myBinarySearchTree.PreOrderBSTPrint(myBinarySearchTree.GetRoot());
	cout << endl << "前序非递归=============================" << endl;
	myBinarySearchTree.PreOrderBSTPrintN(myBinarySearchTree.GetRoot());
	cout << endl << "中序递归=============================" << endl;
	myBinarySearchTree.InOrderBSTPrint(myBinarySearchTree.GetRoot());
	cout << endl << "中序非递归=============================" << endl;
	myBinarySearchTree.InOrderBSTPrintN(myBinarySearchTree.GetRoot());
	cout << endl << "后序递归=============================" << endl;
	myBinarySearchTree.SufOrderBSTPrint(myBinarySearchTree.GetRoot());
	cout << endl << "后序非递归=============================" << endl;
	myBinarySearchTree.SufOrderBSTPrintN(myBinarySearchTree.GetRoot());
	cout << endl << "*****************************" << endl;
	cout << "树的结构实际上是" << endl;
	myBinarySearchTree.RotateBSTPrint(myBinarySearchTree.GetRoot() , 0);
	getchar();
	getchar();
	return 0;
}
