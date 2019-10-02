// Time Complexity: O(ElogV)
// If you implement a heap(not using priority_queue), time complexity becomes O(VlogV)
// This is source code of boj.kr/1753
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define MAX 99999999

// min-heap for dijkstra algorithm, first element is cost, second element is node number
priority_queue<pii, vector<pii>, greater<pii>> heap;

// graph info. first is cost, second is node number
vector<pii> graph[20010];

int n, m;
int ans[20010]; // the minimum cost from st to each node.

void Dijkstra(int st)
{
    // initialize cost array
    for(int i=1; i<=n; ++i) ans[i] = MAX;
    ans[st] = 0;
    heap.push( mp(0,st) );
    while(!heap.empty())
    {
        pii tmp = heap.top(); // get minimum cost in heap
        heap.pop();
        int cost = tmp.first, node = tmp.second;
        if(ans[node] < cost) continue;
        for(auto &pi : graph[node]) // pi: pair<int,int>
        {
            int c = pi.first, next = pi.second;
            if(ans[next] <= cost + c) continue;
            ans[next] = cost + c;
            heap.push( mp(cost+c,next) );
        }
    }
}

int main()
{
    int st;
    scanf("%d%d", &n, &m);
    scanf("%d", &st);
    for(int i=1; i<=m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z); // x->y, cost=z
        graph[x].push_back( mp(z,y) );
    }
    Dijkstra(st);
    for(int i=1; i<=n; ++i){
        if(ans[i]==MAX) printf("INF\n");
        else printf("%d\n", ans[i]);
    }
    return 0;
}
