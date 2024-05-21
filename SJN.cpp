#include<bits/stdc++.h>
using namespace std;
struct proc
{
    int at,bt,ct,no,wt,tat,status;
};
struct proc read(int i)
{
    struct proc p;
    cout<<"process num : "<<i<<endl;;
    p.no=i;
    cin>>p.at>>p.bt;
    p.status=0;
    return p;
};
int main()
{

    int n;
    cin>>n;
    struct proc p[10],temp;
    for(int i=0;i<n;i++)
    {
        p[i]=read(i+1);
    }
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n-1;j++)
        {

            if(p[j].at>p[j+1].at)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;

            }
        }
    }
    int rem=n;
    p[9].bt=500;
    for(int ct=p[0].at;rem!=0;)
    {
        int l=9;
        for(int i=0;i<n;i++)
        {
            if(p[i].at<=ct and p[i].status!=1 and p[i].bt<p[l].bt)
            {
                l=i;
            }
        }
        ct+=p[l].bt;
        //cout<<ct<<endl;
        p[l].ct=ct;
        p[l].status=1;
        cout<<p[l].no<<p[l].ct<<endl;
        rem--;
    }
}
