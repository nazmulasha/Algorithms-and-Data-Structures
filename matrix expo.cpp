#include <bits/stdc++.h>
using namespace std;
long long int mod;
struct matrix{
    long long int arr[2][2];
    void clr()
    {
        arr[0][0]=0;
        arr[0][1]=0;
        arr[1][0]=0;
        arr[1][1]=0;
    }
};
matrix mul(matrix m1, matrix m2)
{
    matrix m;
    m.clr();
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                m.arr[i][j]+=m1.arr[i][k]*m2.arr[k][j];
                m.arr[i][j]%=mod;
            }
        }
    }
    return m;
}
matrix  expo(matrix m1,long long int n)
{
    matrix m;
    m.clr();
    m.arr[0][0]=1;
    m.arr[1][1]=1;
    while(n>0)
    {
        if(n&1)
            m=mul(m,m1);
        m1=mul(m1,m1);
        n>>=1;
    }
    return m;
}
int main()
{
    int tt;
    cin>>tt;
    for(int t=1;t<=tt;t++)
    {
        long long int a,b,n,m;
        cin>>a>>b>>n>>m;
        mod=1;
        while(m--)
            mod*=10;
        matrix m1;
        m1.clr();
        m1.arr[0][0]=1;
        m1.arr[0][1]=1;
        m1.arr[1][0]=1;
        matrix res=expo(m1,n-1);
        long long ans=res.arr[0][0]*b+res.arr[1][0]*a;
        ans%=mod;
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
    return 0;
}
