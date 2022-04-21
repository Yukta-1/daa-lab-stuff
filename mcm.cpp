
#include <bits/stdc++.h>
using namespace std;

int mcm(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int min = INT_MAX;
	int count;

	for (k = i; k < j; k++)
	{
		count = mcm(p, i, k)+ mcm(p, k + 1, j)+ p[i - 1] * p[k] * p[j];
		if (count < min)
			min = count;
	}
	return min;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
	cout<< mcm(arr, 1, n - 1);
}

