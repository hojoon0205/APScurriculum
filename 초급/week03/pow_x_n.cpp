#include<bits/stdc++.h>
using namespace std;
#define MOD (1000000007)
#define ll long long

ll pow_x_n(ll x, ll n){
    ll ans=1;
    while(n){
        if(n%2) ans = (ans*x)%MOD;
        x = (x*x)%MOD;
        n/=2;
    }
    return ans;
}

int main()
{
    ll x, n;
    scanf("%lld%lld", &x, &n);
    printf("%lld\n", pow_x_n(x, n));
    return 0;
}
