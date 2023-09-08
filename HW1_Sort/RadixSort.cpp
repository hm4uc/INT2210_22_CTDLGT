#include <iostream>
using namespace std;

const int maxx = 10000;

void radixSort(int a[], int n)
{
    int b[maxx], m = a[0], k = 1;

    for (int i = 0; i < n; i++)
        if (a[i] > m)
            m = a[i];

    while (m / k > 0)
    {
        int bucket[10] = {0};
        for (int i = 0; i < n; i++)
            bucket[a[i] / k % 10]++;
        for (int i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (int i = n - 1; i >= 0; i--)
            b[--bucket[a[i] / k % 10]] = a[i];
        for (int i = 0; i < n; i++)
            a[i] = b[i];
        k *= 10;
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
    radixSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
