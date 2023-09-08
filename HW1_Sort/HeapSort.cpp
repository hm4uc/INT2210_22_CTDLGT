#include <iostream>
#include <algorithm>

using namespace std;

const int maxx = 10000;

void heap(int a[], int n, int i)
{
    int max = i;
    int l = i*2 +1;
    int r = l+1;
    if(l < n && a[l] > a[max])
    {
        max = l;
    }

    if(r < n && a[r] > a[max])
    {
        max = r;
    }
    if(max != i)
    {
        swap(a[i], a[max]);
        heap(a, n, max);
    }
}
void sort(int a[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
    {
        heap(a,n, i);
    }
    for(int j = n-1; j > 0; j--)
    {
        swap(a[0], a[j] );
        heap(a, j, 0);
    }
}
int main ()
{
    int n; cin >> n;
    int a[maxx];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
