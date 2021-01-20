#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 1e6 + 10;
int a[maxn];

int main()
{
    int n, m;

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);

    while(m--)
    {
        int key;
        scanf("%d",&key);

        int ans = lower_bound(a + 1, a + n + 1, key) - a;
        if(key != a[ans])
            cout << -1 << " ";
        else
            cout << ans << " ";
    }
    

    system("pause");

    return 0;
}