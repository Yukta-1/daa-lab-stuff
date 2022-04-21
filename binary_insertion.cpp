#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int unsorted(int arr[], int len){
    for(int i=0;i<len-1;i++)
        if(arr[i]>arr[i+1])
            return arr[i];
    return -1;
}

void insertion_sort(int arr[],int n, int index)
{
    int i, key, j;
    for (i = index; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n;
    cout<<"Enter number of elements in array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array : "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int index=unsorted(arr,n);
    if(index!=-1){
        int pos=binarySearch(arr,0,n-1,index);
        if(pos!=-1){
            insertion_sort(arr,n,pos);
            cout<<"Sorted elements of array : "<<endl;
            for(int i=0; i<n; i++){
                cout<<arr[i]<<endl;
            }
        }
    }
    return 0;
}