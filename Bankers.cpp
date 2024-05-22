#include<bits/stdc++.h>
using  namespace  std;

struct proc
{
   int no,a,b,c,status;

};
struct proc read(int i)
{
    struct proc p;
    printf(" Process no : %d\n", i);
    p.no=i;
    cin>>p.a>>p.b>>p.c;
    p.status=0;
    return p;
}
struct proc read2(int i)
{
    struct proc p;
    p.no=i;
    cin>>p.a>>p.b>>p.c;
    return p;
}
int main()
{
    struct proc allocat[10],mx[10],need[10];
    int n;
    cin>>n;
    cout<<"Allocate Matrix : \n";
    for(int i=0;i<n;i++)
    {
        allocat[i]=read(i+1);
    }
    cout<<"Max Matrix \n";
    for(int i=0;i<n;i++)
    {
        mx[i]=read2(i+1);
    }
    for(int i=0;i<n;i++)
    {

        need[i].a=(mx[i].a-allocat[i].a);
        need[i].b=(mx[i].b-allocat[i].b);
        need[i].c=(mx[i].c-allocat[i].c);
        cout<<need[i].a<<" "<<need[i].b<<" "<<need[i].c<<endl;
    }
    cout<<"Avable Numbers :\n";
    int x,y,z;
    cin>>x>>y>>z;
    int rem=n;
    int j=0;
    for(;rem!=0;)
    {
        while(j<n)
        {
            if(need[j].a<=x and need[j].b<=y and need[j].c<=z and allocat[j].status!=1)
            {
                x+=allocat[j].a;
                y+=allocat[j].b;
                z+=allocat[j].c;

                allocat[j].status=1;
                rem--;
                cout<<"P"<<j+1<<endl;
            }
            j++;
            if(j==n)
            {
                j=0;
            }
            if(rem==0)break;
        }
    }

}
