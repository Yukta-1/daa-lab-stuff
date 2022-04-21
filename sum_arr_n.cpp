#include <iostream>
#include <vector>
using namespace std;
#include <chrono>
using namespace std::chrono;

int maxSubArraySum(int arr[], int size)
{
    int max_ending_here = 0, max_so_far = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] <= max_ending_here + arr[i]) {
            max_ending_here += arr[i];
        }
        else {
            max_ending_here = arr[i];
        }
        if (max_ending_here > max_so_far)
            max_so_far = max_ending_here;
    }
    return max_so_far;
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
    int sum=maxSubArraySum(arr,num);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout<<"\nStart index : "<<"0"<<endl;
    cout<<"End index : "<<num<<endl;
    cout<<"Max contiguous sum: "<<sum<<endl;
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
    return 0;
}

