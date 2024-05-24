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
    int ct=p[0].at;
    while(rem!=0)
    {
        for(int i=0;i<n;)
        {

            if(ct>=p[i].at and p[i].status!=1)
            {

                ct+=p[i].bt;
                p[i].ct=ct;
                p[i].status=1;
                rem--;
                i++;
            }
            else{
                ct++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {

        cout<<p[i].no<<" "<<p[i].ct<<endl;
    }
}

