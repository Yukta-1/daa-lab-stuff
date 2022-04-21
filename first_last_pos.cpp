
#include <iostream>
using namespace std;

void first_last(int arr[],int size,int num){
    int first=0,last=0;
    for(int i=0;i<size;i++){
        if(arr[i]==num){
            first=i;
            break;
        }
    }
    for(int i=size-1;i>=0;i--){
        if(arr[i]==num){
            last=i;
            break;
        }
    }
    cout<<"First: "<<first<<endl;
    cout<<"Last: "<<last<<endl;


}
int main()
{
    int n = 0,num;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: \n";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter element to be checked: ";
    cin>>num;
    first_last(arr,n,num);
    return 0;
}