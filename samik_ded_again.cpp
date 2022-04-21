#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <chrono>
using namespace std;
using namespace std::chrono;
//maximum subarray sum
int max(int a, int b) { 
    if(a>b)
    return a;
    else{
        return b;
    }
}
int maxSubArraySum(int *arr, int size)
{
    
    int sum_max= INT_MIN;
    for(int i=1;i<=size;i++){
        for(int j=0;j<size;j++){
            if(i+j>size)
                break;
            int sum=0;
            for(int i=j;i<j+size;i++)
                sum+=arr[i];
            sum_max= max(sum,sum_max);
        }
    }
    return sum_max;
}

int main()
{
    
    vector<long long int> values1(10000);
    int arr1[values1.size()];
    
    // Generate Random values
    auto f = []() -> int { return rand() % 10000; };
    // Fill up the vector
    generate(values1.begin(), values1.end(), f);  //random 10000 input
    for(int i = 0; i < values1.size(); i++) 
    {
        arr1[i] = values1[i];
    }
    // Get starting timepoint
    auto start1 = high_resolution_clock::now();
    cout << "Maximum contiguous sum is " << maxSubArraySum(arr1, 10000)<<endl;
    auto stop1 = high_resolution_clock::now();
  
    // Get duration. Substart timepoints to 
    // get durarion. To cast it to proper unit
    // use duration cast method
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    
    cout << "Time taken by function for random(10000): "<< duration1.count() << " microseconds" << endl;
    return 0;
}