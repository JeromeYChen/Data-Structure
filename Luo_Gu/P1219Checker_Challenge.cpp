#include <iostream>

using namespace std;

int n, tot = 0;
int C[20] = {0,};

void search(int cur);

int main()
{
    cin >> n;

    search(0);

    cout << tot;

    system("pause");

    return 0;
}

void search(int cur)
{
    if(cur == n){
        if(tot < 3){
            for(int i = 0; i < n; i++)
                cout << C[i] + 1 << ' ';
            cout << endl;            
        }
        tot++;
    }

    else
        for(int i = 0; i < n; i++)
        {
            bool flag = true;
            C[cur] = i;
            for(int j = 0; j < cur; j++)
                if(C[cur] == C[j] || cur - C[cur] == j -C[j] || cur + C[cur] == j + C[j]){
                    flag = false;
                    break;
                }
            if(flag)
                search(cur + 1);
        }
}