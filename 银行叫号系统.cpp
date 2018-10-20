//#include <iostream>
//#include <queue>
//#include <list>
//using namespace std;
//class User{
//public:
//    int id;
//    int isWait;
//    int ArriveTime;
//    int serveTime;
//    char type;
//    void getServed();
//
//    void setId(int id){
//        this -> id = id;
//    }
//
//    void setType(char c){
//        this -> type = c;
//    }
//
//};
//
//class NormalUser:public User{
//    void getServed();
//};
//
//class vipUser:public User{
//    void getServed();
//};
//
//class OfficeUser:public User{
//    void getServed();
//};
//
//class BankWindow{
//public:
//    bool isBusy;
//    int id;
//    User client;
//    char type;
//    void HandleUser();
//};
//
//class NormalBankWiondow:public BankWindow{
//    void HandleUser();
//};
//
//class VIPBankwindow:public BankWindow{
//    void HandleUser();
//};
//
//class OfficeBankWindow:public BankWindow{
//    void HandleUser();
//};
//
//class Simulater{
//public:
//    queue<NormalUser> NormalUserQueue[3];
//    queue<vipUser> VIPuser;
//    queue<OfficeUser> OfficeUserQueue;
//    list<NormalBankWiondow> nbw;
//    list<VIPBankwindow> vbw;
//    list<OfficeUser> obw;
//    int findMinQueue(){
//        int min = 0;
//        for(int i = 0 ; i < 3 ; i++){
//            if(NormalUserQueue[min].size() < NormalUserQueue[i].size()){
//                min = i;
//            }
//        }
//        return min;
//    }
//    void customerEnter(){
//        User temp;
//        char temp_type;
//        cout << "欢迎你用户" << "清选择你的用户种类" << ": n -- 普通用户 , v -- vip 用户" << "o -- 对公用户" endl;
//        cin >> temp_type;
//        while(temp_type != 'n' && temp_type != 'v' && temp_type != 'o' ){
//            cout << "你输入的用户种类不正确 , 清重新输入" << endl;
//            cin >> temp_type;
//        }
//        temp.setType(temp_type);
//
//    };
//    void simulateCustomEnter();
//    void simulateCallCustomer();
//    void Simulate();
//};
//
//
//int main(){
//    NormalUser user1;
//    return 0;
//}
#include <iostream>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include "windows.h"

using namespace std;

int AverageTime;//平均时间

void  DisplayWindows(int presenttime,int seringtime, int unittime)
{
    cout<<"************模拟银行叫号系统*************"<<endl;
    cout<<"***********银行服务时间0--"<<seringtime<<"************"<<endl;
    cout<<"**该叫号系统每隔"<<unittime<<"单位时间显示窗口信息****"<<endl;
    cout<<"当前时间为"<<presenttime<<""<<endl;
}

class Customer/*顾客信息*/
{
public:
    Customer()
    {
        SerTime=0;
        enterTime=0;
        startTime=0;
        cID=0;
        endTime=0;
    }
    void Reset()
    {
        SerTime=0;
        enterTime=0;
        startTime=0;
        cID=0;
        endTime=0;
    }
    Customer(const Customer& anthercustomer)//复制构造函数
    {
        enterTime=anthercustomer.enterTime;
        startTime=anthercustomer.startTime;
        servDurance=anthercustomer.servDurance;
        SerTime=anthercustomer.SerTime;
        cID=anthercustomer.cID;
        endTime=anthercustomer.endTime;
    }
    void SetSevTime(int serT)
    {
        SerTime=serT;
    }
    int GetID()
    {
        return cID;
    }
    int GetEndTime()
    {
        return endTime;
    }
    int GetStartTime()
    {
        return startTime;
    }
    int GetSerDurance()//顾客等待时间
    {
        return (startTime-enterTime);
    }
    int GetSerTime()
    {
        return SerTime;
    }
    void SetEnterTime(int enterT)
    {
        enterTime=enterT;
    }
    void SetEndTime(int endT)
    {
        endTime=endT;
    }
    void SetID(int ID)
    {
        cID=ID;
    }
    void SetSartTime(int startT)
    {
        startTime=startT;
    }
private:
    int enterTime,startTime,SerTime,servDurance,cID,endTime;
};

class Bank
{
public:
    void ResetBank()
    {
        while(!servingcustomer.empty())
            servingcustomer.pop();
        while(!waitingcustomer.empty())
            waitingcustomer.pop();
    }
    bool Assign(Customer customer)//判断服务窗口有没有完成服务
    {
        if(customer.GetEndTime()-customer.GetStartTime()==customer.GetSerTime())
            return true;
        else
            return false;
    }
    void DisplayWaitingTime(queue<Customer> quecus)
    {
        AverageTime=0;
        cout<<"顾客及等待时间:"<<endl;
        while(!quecus.empty())
        {
            cout<<"顾客"<<quecus.front().GetID()<<": "<<quecus.front().GetSerDurance()<<"  ";
            AverageTime+=quecus.front().GetSerDurance();
            quecus.pop();
        }
        cout<<endl;
    }
    queue<Customer> GetCustomerQueue(queue<Customer> queuec)
    {
        queue<Customer> temp;
        while(!queuec.empty())
        {
            temp.push(queuec.front());
            queuec.pop();

        }
        return temp;
    }
    queue<Customer> servingcustomer;
    queue<Customer> waitingcustomer;
};

int main()
{
    Bank Bank1;
    Bank1.ResetBank();
    queue<Customer> CustomerTrack;
    queue<Customer> CustomerTrack2;
    Customer ser1,ser2,ser3,ser4,ser5;
    int num[5]={0};
    srand((unsigned) time(0));//播种子
    const int TimeSlot=100;//假设服务时间段为0-100
    const int UnitTime=10;//单位时间为10
    const int ServTime=7;//服务时间为1-7
    const int UnitTimePeo=10;//单位时间进来的人数为0-9
    const int StopEnterTime=80;//为了保证所有顾客能完成服务，顾客进入的时间为0-80
    int PresentTime=0;//初始化当前时间为0
    int PerTime=5;//每隔5秒显示一次窗口信息
    int NumberOfCustomer=0;
    int TimeOfServing=0;
    int IDtrack=0;
    while(PresentTime<TimeSlot)
    {
        Customer tempCustomer;
        NumberOfCustomer=rand()%UnitTimePeo;
        for(int j=0; j<NumberOfCustomer;j++)
        {
            tempCustomer.SetID(++IDtrack);
            TimeOfServing=1+rand()%ServTime;
            tempCustomer.SetSevTime(TimeOfServing);
            tempCustomer.SetEnterTime(PresentTime);
            Bank1.waitingcustomer.push(tempCustomer);
        }
        int nnn=0;
        for(int t=0;t<UnitTime+nnn;t++)
        {
            if(Bank1.Assign(ser1))//窗口1完成
            {
                if(ser1.GetID()!=0)
                    CustomerTrack.push(ser1);
                ser1.Reset();
                if(!Bank1.waitingcustomer.empty())
                {
                    ser1=Bank1.waitingcustomer.front();
                    ser1.SetSartTime(PresentTime);
                    ser1.SetEndTime(PresentTime);
                    Bank1.waitingcustomer.pop();
                    Bank1.servingcustomer.push(ser1);
                    num[0]++;
                }
            }
            else
            {
                ser1.SetEndTime(PresentTime);
            }
            if(Bank1.Assign(ser2))//窗口2完成
            {
                if(ser2.GetID()!=0)
                    CustomerTrack.push(ser2);
                ser2.Reset();
                if(!Bank1.waitingcustomer.empty())
                {
                    ser2=Bank1.waitingcustomer.front();
                    ser2.SetSartTime(PresentTime);
                    ser2.SetEndTime(PresentTime);
                    Bank1.waitingcustomer.pop();
                    Bank1.servingcustomer.push(ser2);
                    num[1]++;
                }
            }
            else
            {
                ser2.SetEndTime(PresentTime);
            }
            if(Bank1.Assign(ser3))//窗口3完成
            {
                if(ser3.GetID()!=0)
                    CustomerTrack.push(ser3);
                ser3.Reset();
                if(!Bank1.waitingcustomer.empty())
                {
                    ser3=Bank1.waitingcustomer.front();
                    ser3.SetSartTime(PresentTime);
                    ser3.SetEndTime(PresentTime);
                    Bank1.waitingcustomer.pop();
                    Bank1.servingcustomer.push(ser3);
                    num[2]++;
                }
            }
            else
            {
                ser3.SetEndTime(PresentTime);
            }
            if(Bank1.Assign(ser4))//窗口4完成
            {
                if(ser4.GetID()!=0)
                    CustomerTrack.push(ser4);
                ser4.Reset();
                if(!Bank1.waitingcustomer.empty())
                {
                    ser4=Bank1.waitingcustomer.front();
                    ser4.SetSartTime(PresentTime);
                    ser4.SetEndTime(PresentTime);
                    Bank1.waitingcustomer.pop();
                    Bank1.servingcustomer.push(ser4);
                    num[3]++;
                }
            }
            else
            {
                ser4.SetEndTime(PresentTime);
            }
            if(Bank1.Assign(ser5))//窗口5完成
            {
                if(ser5.GetID()!=0)
                    CustomerTrack.push(ser5);
                ser5.Reset();
                if(!Bank1.waitingcustomer.empty())
                {
                    ser5=Bank1.waitingcustomer.front();
                    ser5.SetSartTime(PresentTime);
                    ser5.SetEndTime(PresentTime);
                    Bank1.waitingcustomer.pop();
                    Bank1.servingcustomer.push(ser5);
                    num[4]++;
                }
            }
            else
            {
                ser5.SetEndTime(PresentTime);
            }
            if(PresentTime%PerTime==0)
            {
                CustomerTrack2=Bank1.GetCustomerQueue(Bank1.servingcustomer);
                system("cls");
                DisplayWindows(PresentTime,TimeSlot,PerTime);
                /*显示窗口1-5的服务ID*/
                cout<<endl;
                cout<<"**当前时间窗口服务的顾客的ID，0为没有顾客**"<<endl;
                cout<<"窗口1的ID："<<ser1.GetID()<<"  ";
                cout<<"窗口2的ID："<<ser2.GetID()<<"  ";
                cout<<"窗口3的ID："<<ser3.GetID()<<"  ";
                cout<<"窗口4的ID："<<ser4.GetID()<<"  ";
                cout<<"窗口5的ID："<<ser5.GetID()<<endl;
                /*显示正在等待的顾客的数量*/
                cout<<"正在等待的顾客的数量:"<<Bank1.waitingcustomer.size()<<endl;
                cout<<endl;
                Bank1.DisplayWaitingTime(CustomerTrack2);
                Sleep(2000);
            }
            PresentTime++;
            if(PresentTime==80)
                nnn=20;
        }
    }
    int TotalNum=0;
    for(int rr=0;rr<5;rr++)
    {
        cout<<"窗口"<<rr+1<<"服务顾客数量："<<num[rr]<<endl;
        TotalNum+=num[rr];
    }
    //cout<<"顾客平均等待时间为："<<static_cast<double>(AverageTime)/static_cast<double>(TotalNum)<<endl;
    system("pause");
    return 0;
}
