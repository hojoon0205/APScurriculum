// Time Complexity:
//  Insert New Word: O(|string|)
//  Search Word: O(|string|)
// This implementation doesn't use pointer
#include<bits/stdc++.h>
using namespace std;

struct Trie{
    int next[26]; // if next[i]==0, i-th alphabet doesn't have any child
    bool check; // check is true if this is the end of one word
    // add something you want... (It could be count, or other values, ...)
};

Trie trie[1000010]; // The size of array is usually sum of the length of strings in dictionary
int s; // number of allocated trie structures
// 1st index means the root of trie.

void init()
{
    s=1;
    for(int i=0; i<26; ++i) trie[1].next[i] = 0;
    trie[1].check = false;
}

void insert(char str[], int len)
{
    int node = 1;
    for(int i=0; i<len; ++i)
    {
        int c = str[i]-'a';
        int tmp = trie[node].next[c];
        if(tmp==0) // we have to allocate new node
        {
            ++s;
            for(int j=0; j<26; ++j) trie[s].next[i] = 0;
            trie[s].check = false;
            trie[node].next[c] = s;
            tmp = s;
        }
        node = tmp;
    }
    trie[node].check = true;
}

bool search(char str[], int len)
{
    int node = 1;
    for(int i=0; i<len && node; ++i)
    {
        int c = str[i]-'a';
        node = trie[node].next[c];
    }
    return node && trie[node].check;
}

int main()
{
    init();
    int n, m;
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        char str[10010];
        scanf("%s", str);
        insert(str, strlen(str));
    }
    scanf("%d", &m);
    for(int i=1; i<=m; ++i)
    {
        char str[10010];
        scanf("%s", str);
        printf("%s\n", search(str, strlen(str))?"Found":"Not Found");
    }
}
