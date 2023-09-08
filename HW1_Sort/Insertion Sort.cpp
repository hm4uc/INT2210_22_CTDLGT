#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[1000];
	for (int i = 0; i < n; i++) 
	{
		cin >> a[i];
	}
	//Insertion Sort
	for (i = 1; i < n; i++)
	{
		int x = a[i];
		int pos = i;
		while (pos > 0 && x < a[pos - 1])
		{
			a[pos] = a[pos - 1];//Lui so
			pos--;
		}
		a[pos] = x;//Chen so
	}
	for (i = 0; i < n; i++) 
	{
		cout << a[i] << " ";
	}
	return 0;
}
