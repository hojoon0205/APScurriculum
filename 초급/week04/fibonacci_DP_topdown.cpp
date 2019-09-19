#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll f[100];

int main()
{
    ll n;
    scanf("%lld", &n);

    f[1] = f[2] = 1;
    for(ll i=3; i<=n; ++i)
        f[i] = f[i-1] + f[i-2];

    printf("%lld\n", f[n]);
}
