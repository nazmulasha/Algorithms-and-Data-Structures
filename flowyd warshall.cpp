#include <bits/stdc++.h>
using namespace std;

int dist[1001][1001];  //distance
int next[1001][1001];  //path store
int cost[1001];        //cost

int main()
{
    int  m, cases = 0;
    char buf[10000];
    scanf("%d", &m);
    while (m --) {
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                next[i][j] = j;
            }
        }
        // floyd
        for (int k = 1; k <= n; ++ k) {
            for (int i = 1; i <= n; ++ i) {
                for (int j = 1; j <= n; ++ j) {
                    if (dist[i][j]>dist[i][k]+dist[k][j]+cost[k]){
                        dist[i][j]=dist[i][k] + dist[k][j] + cost[k];
                        next[i][j]=next[i][k];
                    }
                }
            }
        }
        //path print
            printf("From %d to %d :\n", city1, city2);
            printf("Path: %d",city1);
            total_cost = dist[city1][city2];
            while (city1 != city2) {
                printf("-->%d",next[city1][city2]);
                city1 = next[city1][city2];
            }
            printf("\nTotal cost : %d\n",total_cost);
        }
    }
    return 0;
}
