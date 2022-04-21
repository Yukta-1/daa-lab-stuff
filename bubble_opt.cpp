#include<iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSortOptimised(int arr[], int n)
{
	int i, j;
    int count=0;
	for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
            else if(i==0 && arr[j] < arr[j+1])
            {
                count++;
            }
        }
        if(count==(n-1))
        {
            // cout<<"Already sorted"<<endl;
            break;
        }
    }
}

int main()
{
    int n=100000;
    int arr[n];
    //ascending
    for(int i=0;i<n;i++){
        arr[i]=i;
    }
    auto start = high_resolution_clock::now();
	bubbleSortOptimised(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"Optimised time: "<<endl;
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
	return 0;
}