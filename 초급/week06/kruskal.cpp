// Kruskal algorithm
// Time Complexity: O(ElogE) = O(ElogV)
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair

// This algorithm doesn't need adjacency list
// But we need to implement edge list
int V, E;
vector<pair<int, pair<int,int>>> edges;

// ...and Union-Find too
// there are more example problems in intermediate curriculum using Union-Find
int par[100010];
int Find(int x){ return par[x] = ((par[x]==x)?x:Find(par[x])); }
void Union(int x, int y){ par[Find(x)] = Find(y); }

int main()
{
    scanf("%d%d", &V, &E);
    for(int i=1; i<=V; ++i) par[i] = i;
    for(int i=1; i<=E; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z); // x<->y, cost=z
        edges.push_back( mp(z, mp(x,y)) );
    }
    sort(edges.begin(), edges.end());
    int cnt = 0, ans = 0;
    for(auto e : edges)
    {
        int x = e.second.first;
        int y = e.second.second;
        if(Find(x)==Find(y)) continue;
        Union(x,y);
        ans += e.first;
        ++cnt;
        if(cnt == V-1) break;
    }
    printf("%d\n", ans);
}
