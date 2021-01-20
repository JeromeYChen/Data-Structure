#include<iostream>
#include<cstdio>

using namespace std;

struct gold
{
    int w, v;   //w为重量，v为价值
};

bool cmp(gold a, gold b)
{
    return a.v * b.w > b.v * a.w;
}

int main()
{
    int n, T;
    double res = 0;

    cin >> n >> T;

    struct gold arr[110];

    int i = 0;
    
    while(cin >> arr[i].w >> arr[i++].v);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n - i - 1; j++)
            if(cmp(arr[j], arr[j + 1]))
            {
                int t;

                t = arr[j].w;
                arr[j].w = arr[j + 1].w;
                arr[j + 1].w = t;

                t = arr[j].v;
                arr[j].v = arr[j + 1].v;
                arr[j + 1].v = t;
            }
    
    for(int i = n - 1; i >= 0; i--)
    {
        if(T - arr[i].w < 0)
        {
            res += arr[i].v * 1.00 / arr[i].w * T;
            break;
        }
        T -= arr[i].w;
        res += arr[i].v;
    }

    printf("%.2f", res);

    system("pause");
    return 0;
}