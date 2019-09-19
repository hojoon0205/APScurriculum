// Time complexity
//  Initialize: O(N)
//  Update: O(logN)
//  Ranged-query: O(logN)
// This code makes a Sum Segment Tree. You can also make Max, Min, Multiply, Xor, .... etc Segment Tree.
// Warning: This implement method(bottom-up) cannot do Lazy Propagation.
#include<bits/stdc++.h>
using namespace std;

int n, S;
int tree[4000010]; // Recommended size: 4*n
int arr[1000010];

void init(){
    for(S=1;S<n;S<<=1);
    for(int i=1; i<=n; ++i) tree[i+S-1] = arr[i];
    for(int i=S-1; i>=1; --i)
        tree[i] = tree[i*2] + tree[i*2+1];
}

void update(int ind, int val){
    ind += S-1;
    tree[ind] = val;
    ind /= 2;
    while(ind){
        tree[ind] = tree[ind*2] + tree[ind*2+1];
        ind /= 2;
    }
}

int get_sum(int l, int r){
    l += S-1; r += S-1;
    int ret = -1;
    while(l<r){
        if(l%2==1){ ret += tree[l]; ++l; }
        if(r%2==0){ ret += tree[r]; --r; }
        l/=2; r/=2;
    }
    if(l==r) ret += tree[l];
    return ret;
}

int main()
{
    int i;
    scanf("%d", &n);
    for(i=1; i<=n; ++i) scanf("%d", &arr[i]);
    init();
    int q;
    scanf("%d", &q); // number of queries
    for(i=1; i<=q; ++i){
        int x, y;
        scanf("%d", &x);
        if(x==1) // change value
        {
            scanf("%d%d", &x, &y);
            update(x, y); // arr[x] = y;
        }
        else if(x==2) // get max of [l, r]
        {
            scanf("%d%d", &x, &y);
            printf("%d\n", get_sum(x, y)); // max(arr[x], arr[x+1], arr[x+2], ... , arr[y])
        }
    }
    return 0;
}
