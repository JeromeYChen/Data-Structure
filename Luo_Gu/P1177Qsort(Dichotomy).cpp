#include <iostream>

using namespace std;

int n, arr[1000001] = {0,};

void Quicksort(int arr[], int l, int r);

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    Quicksort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    system("pause");

    return 0;
}

void Quicksort(int arr[], int l, int r)
{
    int mid = arr[(l + r) / 2];
    int i = l, j = r;

    do
    {
        while(arr[i] < mid) i++;
        while(arr[j] > mid) j--;

        if(i <= j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }

    }while(i <= j);

    if(l < j)   Quicksort(arr, l, j);
    if(r > i)   Quicksort(arr, i, r);

}