#include <bits/stdc++.h>

using namespace std;

long long int addMod(long long int a, long long int b, long long int m) {
    if (a + b < 0)
        return (a - m) + b;
    else if (a + b >= m)
        return a + b - m;
    else
        return a + b;
}

long long int  multiplyMod(long long int a, long long int b, long long int m) {
    if (b == 0 || a <= LLONG_MAX / b)
        return a * b % m;
    long long int result = 0;
    if (a > b) {
        long long int c = b;
        b = a;
        a = c;
    }
    while (a > 0) {
        if ((a & 1) != 0) {
            result = addMod(result, b, m);
        }
        a >>= 1;
        b -= m - b;
        if (b < 0)
            b += m;
    }
    return result;
}

long long int power(long long int b,long long int p,long long int m)
{
    if(p==0)
        return 1;
    else if(p%2==0)
    {
        long long int tmp=power(b,p/2,m)%m;
        return (multiplyMod(tmp,tmp,m))%m;
    }
    else
        return (multiplyMod(b%m,power(b,p-1,m)%m,m))%m;
}

int main()
{
    int tt;
    scanf("%d",&tt);
    for(int t=1;t<=tt;t++)
    {
        long long int b,p,m;
        scanf("%lld %lld %lld",&b,&p,&m);
        long long int ans=power(b,p,m);
        printf("Case %d: %lld\n",t,ans);

    }
    return 0;
}
