#include <bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define pc(x) printf("%d\n",x)
int merge(int arr[],int p,int q,int r)
{
    int count=0;
    int i,j=1,k,s1=q-p+1,s2=r-q;
    int lr[s1+2],rs[s2+2];
    for(i=1;i<=s1;i++)
        lr[i]=arr[p+i-1];
    for(i=1;i<=s2;i++)
        rs[i]=arr[q+i];
    i=1;
    lr[s1+1]=INT_MAX;
    rs[s2+1]=INT_MAX;
    for(k=p;k<=r;k++)
    {
        if(lr[i]>rs[j])
        {
            if(lr[i]!=INT_MAX)
                count+=(s1-i+1);
            arr[k]=rs[j];
            j++;
        }
        else
        {
            arr[k]=lr[i];
            i++;
        }
    }
    return count;
}
int divide(int arr[],int p,int r)
{
    int ans=0;
    if(p<r)
    {
        int q=(p+r)/2;
        ans+=divide(arr,p,q);
        ans+=divide(arr,q+1,r);
        ans+=merge(arr,p,q,r);
    }
    return ans;
}
int main()
{
    int n;
    sc(n);
    int arr[n+1],i;
    for(i=1;i<=n;i++)
        sc(arr[i]);
    pc(divide(arr,1,n));
    return 0;
}
