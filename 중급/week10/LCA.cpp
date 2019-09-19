// Time complexity:
//  Initialize: O(NlogN)
//  Query: O(logN)
// This is source code for boj.kr/11438
#include<bits/stdc++.h>
using namespace std;
int n, m;
int par[100010][25]; // sparse table
int d[100010]; // depth of each nodes
vector<int> graph[100010]; // tree is a kind of graph
void DFS(int node, int parent, int depth)
{
    d[node] = depth;
    par[node][0] = parent;
    for(int i=0; par[node][i]; ++i)
        par[node][i+1] = par[ par[node][i] ][i];
    for(auto x : graph[node]){
        if(x==parent) continue;
        DFS(x, node, depth+1);
    }
}
int kth_parent(int node, int k)
{
    int p=0;
    while(k){
        if(k&1) node = par[node][p];
        ++p; k>>=1;
    }
    return node;
}
int getLCA(int x, int y)
{
    if(d[x]>d[y]) x^=y^=x^=y; // swap
    y = kth_parent(y, d[y]-d[x]); // make two nodes have same depth
    if(y==x) return x; // after sync two nodes, if they are same, that is the LCA
    int p=20;
    while(true){
        while(p>=0 && par[x][p]==par[y][p]) --p; // check 2^p-th parent of x and y. if same, decrease p
        if(p<0) break; // if the parent of x and y are same, the LCA is parent of x.
        x = par[x][p]; y = par[y][p];
    }
    return par[x][0];
}
int main()
{
    scanf("%d", &n);
    for(int i=1; i<n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    DFS(1, 0, 1); // run DFS for get depths of all nodes and make sparse table.
    scanf("%d", &m);
    for(;m--;)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", getLCA(x,y));
    }
}
