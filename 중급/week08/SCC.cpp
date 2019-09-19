// Strongly Connected Components
// This code is solution code for boj.kr/2150, try other problem: boj.kr/4013
// Time Complexity: O(V+E)
// This algorithm was made by Kosaraju.
#include<bits/stdc++.h>
using namespace std;

vector<int> graph[10010];
vector<int> inv_g[10010];
int V, E;
bool chk[10010];

int rev[10010], r;

int sccid[10010], scc_num;
vector<int> SCC[10010];
// At the end of algorithm, the SCCs are sorted in topological order.

void DFS(int node)
{
    chk[node] = true;
    for(auto x : graph[node]){
        if(chk[x]) continue;
        DFS(x);
    }
    rev[++r] = node;
}

void inv_DFS(int node)
{
    sccid[node] = scc_num;
    chk[node] = false;
    for(auto x : inv_g[node]){
        if(!chk[x]) continue;
        inv_DFS(x);
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
        inv_g[y].push_back(x);
    }
    for(int i=1; i<=V; ++i)
    {
        if(chk[i]) continue;
        DFS(i);
    }
    for(int i=V; i>=1; --i)
    {
        int c = rev[i];
        if(!chk[c]) continue;
        ++scc_num;
        inv_DFS(c);
    }

    for(int i=1; i<=V; ++i)
        SCC[sccid[i]].push_back(i);
    for(int i=1; i<=scc_num; ++i)
        sort(SCC[i].begin(), SCC[i].end());
    sort(&SCC[1], &SCC[scc_num+1], [](vector<int> &a, vector<int> &b){ return a[0]<b[0]; });

    printf("%d\n", scc_num);
    for(int i=1; i<=scc_num; ++i){
        for(auto x : SCC[i])
            printf("%d ", x);
        printf("-1\n");
    }
}
