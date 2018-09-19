#include <iostream>
using namespace std;
class Node
{
    friend class List;//把List声明为友类，好在List类中容易访问Node的私有成员。
private:
    char Data;
    Node* next;
} ;//节点有两个数据成员，数据域的字符类型的 Data,以及指向下一个节点的指针域 next。

class List
{
    Node* first;//第一个节点的指针
    Node* end;//最后一个节点的指针。。。这一个数据成员可有可无，我用来记录最后一个节点的指针，添加新元素将会很快。
public:
    //构造函数
    List()
    {
        first=nullptr;
        end=nullptr;
    }
    /*添加元素*/
    Node* push_back(char p_back)
    {
        Node* a=new Node;
        a->Data=p_back;
        a->next=nullptr;
        if(a!=nullptr)
        {
            if (!first) //添加时是第一个节点的情况
            {
                first=a;
                end=a;
            }
            end->next=a;//已添加的最后一个节点的next指针赋值新添加的节点地址
            end=a;//end赋新的节点的地址。

            return end;
        }
    }
    /*显示链表中的各个元素*/
    void print()
    {
        Node* h=first;
        if (!h)
        {
            cout<<"空链表"<<endl;
        }
        else
        {
            while (h)
            {
                cout<<h->Data<<" ";
                h=h->next;
            }
        }
    }
    /*链表元素计数*/
    long count()
    {
        long acount=0;
        Node* start=first;
        while (start) {
            acount++;
            start=start->next;
        }
        return acount;
    }
    /*链表逆序*/
    void reverse()
    {
        //尾指针指向first
        end=first;
        //第一个节点指针域设为Null ，为逆序链表的尾节点,在这之前需要找到下一个节点
        Node* behind=first;//这个指针要做为下一个节点的next域。
        Node* pre=first->next;//当前第一个节点的的next域，靠它寻找第二个节点
        first->next=nullptr;//第一个节点变为尾节点
        first=pre;//first指向第二个节点
        while (first->next!=nullptr)
        {
            pre=first->next;//用于对first赋值
            first->next=behind;
            behind=first;
            first=pre;//first指向第二个节点
        }
        //还得执行最后一步
        first->next=behind;
    }
};



int main(int argc, const char * argv[])
{

    List  a;
    a.push_back('h');
    a.push_back('e');
    a.push_back('l');
    a.print();
    cout<<endl;
    cout<<"该链表有:"<<a.count()<<"个元素。"<<endl;
    cout<<endl;
    cout<<"链表逆序之后输出:"<<endl;
    a.reverse();
    a.print();
    cout<<endl;
    cout<<"该链表有:"<<a.count()<<"个元素。"<<endl;
    return 0;
}
