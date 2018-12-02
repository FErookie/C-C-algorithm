#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
#include "queue"
#include "stack"
#include "cmath"
#include "utility"
#include "map"
#include "set"
#include "vector"
#include "list"
#include "string"
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
enum ResultCode { Underflow, Duplicate, Failure, Success, NotPresent };

template <class T>
class SeqQueue
{
public:
    SeqQueue(int mSize);
    ~SeqQueue() { delete []q; }
    bool IsEmpty() const { return front == rear; } // front与rear相等时循环队列为空
    bool IsFull() const { return (rear + 1) % maxSize == front; } // front与(rear + 1) % maxSize相等时循环队列满
    bool Front(T &x) const;
    bool EnQueue(T x);
    bool DeQueue();
    void Clear() { front = rear = 0; }
    /* data */
private:
    int front, rear, maxSize; // 队头元素 队尾元素 数组最大长度
    T *q;
};
template <class T>
SeqQueue<T>::SeqQueue(int mSize)
{
    maxSize = mSize;
    q = new T[maxSize];
    front = rear = 0;
}
template <class T>
bool SeqQueue<T>::Front(T &x) const
{
    if(IsEmpty()) { // 空队列处理
        cout << "SeqQueue is empty" << endl;
        return false;
    }
    x = q[(front + 1) % maxSize];
    return true;
}
template <class T>
bool SeqQueue<T>::EnQueue(T x)
{
    if(IsFull()) { // 溢出处理
        cout << "SeqQueue is full" << endl;
        return false;
    }
    q[(rear = (rear + 1) % maxSize)] = x;
    return true;
}
template <class T>
bool SeqQueue<T>::DeQueue()
{
    if(IsEmpty()) { // 空队列处理
        cout << "SeqQueue is empty" << endl;
        return false;
    }
    front = (front + 1) % maxSize;
    return true;
}
template <class T>
class Graph
{
public:
    virtual	~Graph() {};
    virtual ResultCode Insert(int u, int v, T &w) = 0;
    virtual ResultCode Remove(int u, int v) = 0;
    virtual bool Exist(int u, int v) const = 0;
    /* data */
};
template <class T>
class MGraph: public Graph<T>
{
public:
    MGraph(int mSize, const T& noedg);
    ~MGraph();
    ResultCode Insert(int u, int v, T &w);
    ResultCode Remove(int u, int v);
    bool Exist(int u, int v) const;
    int Vertices() const { return n; }
    void Output();
    void DFS();
    void BFS();
protected:
    T **a;
    T noEdge;
    int n, e;
    void DFS(int v, bool *vis);
    void BFS(int v, bool *vis);
    /* data */
};
template <class T>
void MGraph<T>::Output()
{
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j)
            if(a[i][j] == noEdge) cout << "NE\t";
            else cout << a[i][j] << "\t";
        cout << endl;
    }
    cout << endl << endl << endl;
}
template <class T>
MGraph<T>::MGraph(int mSize, const T &noedg)
{
    n = mSize, e = 0, noEdge = noedg;
    a = new T *[n];
    for(int i = 0; i < n; ++i) {
        a[i] = new T[n];
        for(int j = 0; j < n; ++j)
            a[i][j] = noEdge;
        a[i][i] = 0;
    }
}
template <class T>
MGraph<T>::~MGraph()
{
    for(int i = 0; i < n; ++i)
        delete []a[i];
    delete []a;
}
template <class T>
bool MGraph<T>::Exist(int u, int v) const
{
    if(u < 0 || v < 0 || u > n - 1 || v > n - 1 || u == v || a[u][v] == noEdge) return false;
    return true;
}
template <class T>
ResultCode MGraph<T>::Insert(int u, int v, T &w)
{
    if(u < 0 || v < 0 || u > n - 1 || v > n - 1 || u == v) return Failure;
    if(a[u][v] != noEdge) return Duplicate;
    a[u][v] = w;
    e++;
    return Success;
}
template <class T>
ResultCode MGraph<T>::Remove(int u, int v)
{
    if(u < 0 || v < 0 || u > n - 1 || v > n - 1 || u == v) return Failure;
    if(a[u][v] == noEdge) return NotPresent;
    a[u][v] = noEdge;
    e--;
    return Success;
}
template <class T>
void MGraph<T>::DFS()
{
    bool *vis = new bool[n];
    memset(vis, false, n);
    for(int i = 0; i < n; ++i)
        if(!vis[i]) DFS(i, vis);
    delete []vis;
}
template <class T>
void MGraph<T>::DFS(int v, bool *vis)
{
    vis[v] = true;
    cout << ' ' << v;
    for(int i = 0; i < n; ++i)
        if(a[v][i] != noEdge && a[v][i] != 0 && !vis[i]) DFS(i, vis);
}
template <class T>
void MGraph<T>::BFS()
{
    bool *vis = new bool[n];
    memset(vis, false, n);
    for(int i = 0; i < n; ++i)
        if(!vis[i]) BFS(i, vis);
    delete []vis;
}
template <class T>
void MGraph<T>::BFS(int v, bool *vis)
{
    SeqQueue<int> q(n);
    vis[v] = true;
    cout << ' ' << v;
    q.EnQueue(v);
    while(!q.IsEmpty()) {
        q.Front(v);
        q.DeQueue();
        for(int i = 0; i < n; ++i)
            if(a[v][i] != noEdge && a[v][i] != 0 && !vis[i]) {
                vis[i] = true;
                cout << ' ' << i;
                q.EnQueue(i);
            }
    }
}
template <class T>
struct ENode
{
    ENode() { nxtArc = NULL; }
    ENode(int vertex, T weight, ENode *nxt) {
        adjVex = vertex;
        w = weight;
        nxtArc = nxt;
    }
    int adjVex;
    T w;
    ENode *nxtArc;
    /* data */
};
template <class T>
class LGraph: public Graph<T>
{
public:
    LGraph(int mSize);
    ~LGraph();
    ResultCode Insert(int u, int v, T &w);
    ResultCode Remove(int u, int v);
    bool Exist(int u, int v) const;
    int Vertices() const { return n; }
    void Output();
protected:
    ENode<T> **a;
    int n, e;
    /* data */
};
template <class T>
void LGraph<T>::Output()
{
    ENode<T> *q;
    for(int i = 0; i < n; ++i) {
        q = a[i];
        while(q) {
            cout << '(' << i << ' ' << q -> adjVex << ' ' << q -> w << ')';
            q = q -> nxtArc;
        }
        cout << endl;
    }
    cout << endl << endl;
}
template <class T>
LGraph<T>::LGraph(int mSize)
{
    n = mSize;
    e = 0;
    a = new ENode<T>*[n];
    for(int i = 0; i < n; ++i)
        a[i] = NULL;
}
template <class T>
LGraph<T>::~LGraph()
{
    ENode<T> *p, *q;
    for(int i = 0; i < n; ++i) {
        p = a[i];
        q = p;
        while(p) {
            p = p -> nxtArc;
            delete q;
            q = p;
        }
    }
    delete []a;
}
template <class T>
bool LGraph<T>::Exist(int u, int v) const
{
    if(u < 0 || v < 0 || u > n - 1 || v > n - 1 || u == v) return false;
    ENode<T> *p = a[u];
    while(p && p -> adjVex != v) p = p -> nxtArc;
    if(!p) return false;
    return true;
}
template <class T>
ResultCode LGraph<T>::Insert(int u, int v, T &w)
{
    if(u < 0 || v < 0 || u > n - 1 || v > n - 1 || u == v) return Failure;
    if(Exist(u, v)) return Duplicate;
    ENode<T> *p = new ENode<T>(v, w, a[u]);
    a[u] = p;
    e++;
    return Success;
}
template <class T>
ResultCode LGraph<T>::Remove(int u, int v)
{
    if(u < 0 || v < 0 || u > n - 1 || v > n - 1 || u == v) return Failure;
    ENode<T> *p = a[u], *q = NULL;
    while(p && p -> adjVex != v) {
        q = p;
        p = p -> nxtArc;
    }
    if(!p) return NotPresent;
    if(q) q -> nxtArc = p -> nxtArc;
    else a[u] = p -> nxtArc;
    delete p;
    e--;
    return Success;
}
int main(int argc, char const *argv[])
{
    int n, g;
    cout << "请输入元素的个数: ";
    cin >> n;
    MGraph<int> A(n, INF);
    LGraph<int> B(n);
    cout << "请输入边的条数: ";
    cin >> g;
    int *a = new int[g];
    int *b = new int[g];
    int *w = new int[g];
    for(int i = 0; i < g; ++i)
    {
        cout << "请输入边及权值: ";
        cin>> a[i] >> b[i] >> w[i];
        A.Insert(a[i], b[i], w[i]);
        B.Insert(a[i], b[i], w[i]);
    }
    cout << "该图的深度优先遍历为:" << endl;
    A.DFS();
    cout << endl;
    cout << "该图的广度优先遍历为:" << endl;
    A.BFS();
    cout << endl;
    return 0;
}
