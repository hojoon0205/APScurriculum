// Space Complexity: O(V+E)
// This method is almost always implemented
#include<bits/stdc++.h>
using namespace std;

int V, E;
vector<int> graph[100010];

bool check[100010];
void DFS(int node)
{
    printf("%d\n", node);
    check[node] = true;
    for(auto next : graph[node]){
        if(check[next]) continue;
        DFS(next);
    }
}

int main()
{
    scanf("%d%d", &V, &E);
    for(int i=1; i<=E; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        // graph[y].push_back(x); // if the graph is bi-directional, uncomment this line
    }
    for(int i=1; i<=V; ++i){
        if(check[i]) continue;
        DFS(i);
    }
}
