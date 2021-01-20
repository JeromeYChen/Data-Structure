#include <iostream>

using namespace std;

int arr[1000001] = {0,};

void Quicksort(int arr[], int l, int r);
int Partition(int arr[], int low, int high);
void swap(int* a, int* b);

int main()
{
    int N;

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    Quicksort(arr, 0, N - 1);

    int i = 0;
    for(i = 0; i < N - 1; i++)
        cout << arr[i] << ' ';
    cout << arr[i] << endl;

    system("pause");
    return 0;
}

void Quicksort(int arr[], int l, int r)
{
    if(l < r)
    {
        int q;

        q = Partition(arr, l, r);
        Quicksort(arr, l, q - 1);
        Quicksort(arr, q + 1, r);
    }

}

int Partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return (i + 1);

}

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}