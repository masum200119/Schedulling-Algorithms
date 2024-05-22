#include<bits/stdc++.h>
using  namespace  std;

struct proc
{
   int no,at,bt,ct,wt,tat,pri,status; 
};
struct proc read(int i)
{
    struct proc p;
    printf(" Process no : %d\n", i);
    p.no=i;
    cin>>p.at>>p.bt>>p.pri;
    p.status=0;
    return p;

}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,l;
    cin>>n;
    struct proc p[10],temp;
    for(int i=0;i<n;i++)
    {
        p[i]=read(i+1);
    }
    // int temp;
    for(int i=0;i<n-1;i++)
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
    p[9].pri=INT_MIN;
    for(int ct=p[0].at;rem!=0;)
    {
        l=9;
        for(int i=0;i<n;i++)
        {
            if(p[i].at<=ct and p[i].status!=1 and p[i].pri>p[l].pri)
            {
                l=i;
            }
        }
        p[l].ct=ct=ct+=p[l].bt;
        cout<<p[l].ct<<endl;rem--;
    }
    
    

}
