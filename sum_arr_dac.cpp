#include <iostream>
#include <vector>
using namespace std;
#include <chrono>
using namespace std::chrono;

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
}

int max(int a, int b, int c) 
{
    return max(max(a, b), c); 
}

int maxCrossingSum(int arr[], int l, int m, int h)
{
	int sum = 0;
	int left_sum = -1000;
	for (int i = m; i >= l; i--) {
		sum = sum + arr[i];
		if (sum > left_sum)
			left_sum = sum;
	}
	sum = 0;
	int right_sum = -1000;
	for (int i = m + 1; i <= h; i++) {
		sum = sum + arr[i];
		if (sum > right_sum)
			right_sum = sum;
	}
	return max(left_sum + right_sum, left_sum, right_sum);
}

int maxSubArraySum(int arr[], int l, int h)
{
	if (l == h)
		return arr[l];
	int m = (l + h) / 2;
	return max(maxSubArraySum(arr, l, m),
			maxSubArraySum(arr, m + 1, h),
			maxCrossingSum(arr, l, m, h));
}

int main()
{
	int num=1000000;
    int arr[num];
    //random
    for(int i=0;i<num;i++){
        arr[i]=rand();
    }
    // for(int i=0;i<num;i++){
    //     cout<<arr[i]<<" ";
    // }
	auto start = high_resolution_clock::now();
    int sum=maxSubArraySum(arr,0,num-1);
	auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
	cout<<"\nStart index : "<<"0"<<endl;
    cout<<"End index : "<<num<<endl;
    cout<<"Max contiguous sum: "<<sum<<endl;
	cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
	return 0;
}
