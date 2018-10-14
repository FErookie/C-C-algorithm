
#include <iostream>
#include<stack>
using namespace std;
typedef struct point
{
    int x;
    int y;
}point;

int main() {
    stack<point> st;
    int mg2[20][20]={0};//记录该路径是否走过，防止进入死循环
    int mg[100][100]= {
            {
                    0,0,0,0,0,0,0,0,0,0
            },
            {
                    0,1,1,0,1,1,1,0,1,0
            },
            {
                    0,1,1,0,1,1,1,0,1,0
            },
            {
                    0,1,1,1,1,0,0,1,1,0
            },
            {
                    0,1,0,0,0,1,1,1,1,0
            },
            {
                    0,1,1,1,0,1,1,1,1,0
            },
            {
                    0,1,0,1,1,1,0,1,1,0
            },
            {
                    0,1,0,0,0,1,0,0,1,0
            },
            {
                    0,0,1,1,1,1,1,1,1,0
            },
            {
                    0,0,0,0,0,0,0,0,0,0
            }
    };
    int i,j,k;
    point a,b;
    a.x=1,a.y=1;
    st.push(a);
    while(!(b.x==8&&b.y==8)&&!(st.empty()))
    {
        b=st.top();
        i=b.y;
        j=b.x;
        if(mg[i][j+1]==1&&mg2[i][j+1]==0) {
            b.x=j+1;
            mg2[i][j+1]=1;
            st.push(b);
        }
        else if(mg[i+1][j]==1&&mg2[i+1][j]==0) {
            b.y=i+1;
            mg2[i+1][j]=1;
            st.push(b);
        }
        else if(mg[i][j-1]==1&&mg2[i][j-1]==0) {
            b.x=j-1;
            mg2[i][j-1]=1;
            st.push(b);
        }
        else if(mg[i-1][j]==1&&mg2[i-1][j]==0) {
            b.y=i-1;
            mg2[i-1][j]=1;
            st.push(b);
        }
        else{ 
            st.pop();
        };
    }
    while(!(st.empty())){
        b=st.top();
        cout<<"x: "<<b.x<<"y: "<<b.y<<endl;
        st.pop();
    }
    return 0;
}
