#include <iostream>
using namespace std;

typedef char ElemType;

//定义树的节点
typedef struct BiNode
{
    ElemType data;			//节点的数据类型
    BiNode * left;			//左子树
    BiNode * right;			//右子树
    BiNode(ElemType val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
}BiNode,*BiTree;


//二叉树类
class BinaryTree
{
public:
    void Create();				//递归的创建二叉树的节点
    int getSize();				//递归得到树的节点数目
    int getHeight();			//递归得到树的高度
    void preOrder();			//前序遍历
    void inOrder();			//中序遍历
    void postOrder();			//后序遍历
    void distroy();			//删除二叉树

private:
    BiTree create();						//递归的创建二叉树的节点
    void preOrder(BiTree root);				//前序遍历
    void inOrder(BiTree root);				//中序遍历
    void postOrder(BiTree root);			//后序遍历
    void distroy(BiTree root);				//摧毁树
    int getHeight(BiTree root);				//递归得到树的高度
    void AddNode(const ElemType key,int direction, BiTree root);         //添加节点
    BiTree m_root;      //根节点
    int size;			//节点总数
};
void BinaryTree::AddNode(const ElemType key,int direction, BiTree root)
{
    if(direction == 0)
    {
        //从左子树插入
        if(root->left == NULL)
            root->left = new BiNode(key);
        else
            AddNode(key, direction,root->left);
    }
    else if(direction == 1)
    {
        //从右子树插入
        if(root->right == NULL)
            root->right = new BiNode(key);
        else
            AddNode(key, direction,root->right);
    }
}

////二叉树的建立，按前序遍历的方式建立二叉树
BiTree BinaryTree::create()
{
    BiTree current = NULL;
    ElemType val;
    cin >> val;//输入键值

    if(val == '#')//标识当前子树为空，转向下一节点
    {
        return NULL;
    }
    else
    {   //递归的创建左右子树
        size++;
        current = new BiNode(val);
        current->left = create();
        current->right = create();
        return current;
    }
}

//删除二叉树(private 函数)
void BinaryTree ::distroy(BiTree root)
{
    if(root)
    {
        distroy(root->left);
        distroy(root->right);
        delete root;
        root = NULL;
        size = 0;
    }
}

//递归得到树的高度
int BinaryTree::getHeight(BiTree root)
{
    if(root == NULL)
        return 0;
    int left_height = getHeight(root->left);
    int right_height = getHeight(root->right);
    return (left_height>right_height)? (left_height+1):(right_height+1);
}

//前序遍历
void BinaryTree::preOrder(BiTree root)
{
    if(root == NULL)
        return;
    else
    {
        cout << root->data << "  -->  ";     //首先打印根节点
        preOrder(root->left);				 //接着遍历左子树
        preOrder(root->right);				 //接着遍历右子树
    }
}

//中序遍历
void BinaryTree::inOrder(BiTree root)
{
    if(root == NULL)
        return;
    else
    {
        inOrder(root->left);				 //首先遍历左子树
        cout << root->data << "  -->  ";     //接着打印根节点
        inOrder(root->right);				 //接着遍历右子树
    }
}

//后序遍历
void BinaryTree::postOrder(BiTree root)
{
    if(root == NULL)
        return;
    else
    {
        postOrder(root->left);				 //首先遍历左子树
        postOrder(root->right);				 //接着遍历右子树
        cout << root->data << "  -->  ";     //接着打印根节点
    }
}
void BinaryTree::Create()
{
    size = 0;
    m_root = create();
}

//删除二叉树
void BinaryTree ::distroy()
{
    distroy(m_root);
}

//递归得到树的高度
int BinaryTree::getHeight()
{
    return getHeight(m_root);
}

//前序遍历
void BinaryTree::preOrder()
{
    cout << "前序遍历的结果如下："<<endl;
    preOrder(m_root);
    cout << endl;
}

//中序遍历
void BinaryTree::inOrder()
{
    cout << "中序遍历的结果如下："<<endl;
    inOrder(m_root);
    cout << endl;
}

//后序遍历
void BinaryTree::postOrder()
{
    cout << "后序遍历的结果如下："<<endl;
    postOrder(m_root);
    cout << endl;
}

//获取大小
int BinaryTree::getSize()
{
    //这里是创建时候直接进行了计数
    //也可以利用遍历的方式获取，当节点有值，就加1
    return size;
}
int main(){
    BinaryTree tree;
    cout << "按前序遍历方式创建树" <<endl;
//"ABDG##H###CE#I##F##";
    tree.Create();
    cout << "树的高度为：" << tree.getHeight() <<endl;
    cout << "树的节点为：" << tree.getSize() <<endl;
    tree.preOrder();			//前序遍历
    tree.inOrder();				//中序遍历
    tree.postOrder();			//后序遍历
    tree.distroy();				//摧毁树
    return 0;
}
