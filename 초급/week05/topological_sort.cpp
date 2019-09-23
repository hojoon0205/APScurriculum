// Time Complexity : O(V+E)
#include<bits/stdc++.h>
using namespace std;

int V, E;
vector<int> graph[100010];

int t_sorted[100010], t;

bool chk[100010];
void DFS(int node)
{
    chk[node] = true;
    for(auto x : graph[node]){
        if(chk[x]) continue;
        DFS(x);
    }
    t_sorted[t--] = node;
}

int main()
{
    scanf("%d%d", &V, &E);
    for(int i=1; i<=E; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
    }
    t = V;
    for(int i=1; i<=V; ++i){
        if(chk[i]) continue;
        DFS(i);
    }
    for(int i=1; i<=V; ++i)
        printf("%d ", t_sorted[i]);
    return 0;
}
