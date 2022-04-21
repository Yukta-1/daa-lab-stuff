#include <iostream>
#include <vector>
using namespace std;
int maxSubArraySum(int arr[], int size)
{
    
    int sum_max= -1000;
    int start=0;
    int end=0;
    for(int i=0;i<size;i++){
        int sum=0;
        start=i;
        for(int j=i;j<size;j++){
            sum=sum+arr[j];
            if(sum>sum_max)
                sum_max= sum;
                end=j;
        }
    } 
    cout<<"\nStart index : "<<"0"<<endl;
    cout<<"End index : "<<end<<endl;
    return sum_max;
}
int main()
{
    int num=10;
    int arr[num];
    //random
    for(int i=0;i<num;i++){
        arr[i]=rand();
    }
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
    int sum=maxSubArraySum(arr,num);
    cout<<"Max contiguous sum: "<<sum;
    return 0;
}