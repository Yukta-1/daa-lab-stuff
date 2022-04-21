#include <iostream>
using namespace std;

int missingElement(int arr[],int n)
{
    int l=0;
    int r=n-1;
    int cd=(arr[n-1]-arr[0])/n;
    while(l<=r){
        int m=r-(r-l)/2;
        if (((m + 1) < n )&& ((arr[m + 1] - arr[m]) != cd)) {
            return (arr[m + 1] - cd);
        }
        if (((m - 1) >= 0) && ((arr[m] - arr[m - 1]) != cd)) {
            return (arr[m - 1] + cd);
        }
        if ((arr[m] - arr[0]) != ((m - 0) * cd)) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"----------------input-------------------\n\n";
    cout<<"Enter number of elements in array : ";
    cin>>n;
    cout<<"\nEnter elements of array one by one : \n\n";
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Element "<<(i+1)<<": ";
        cin>>arr[i];
    }
    int miss=missingElement(arr,n);
    cout<<"\n----------------output------------------\n\n";
    cout<<"The missing element is: "<<miss;
    return 0;
}