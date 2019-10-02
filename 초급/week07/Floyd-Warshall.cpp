// Floyd-Warshall algorithm
// Shortest path for all source-dest pairs
// Time Complexity: O(V^3) (adjacency-matrix)
#include<bits/stdc++.h>
using namespace std;
#define INF 1000000007

int V, E;
int dist[5010][5010];

int main()
{
    scanf("%d%d", &V, &E);
    for(int i=1; i<=V; ++i)
        for(int j=1; j<=V; ++j)
            dist[i][j] = INF;

    for(int i=1; i<=E; ++i){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z); // x->y, cost=z
        dist[x][y] = z;
    }

    for(int k=1; k<=V; ++k)
    {
        for(int i=1; i<=V; ++i)
        {
            for(int j=1; j<=V; ++j) // be careful for order of i, j, k loop
            {
                if(dist[i][j] > dist[i][k] + dist[k][j]) // i->j vs i->k->j
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for(int i=1; i<=V; ++i){
        for(int j=1; j<=V; ++j){
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}
