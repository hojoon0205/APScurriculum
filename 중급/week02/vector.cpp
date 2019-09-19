#include<bits/stdc++.h> //Can use on most of Unix-based OS, not standard c++
using namespace std;

int main()
{
    vector<int> iv(5, 2); // iv = [2, 2, 2, 2, 2]
    
    // insert values: push_back() function
    for(int i=0; i<5; ++i) iv.push_back(i); // iv = [2, 2, 2, 2, 2, 0, 1, 2, 3, 4]

    // Linear search the vector
    // Sol. 1
    for(int i=0; i<iv.size(); ++i)
    {
        // do something with iv[i]
        printf("%d ", iv[i]);
    }
    printf("\n");
    // also you can change value with iv[i]
    for(int i=0; i<iv.size(); ++i) iv[i] = 1; // iv = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    // Sol. 2 (c++11 or higher)
    for(auto x : iv) // copy value in iv to x
    {
        // do something with x
        // if you modify x, the value of iv didn't changes
        printf("%d ", x);
        x = 3;
    }
    printf("\n");
    // Sol. 3 (c++11 or higher)
    for(auto &x : iv) // &: call by reference
    {
        // if you modify x, the valud of iv changes
        printf("%d ", x);
        x = 3; // iv = [3, 3, 3, 3, 3, 3, 3, 3, 3, 3]
    }
    printf("\n");
    // check the changed values
    for(auto x : iv) printf("%d ", x);
    printf("\n");

    // erase all values
    iv.clear();
    printf("%d\n", iv.size());

    return 0;
}
