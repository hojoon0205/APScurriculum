// Time Complexity
//  Initialize: O(N)
//  Update: O(logN)
//  Range-Update: O(logN) (Lazy Propagation)
//  Range-query: O(logN)
// Top-Down Segment tree can use Lazy Propagation technique.
#include<bits/stdc++.h>
using namespace std;

int tree[4000010], S;
int lazy[4000010];
int a[1000010];

void init(int n, int* arr){
    for(S=1;S<n;S<<=1);
    for(int i=1; i<=n; ++i) tree[i+S-1] = arr[i];
    for(int i=S-1; i>=1; --i) tree[i] = tree[i*2] + tree[i*2+1];
}

// This is for Lazy Propagation technique.
// You have to change this function for different problem or tree or queries.
// For more detail, google it please.
// tree[node] = arr[nl] + arr[nl+1] + ... + arr[nr-1] + arr[nr]
void propagate(int nl, int nr, int node)
{
    if(lazy[node]==0) return; //nothing to work (we will not input 0 for queries)
    if(node>=S) return;
    if(nl<nr){
        lazy[node*2]   += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    tree[node] += lazy[node] * (nr-nl+1);
    lazy[node] = 0;
}

// In this example, the range query is "add val every elements in [l, r]".
// You have to change this function for different problem or tree or queries.
// tree[node] = arr[nl] + arr[nl+1] + ... + arr[nr-1] + arr[nr]
void update(int l, int r, int val, int nl=1, int nr=S, int node=1)
{
    propagate(nl, nr, node); // propagate first
    if(nl>r || nr<l) return; // [l,r] and [nl,nr] didn't overlap.
    if(l<=nl && nr<=r) // [l,r] includes [nl,nr]
    {
        lazy[node] += val;
        propagate(nl, nr, node);
        return;
    }
    int m = (nl+nr)/2;
    update(l, r, val, nl,  m,  node*2);   // update for left-subtree
    update(l, r, val, m+1, nr, node*2+1); // update for right-subtree
    // after updating left-subtree and right-subtree
    tree[node] = tree[node*2] + tree[node*2+1];
}

// Single value update: add val every elements in [ind, ind]
void update(int ind, int val){ update(ind, ind, val); }

// Simillar as range-update function
// tree[node] = arr[nl] + arr[nl+1] + ... + arr[nr-1] + arr[nr]
int get_sum(int l, int r, int nl=1, int nr=S, int node=1)
{
    propagate(nl, nr, node);   // propagate first
    if(nl>r || nr<l) return 0; // [l,r] and [nl,nr] didn't overlap.
    if(l<=nl && nr<=r) return tree[node]; // [l,r] includes [nl,nr]
    int m = (nl+nr)/2;
    int x = get_sum(l, r, nl,  m,  node*2);   // get_sum for left-subtree
    int y = get_sum(l, r, m+1, nr, node*2+1); // get_sum for right-subtree
    return x+y;
}

int main()
{
    update(1, 2, 3);
    update(1, 2, 3, 4, 5);

    int n, i, q;
    scanf("%d", &n);
    for(i=1; i<=n; ++i) scanf("%d", &a[i]);
    init(n, a);
    
    scanf("%d", &q);
    for(;q--;)
    {
        int x, y, z;
        scanf("%d", &x);
        if(x==1) // update value
        {
            scanf("%d%d", &x, &y); // arr[x] += y;
            update(x, y);
        }
        else if(x==2) // update range ( arr[x]+=z, arr[x+1]+=z, ... , arr[y]+=z )
        {
            scanf("%d%d%d", &x, &y, &z);
            update(x, y, z);
        }
        else if(x==3) // range sum query ( arr[x]+arr[x+1]+...+arr[y] )
        {
            scanf("%d%d", &x, &y);
            printf("%d\n", get_sum(x, y));
        }
    }

    return 0;
}
