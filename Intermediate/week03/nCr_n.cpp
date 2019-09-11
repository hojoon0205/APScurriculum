// Time complexity: O(n)
// Only available when MOD is prime number
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD (1000000007)

int inv[1000010];

int main()
{
    ll n, r;
    scanf("%lld%lld", &n, &r);
    // We want to get inverse of x on modulo p
    // p = x * q + r (0<=r<x)    -> q = [p/x], r = p%x
    // 0 = x*q + r (mod p)
    // r = -x*q (mod p)              multiply inv(r) each side
    // 1 = -x*q*inv(r) (mod p)       multiply inv(x) each side
    // inv(x) = -q*inv(r) (mod p)
    // Use Dynamic Programming, we always know inv(r) before inv(x) because of r<x
    // So, We can get inv(x) in O(1)
    inv[1] = 1; // trivial
    for(ll i=2; i<=n; ++i){
        inv[i] = ( (MOD - inv[MOD%i])*(MOD/i) )%MOD;
    }
    ll ans = 1;
    // nCr = n! / r! / (n-r)!
    for(ll i=1; i<=n;   ++i) ans = (ans*i)%MOD;
    for(ll i=1; i<=r;   ++i) ans = (ans*inv[i])%MOD;
    for(ll i=1; i<=n-r; ++i) ans = (ans*inv[i])%MOD;
    printf("%lld\n", ans);
    return 0;
}
