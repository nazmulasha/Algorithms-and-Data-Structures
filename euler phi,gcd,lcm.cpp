#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a,long long int b)
{
    return (b==0)?a:gcd(b,a%b);
}
long long int lcm(long long int a,long long int b)
{
    return (a/gcd(a,b))*b;
}
long long int cubic_root(long long int x)
{
    long long int  l = 0, r = MAXR;
    while (l != r) {
        ll m = (l + r + 1) / 2;
        if (m * m * m > x)
            r = m - 1;
        else
            l = m;
    }
    return l;
}
long long int phi(long long int n)
{
    long long int ans=n;
    for(long long int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            ans-=ans/i;
        while(n%i==0)
            n/=i;
    }
    if(n>1)
        ans-=(ans/n);
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int a,b;
        cin>>a>>b;
        b--;
        long long int ans=phi(a);
        ans=ans*b;
        cout<<ans<<endl;
    }
    return 0;
}
