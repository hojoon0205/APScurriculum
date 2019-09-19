// Time Complexity
//  Find:  O(Ack^-1(N)) ~= O(1)
//  Union: O(Ack^-1(N)) ~= O(1)    If you want to know Ack(n), search "Ackermann function".
// BOJ 1717
#include<bits/stdc++.h>
using namespace std;

int par[1000010];

int init(int n){ for(int i=1;i<=n;++i) par[i]=i; }
int Find(int x){ return par[x] = ( par[x]==x?x:Find(par[x]) ); }
void Union(int x, int y){ par[Find(x)] = Find(y); }

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    init(n);
    for(int i=1; i<=m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if(x==0) Union(y,z);
        else printf("%s\n", Find(y)==Find(z)?"YES":"NO");
    }
}
