#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define lc o<<1
#define rc o<<1|1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const double PI = acos(-1.0);
const double eps = 1e-10;
int dcmp(double x) { if(fabs(x) < eps) return 0;
else return x<0?-1:1; }
const int INF = 0x3f3f3f3f;
const int N = 1e6+5;
char str[N];
int ql, qr;
struct node {
    int lb, rb, num;
    node() { lb = rb = num = 0; }
}a[4*N];

void build(int o, int L, int R) {
    if(L == R) {
        a[o].num = a[o].lb = a[o].rb = 0;
        if(str[L] == 'C') a[o].rb++;
        else a[o].lb++;
        return;
    }
    int M = (L+R)>>1;
    build(lc, L, M);
    build(rc, M+1, R);
    int t = min(a[lc].lb, a[rc].rb);
    a[o].num = a[lc].num+a[rc].num+t*2;
    a[o].lb = a[rc].lb+a[lc].lb-t;
    a[o].rb = a[rc].rb+a[lc].rb-t;
}
void update(int o, int L, int R,int i,int j)
{
    if (i > R || j < L)
        return;
    if (L >= i && R <= j)
    {
        a[o].num = a[o].lb = a[o].rb = 0;
        if(str[i]=='O')
        {
            str[i]='C';
            a[o].rb++;
        }
        else
        {
            str[i]='O';
            a[o].lb++;
        }
        return;
    }
    int M = (L+R)>>1;
    update(lc, L, M,i,j);
    update(rc, M+1, R,i,j);
    int t = min(a[lc].lb, a[rc].rb);
    a[o].num = a[lc].num+a[rc].num+t*2;
    a[o].lb = a[rc].lb+a[lc].lb-t;
    a[o].rb = a[rc].rb+a[lc].rb-t;
}
node query(int o, int L, int R) {
    if(ql<=L && qr>=R) return a[o];
    int M = (L+R)>>1;
    node u, v;
    if(ql <= M) u = query(lc, L, M);
    if(qr > M) v = query(rc, M+1, R);
    int t = min(u.lb, v.rb);
    u.num = u.num+v.num+t*2;
    u.lb = u.lb+v.lb-t;
    u.rb = u.rb+v.rb-t;
    return u;
}
int main() {
    scanf("%s", str+1);
    int n = strlen(str+1), m;
    cin>>m;
    build(1,1,n);
    while(m--)
    {
        char c;
        cin>>c;
        if(c=='R')
        {
            int in;
            cin>>in;
            update(1,1,n,in,in);
        }
        else
        {
            cin>>ql>>qr;
            cout<<query(1,1,n).num<<endl;
        }
    }
    return 0;
}
