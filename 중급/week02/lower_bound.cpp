// sort
#include<bits/stdc++.h>
using namespace std;

int n;
int arr[100010];
vector<int> vec;

int main()
{
    int i;
    scanf("%d", &n);
    for(i=0; i<n; ++i){
        int x;
        scanf("%d", &x);
        arr[i] = x;
        vec.push_back(x);
    }

    // before using binary_search or lower_bound or upper_bound, sort the array/vector first.
    sort(arr, arr+n); // if you use array instead of vector, write the pointer as [left, right).
    sort(vec.begin(), vec.end());

    int query;
    scanf("%d", &query);
    for(;query--;){
        int x;
        scanf("%d", &x);
        auto l = lower_bound(vec.begin(), vec.end(), x);
        auto r = upper_bound(vec.begin(), vec.end(), x);
        printf("Number of %d : %d\n", x, r - l);
        printf("%d starts at : %d\n", x, l - vec.begin());
    }
}
