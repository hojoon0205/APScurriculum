// Time complexity : O(nr) ~= O(n^2)
#include<bits/stdc++.h>
using namespace std;
#define MOD (1000000007)

int comb[3010][3010];

int main()
{
    int n, r;
    scanf("%d%d", &n, &r);
    comb[0][0] = comb[1][0] = comb[1][1] = 1;
    for(int i=2; i<=n; ++i){
        comb[i][0] = 1;
        for(int j=1; j<=min(i,r); ++j)
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j])%MOD;
    }
    printf("%d\n", comb[n][r]);
}
