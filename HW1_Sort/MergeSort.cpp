#include <iostream>
using namespace std;

const int maxx = 10000;

void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int al[n1], ar[n2];

    for (i = 0; i < n1; i++)
    {
        al[i] = a[l + i];
    }
    for (j = 0; j < n2; j++)
        ar[j] = a[m + 1+ j];

    i = 0; j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (al[i] <= ar[j])
        {
            a[k] = al[i];
            i++;
        }
        else
        {
            a[k] = ar[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = al[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = ar[j];
        j++;
        k++;
    }
}

void sort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        sort(a, l, m);
        sort(a, m+1, r);

        merge(a, l, m, r);
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
    sort(a, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
