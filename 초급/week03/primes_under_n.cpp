#include<bits/stdc++.h>
using namespace std;

// p:  array of prime numbers
// pn: number of prime numbers
int p[1010], pn;

int main()
{
    int n;
    scanf("%d", &n);
    pn = 1; p[1] = 2;
    for(int i=3; i<=n; i+=2){ // even number (larger than 2) cannot be prime
        int j;
        for(j=3; j*j<=i; j+=2){
            if(i%j==0) break;
        }
        if(j*j<=i) continue;
        p[++pn] = i;
    }

    printf("%d\n", pn);
    for(int i=1; i<=pn; ++i) printf("%d ", p[i]);
    printf("\n");

    return 0;
}
