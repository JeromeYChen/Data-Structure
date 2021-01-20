#include <iostream>
#include <algorithm>

using namespace std;

int arr[10010] = {0,};

int main()
{
    int N, M;

    cin >> N >> M;

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    for(;M > 0; M--)
        next_permutation(arr, arr + N);

    for(int i = 0; i < N; i++)
        cout << arr[i] << " ";

    system("pause");

    return 0;
}