// Time Complexity: O(NlogN) ( because of sorting, other works are O(N) )
// This is source code for boj.kr/1708
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second
#define mp make_pair

// p1->p2->p3
// clockwise:  ccw()<0
// line:       ccw()==0
// counter cw: ccw()>0
// Important function for most of geometric problems
ll ccw(pll p1, pll p2, pll p3){
    return (p2.x-p1.x)*(p3.y-p1.y) - (p3.x-p1.x)*(p2.y-p1.y);
}

ll square_dist(pll p1, pll p2){
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

int n;
vector<pll> arr;

vector<pll> CH; // the points of convex hull
int CHsz; // the number of points of the convex hull

int main()
{
    int mi=0;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        ll xx, yy;
        scanf("%lld%lld", &xx, &yy);
        arr.push_back( mp(xx,yy) );
        // choose the most bottom-left point
        if(arr[mi].y > arr[i].y) mi = i;
        else if(arr[mi].y == arr[i].y && arr[mi].x > arr[i].x) mi = i;
    }
    // the bottom-left point will be the first position
    pll tmp = arr[0]; arr[0] = arr[mi]; arr[mi] = tmp;
    
    // sort by angle
    sort(arr.begin()+1, arr.end(), [](pll a, pll b){
        ll c = ccw(a, arr[0], b);
        // if (a, arr[1], b) are on a straight line, sort by distance with arr[1]
        if(c == 0) return square_dist(arr[0],a) < square_dist(arr[0],b);
        // else, a->arr[1]->b must be clockwise
        return c < 0;
    });

    CHsz = 0;
    for(auto p : arr){
        while(CHsz>=2){ // convex hull has at least 3 points, but we have to check the 3-point in a line case.
            // if (stack.2nd_top -> stack.top -> current point) is ccw, push current point in stack.
            if( ccw(CH[CHsz-2], CH[CHsz-1], p) > 0 ) break;
            // else, pop the stack
            --CHsz;
            CH.pop_back();
        }
        CH.push_back(p);
        ++CHsz;
    }

    printf("%d\n", CHsz);
    // for(auto p : CH) printf("%lld %lld\n", p.x, p.y);
}
