#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll f[100];

ll fibo(ll n)
{
    if(1<=n && n<=2) return 1;
    if(f[n]) return f[n];
    return f[n] = fibo(n-1)+fibo(n-2);
}

int main()
{
    ll n;
    scanf("%lld", &n);
    printf("%lld\n", fibo(n));
    return 0;
}

// compare with fibonacci_bruteforce.cpp!
