// Time complexity : O( n * log(MOD) )
// Only available when MOD is prime number
#include<bits/stdc++.h>
using namespace std;
#define MOD (1000000007)
#define ll long long

ll invMOD(ll x){
    // By Fermat's little theorem, a^(p-1) == 1 (mod p) when p is prime number and gcd(a,p)==1
    // We can change the fomula: a * a^(p-2) == 1 (mod p)
    // So, the inverse of a is a^(p-2)
    // In this case, the inverse of a is a^(1000000005)
    ll ret = 1, p = MOD-2;
    while(p){
        if(p&1) ret = (ret*x)%MOD;
        p>>=1;
        x = (x*x)%MOD;
    }
    return ret;
}

int main()
{
    ll n, r;
    scanf("%lld%lld", &n, &r);
    // nCr = n! / r! / (n-r)!
    ll ans = 1;
    for(int i=1; i<=n;   ++i) ans = (ans*i)%MOD;
    for(int i=1; i<=r;   ++i) ans = (ans*invMOD(i))%MOD;
    for(int i=1; i<=n-r; ++i) ans = (ans*invMOD(i))%MOD;
    printf("%lld\n", ans); 
}
