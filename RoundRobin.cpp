///Not Exactly Round Robin
#include<bits/stdc++.h>
using namespace std;
struct proc
{
    int no,at,bt,ct,status;
};
struct proc read(int i)
{
    cout<<"Process Number-> "<<i<<endl;
    struct proc p;
    p.no=i;
    cin>>p.at>>p.bt;
    p.status=0;
    return p;

}
int main()
{
    cout<<"Number of Processes : ";
    int n;
    cin>>n;
    struct proc p[10],temp;
    for(int i=0;i<n;i++)
    {
        p[i]=read(i+1);
    }
    cout<<"Time Quantum :";
    int tq;
    cin>>tq;
    int rem=n;
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
    //for(int i=0;i<n;i++)

    int ct=p[0].at;
    while(rem!=0)
    {
        for(int i=0;i<n;i++)
        {
            if(tq>=p[i].bt and p[i].status!=1 and ct>=p[i].at)
            {
                ct+=p[i].bt;
                p[i].status=1;
                p[i].ct=ct;
                rem--;
            }
            else if(tq<p[i].bt and p[i].status==0 and ct>=p[i].at)
            {
                ct+=tq;
                p[i].bt-=tq;
            }
            //cout<<p[i].no<<" "<<ct<<endl;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<" "<<p[i].ct<<endl;
    }


}
