// Time complexity: O(sqrt(n))
#include<bits/stdc++.h>
using namespace std;

// Euler's phi function
// For given N(>=1), find the number of X such that gcd(N,X)=1 and 1<=X<=N

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 1;
    if(n%2==0){
        n/=2;
        while(n%2==0){ ans *= 2; n/=2; }
    }
    for(int i=3; i*i<=n; i+=2){ // Why we don't need to calculate for i*i>n ?
        if(n%i) continue;
        n/=i; ans *= (i-1); // At this moment, i is always prime number. Think about why.
        while(n%i==0){ ans *= i; n/=i; }
    }
    if(n!=1) ans *= n-1; // Why we should check n!=1 ?
    printf("%d\n", ans);
    return 0;
}
