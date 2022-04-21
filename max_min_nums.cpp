#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void min_max(vector<int> const &nums, int low, int high, int &min, int &max)
{
 
    if (low == high)
    {
        if (max < nums[low])
            max = nums[low];
        if (min > nums[high])
            min = nums[high]; 
        return;
    }
    if (high - low == 1)
    {
        if (nums[low] < nums[high])
        {
            if (min > nums[low])
                min = nums[low]; 
            if (max < nums[high])
                max = nums[high];
        }
        else {
            if (min > nums[high])
                min = nums[high];
 
            if (max < nums[low])
                max = nums[low];
        }
        return;
    }
    int mid = (low + high) / 2;
    min_max(nums, low, mid, min, max);
    min_max(nums, mid + 1, high, min, max);
}

int main()
{
    int n = 0;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: \n";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int max = INT_MIN, min = INT_MAX;

    min_max(arr, 0, n - 1, min, max);
 
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    return 0;
}