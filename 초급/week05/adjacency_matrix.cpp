// Space Complexity: O(V^2)
// This method is rarely implemented (ex: Floyd-Warshall)
#include<bits/stdc++.h>
using namespace std;

int V, E; // number of vertex, number of edge
int graph[5010][5010];

bool check[5010];

void DFS(int node)
{
    printf("%d\n", node);
    check[node] = true;
    for(int i=1; i<=V; ++i)
    {
        if(!graph[node][i]) continue;
        if(check[i]) continue;
        DFS(i);
    }
}

int main()
{
    scanf("%d%d", &V, &E);
    for(int i=1; i<=E; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        graph[x][y] = 1;
        // graph[y][x] = 1; // if the graph is bi-directional graph, uncomment this line
    }

    for(int i=1; i<=V; ++i){
        if(check[i]) continue;
        DFS(i);
    }
}
