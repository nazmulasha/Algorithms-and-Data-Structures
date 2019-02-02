#include <bits/stdc++.h>
using namespace std;
#define mx 1000002
long long int tree[4*mx];
long long int prop[4*mx];
void update(int node,int left,int right,int i,int j,int v)
{
    if(i>right||j<left)
        return;
    if(left>=i&&right<=j)
    {
        prop[node]+=v;
    }
    else
    {
        int mid=(left+right)/2;
        tree[node]+=v*(long long int)(min(j,right)-max(i,left)+1);
        update(2*node,left,mid,i,j,v);
        update(2*node+1,mid+1,right,i,j,v);
    }
}
long long int query(int node,int left,int right,int i,int j)
{
    if(i>right||j<left)
        return 0;
    tree[node]+=prop[node]*(long long int)(right-left+1);
    if(left!=right)
    {
        prop[2*node]+=prop[node];
        prop[2*node+1]+=prop[node];
    }
    prop[node]=0;
    int mid=(right+left)/2;
    if(left>=i&&right<=j)
        return tree[node];
    else
        return query(2*node,left,mid,i,j)+query(2*node+1,mid+1,right,i,j);
}
int main()
{
    int tt;
    cin>>tt;
    for(int t=1;t<=tt;t++)
    {
        int n,q;
        cin>>n>>q;
        memset(tree,0,sizeof(tree));
        memset(prop,0,sizeof(prop));
        while(q--)
        {
            int a;
            cin>>a;
            if(a==0)
            {
                int i,j,v;
                cin>>i>>j>>v;
                i--;
                j--;
                update(1,0,n-1,i,j,v);
            }
            else
            {
                int i,j;
                cin>>i>>j;
                i--;
                j--;
                cout<<query(1,0,n-1,i,j)<<endl;
            }}}
    return 0;
}
