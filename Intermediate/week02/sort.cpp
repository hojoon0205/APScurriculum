#include<bits/stdc++.h>
using namespace std;

void print_arr(vector<string> &v){
    for(auto x : v) cout << x << " ";
    cout << "\n\n";
    return;
}

bool reverse_dictionary(string a, string b){ return a > b; }

int main()
{
    vector<string> arr{"c", "a", "bb", "b", "aa"};
    print_arr(arr);

    // sort function
    sort(arr.begin(), arr.end()); // int: ascending order, string: dictionary order
    print_arr(arr);

    // custom sort Sol. 1 (using compare function(must be boolean))
    // you can't use local variable in the compare function
    sort(arr.begin(), arr.end(), reverse_dictionary);
    print_arr(arr);

    // custom sort Sol. 2 (using lambda)
    // you can use local variable in this 
    sort(arr.begin(), arr.end(), 
            [](string a, string b)->bool{
                if(a.length() == b.length()) return a < b;
                return a.length() < b.length();
            }); // sort with length, dictionary order on same length strings
    print_arr(arr);

    return 0;
}
