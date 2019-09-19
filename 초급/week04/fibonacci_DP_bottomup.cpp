#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll f[100];

int main()
{
    ll n;
    scanf("%lld", &n);

    f[1] = 1;
    for(ll i=1; i<n; ++i){
        f[i+1] += f[i];
        f[i+2] += f[i];
    }

    printf("%lld\n", f[n]);
}
