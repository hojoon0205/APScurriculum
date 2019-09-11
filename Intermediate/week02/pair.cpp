#include<bits/stdc++.h>
using namespace std;

// if we don't use any macros, code will be dirty, so I usually use them
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second

void print_pair(pii x){ printf("first: %d, second: %d\n", x.f, x.s); }

int main()
{
    pii p;
    p.f = 1, p.s = 2;
    cout << "first: " << p.f << ", second: " << p.s << endl;

    vector<pii> arr;

    srand(time(NULL));
    for(int i=0; i<10; ++i)
    {
        int x = rand()%20;
        int y = rand()%20;
        arr.push_back( mp(x,y) ); // Becareful about type
    }
    printf("\n");
    for(auto x : arr) print_pair(x);
    printf("\n");

    // compare of pair: ascending order for first value, ascending order for second value if first value is same
    // this is useful when implementing Dijkstra's algorithm with priority_queue
    sort(arr.begin(), arr.end());
    printf("\n");
    for(auto x : arr) print_pair(x);
    printf("\n");

    return 0;
}
