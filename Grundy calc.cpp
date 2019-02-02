#include <bits/stdc++.h>

using namespace std;
#define mx 10001
int dp[mx];
int ss[mx];

void work()
{
    memset(dp,0,sizeof(dp));
    memset(ss,0,sizeof(ss));
    for(int i=3;i<mx;i++)
    {
        for(int j=1,k=i-1;j<k;j++,k--)
            ss[dp[j]^dp[k]]=i;
        for(int j=0;j<=i;j++)
        {
            if(ss[j]!=i)
            {
                dp[i]=j;
                break;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    work();
    int tt;
    cin>>tt;
    for(int t=1;t<=tt;t++)
    {
        int n,xsum=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            xsum^=dp[x];
        }
        if(xsum)
            cout<<"Case "<<t<<": Alice"<<endl;
        else
            cout<<"Case "<<t<<": Bob"<<endl;
    }
}
