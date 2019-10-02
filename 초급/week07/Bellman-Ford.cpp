// Bellman-Ford algorithm
// Multiple Source - All destination
// Time Complexity: O(VE)
// It allows negative edge weight, and able to detect the negative-weight cycle.
#include<bits/stdc++.h>
using namespace std;
#define INF 1000000007

int V, E;
struct Edge{
    int st;
    int ed;
    int w;
}edges[10010];

int dist[10010];

int main()
{
    scanf("%d%d", &V, &E);
    for(int i=1; i<=E; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        edges[i].st = x;
        edges[i].ed = y;
        edges[i].w = z; // If it is bi-directional edge, add an edge for inverse
    }

    int source;
    scanf("%d", &source); // It could be two or more sources.

    for(int i=1; i<=V; ++i) dist[i] = INF;
    dist[source] = 0;

    for(int i=1; i<=V; ++i)
    {
        for(int j=1; j<=E; ++j)
        {
            int st = edges[j].st, ed = edges[j].ed, w = edges[j].w;
            if(dist[ed] > dist[st] + w)
                dist[ed] = dist[st] + w;
        }
    }
    for(int i=1; i<=E; ++i){
        int st = edges[i].st, ed = edges[i].ed, w = edges[i].w;
        if(dist[ed] > dist[st] + w){
            printf("Negative-weight cycle detected\n");
            return 0;
        }
    }
    for(int i=1; i<=V; ++i)
        printf("%d %d\n", i, dist[i]);
}
