// Shortest Path Faster Algorithm
// Time Complexity:
//  Worst Case: O(VE)
//  Average Case: O(E) (If you think the setter didn't prepared for counter-SPFA testcase, try this algorithm)
// This is source code of boj.kr/1753 but the result will be Time Limit Exceeded.
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define MAX 99999999

// Dijkstra uses priority-queue, but SPFA use simple queue
// Other parts are same as Dijkstra's algorithm
queue<pii> q;

// graph info. first is cost, second is node number
vector<pii> graph[20010];

int n, m;
int ans[20010]; // the minimum cost from st to each node.

void SPFA(int st)
{
    // initialize cost array
    for(int i=1; i<=n; ++i) ans[i] = MAX;
    ans[st] = 0;
    q.push( mp(0,st) );
    while(!q.empty())
    {
        pii tmp = q.front(); // get minimum cost in queue
        q.pop();
        int cost = tmp.first, node = tmp.second;
        if(ans[node] < cost) continue;
        for(auto &pi : graph[node]) // pi: pair<int,int>
        {
            int c = pi.first, next = pi.second;
            if(ans[next] <= cost + c) continue;
            ans[next] = cost + c;
            q.push( mp(cost+c,next) );
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
    SPFA(st);
    for(int i=1; i<=n; ++i){
        if(ans[i]==MAX) printf("INF\n");
        else printf("%d\n", ans[i]);
    }
    return 0;
}
