#include <iostream>

using namespace std;

const int maxx = 10000;
int partition(int a[], int l, int r)
{
    int pivot = a[(l + r) / 2];
    while (l <= r)
    {
        while (a[l] < pivot) l++;
        while (a[r] > pivot) r--;
        if (l <= r)
        {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }
    return l;
}

void quickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int i = partition(a, l, r);
        quickSort(a, l, i - 1);
        quickSort(a, i, r);
    }
}

int main()
{
    int n; cin >> n;
    int a[maxx];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
