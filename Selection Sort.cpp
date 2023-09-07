#include <iostream>
#include <algorithm>

using namespace std;

int findMin(int n, int a[], int& dau, int& cuoi)
{
	int minn = a[dau], pos = dau;
	for (int i = dau + 1; i < cuoi; i++)
	{
		if (minn > a[i])
		{
			minn = a[i];
			pos = i;
		}
	}
	return pos;
}

int main()
{
	int n;
	cin >> n;
	int a[1000];
	for (int i = 0; i < n; i++) 
	{
		cin >> a[i];
	}
	int i = 0;
	while (i < n)
	{
		int pos = findMin(n, a, i, n);
		swap(a[i], a[pos]);
		i++;
	}
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
