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
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int a=arr[0];
    int b=arr[1];
    int c=arr[2];
    // int d=arr[4];
    int pgm=3;
    int pgh=0;
    for(int i=3;i<n;)
    {
        
        if(a==arr[i] or b==arr[i] or c==arr[i])
        {
            pgh++;
            i++;
        }
        else
        {
            vector<pair<int,int>> v;
            int aa=n;
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]==a)
                {
                    aa=min(j-i,n-i);
                    break;
                }
            }
            v.push_back({aa,a});
            int bb=n;
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]==b)
                {
                    bb=min(j-i,n-i);
                    break;
                }
            }
            v.push_back({bb,b});
            int cc=n;
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]==c)
                {
                    cc=min(j-i,n-i);
                    break;
                }
            }
            v.push_back({cc,c});
            // cout<<aa<< " "<<bb<<" " <<cc<<endl;
            sort(v.rbegin(),v.rend());
            if(v[0].second==a)
            {
                a=arr[i];
            }
            else if(v[0].second==c)
            {
                c=arr[i];
            }
            else
            {
                b=arr[i];
            }
            // cout<<a<<"< "<<b<<"<"<<c<<i+1<<endl;
            pgm++;
            i++;
        }
    }
    cout<<pgh<<" "<<pgm<<endl;
    

}
