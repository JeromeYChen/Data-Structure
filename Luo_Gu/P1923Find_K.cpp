#include <iostream>

using namespace std;

int n, arr[5000001] = {0,};
int k;

void Quicksort(int arr[], int l, int r);

int main()
{

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        scanf("%d ", &arr[i]);

    Quicksort(arr, 0, n - 1);

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

    if(j >= k)   Quicksort(arr, l, j);
    else if(i <= k)   Quicksort(arr, i, r);
    else{
        cout << arr[j + 1];
        return;      
    }

}