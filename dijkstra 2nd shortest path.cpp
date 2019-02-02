
//shortest and 2nd shortest path using dijkstra
#include<bits/stdc++.h>
#define fi(n, m) for(int i=n; i<=m; i++)
#define ll long long
using namespace std;
vector<ll>vt[5009], cost[5009];
ll n, en, d1[5009], d2[5009], sz;
priority_queue< ppi, vector< ppi >, greater< ppi > > Q;
struct node{
    ll u, w;
    node(ll a, ll b){
        u=a, w=b;
    }
    bool operator < (const node & p)const{
        return p.w<w;
    }
};

void dijkstra(int st){
    priority_queue<node>q;
    q.push(node(st, 0));
    fi(1, n){d1[i]=30000000, d2[i]=30000000;}
    d1[st]=0;
    while(!q.empty()){
        node top=q.top();
        q.pop();
        int u=top.u;
        sz=vt[u].size();
        fi(0, sz-1){
            int v=vt[u][i];
            int uu=cost[u][i];
            if(d1[u]+uu<d1[v]){
                ll temp=d1[v];
                d1[v]=d1[u]+uu;
                d2[v]=min(temp, min(d2[v], min(d2[u]+uu, d1[u]+3*uu)));
                q.push(node(v, d1[v]+d2[v]));
            }
            else if(d1[u]+uu<d2[v] && (d1[u]+uu)>d1[v]){
                d2[v]=d1[u]+uu;
            }
            else{
                d2[v]=min(d2[v], min(d2[u]+uu, d1[u]+3*uu));
            }
        }
    }
}

int main(){
    int t, cs=1, st, e, u, v, w, nn, ans;
    cin>>t;
    while(t--){
        cin>>n>>e;
        fi(1, e){
            cin>>u>>v>>w;
            vt[u].push_back(v);
            vt[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        ll back=100000009;
        fi(0, vt[1].size()-1){
            back=min(back, 2*cost[1][i]);
        }
        dijkstra(1);
        back=d1[n]+back;
        cout<<"Case "<<cs++<<": "<<min(back, d2[n])<<endl;
        fi(0, n){
            vt[i].clear(); cost[i].clear();
        }
    }
    return 0;
}
