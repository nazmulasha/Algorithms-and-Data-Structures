#include <bits/stdc++.h>
using namespace std;
#define max 10005
int visited[max],st[max],et[max],ct;
vector <int> adj[max];
vector < pair<int,int> > cp;
void dfs(int start,int f)
{
    int x=start;
    visited[x]=1;
    st[x]=ct;
    et[x]=ct;ct++;
    int si=adj[x].size();
    for(int i=0;i<si;i++)
    {
        int tmp=adj[x][i];
        if(tmp==f)
            continue;
        if(visited[tmp]==0)
        {
            dfs(tmp,x);
            et[x]=min(et[x],et[tmp]);
            if(et[tmp]==st[tmp])
            {
                pair<int,int>p;
                p.first=x;
                p.second=tmp;
                if(p.first>p.second)
                    swap(p.first,p.second);
                cp.push_back(p);
            }
        }
        else
            et[x]=min(et[x],et[tmp]);
    }
}
int main()
{
    int t;scanf("%d",&t);
    for(int ca=1;ca<=t;ca++){
    for(int i=0;i<max;i++)
    {
        visited[i]=0;
        et[i]=0;
        st[i]=0;
        adj[i].clear();
    }
    cp.clear();
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        char c1,c2;
        scanf("%d %c%d%c",&x,&c1,&y,&c2);
        for(int j=0;j<y;j++)
        {
            int k;
            scanf("%d",&k);
            adj[x].push_back(k);
        }
    }
    ct=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
            dfs(i,-1);
    }
    sort(cp.begin(),cp.end());
    printf("Case %d:\n",ca);
    printf("%d critical links\n",cp.size());
    for(int i=0;i<cp.size();i++)
        printf("%d - %d\n",cp[i].first,cp[i].second);
    }
    return 0;
}
