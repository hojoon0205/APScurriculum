// Prim algorithm
// Time complexity: O(ElogV)
// sample source code for boj.kr/1922
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair

int V, E;
vector<pii> graph[100010]; // first: cost, second: node

priority_queue<pii, vector<pii>, greater<pii>> heap;
bool chk[100010];
int MST()
{
    int ans = 0;
    heap.push( mp(0,1) );
    while(!heap.empty()){
        pii tmp = heap.top();
        heap.pop();
        int cost = tmp.first, node = tmp.second;
        if(chk[node]) continue;
        ans += cost;
        chk[node] = true;
        for(auto x : graph[node]){
            if(chk[x.second]) continue;
            heap.push( x );
        }
    }
    return ans;
}

int main()
{
    scanf("%d", &V);
    scanf("%d", &E);
    for(int i=1; i<=E; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z); // x<->y, cost=z
        graph[x].push_back( mp(z,y) );
        graph[y].push_back( mp(z,x) );
    }

    printf("%d\n", MST());

    return 0;
}
