#include<bits/stdc++.h>
using  namespace  std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    int n;
    cin>>n;
    queue<pair<int,int>>q;
    int arrv[n],brust[n];
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        arrv[i]=x;
        brust[i]=y;
        q.push({y,x});
    }
    int tq;
    cin>>tq;
    int ct[n];
    int time=0;
    while(!q.empty())
    {
        auto x=q.front();
        q.pop();
        int bt=x.first;
        int at=x.second;
        if(bt<=tq)
        {
            time+=bt;
            ct[at]=time;
        }
        else
        {
            time+=tq;
            bt-=tq;
            q.push({bt,at});
        }
    }
    cout<<"completion time"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<ct[i]<<endl;
    }
    cout<<"Turn around Time & Waiting time"<<endl;
    for(int i=0;i<n;i++)
    {
        int p=ct[i]-arrv[i];
        int q=p- brust[i];
        cout<<p<<"       "<<q<<endl;

    }
    

}
input
6
0 7
1 4
2 15
3 11
4 20
5 9
5
output:
completion time
0 31
1 9
2 55
3 56
4 66
5 50
Turn around Time & Waiting time
31       24
8       4
53       38
53       42
62       42
45       36
