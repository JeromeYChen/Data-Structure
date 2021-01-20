#include <iostream>

using namespace std;
 
const int MAXN = 10e6 + 10;

int n, ans = 1;

struct node{
    int left, right;
};

node tree[MAXN];

void dfs(int id, int deep){
    if(id == 0)
        return;
    
    ans = max(deep, ans);

    dfs(tree[id].left, deep + 1);
    dfs(tree[id].right, deep + 1);
}

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> tree[i].left >> tree[i].right;
    
    dfs(1, 1);

    cout << ans;

    system("pause");

    return 0;
}