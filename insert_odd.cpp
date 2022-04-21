#include<iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


int main(){
    int num=100;
    int key,j;
    int arr[num];
    //random
    for(int i=0;i<num;i++){
        arr[i]=rand();
    }

    int comp=0;
    auto start = high_resolution_clock::now();

    for(int i=3;i<num;i+=2){
        key=arr[i];
        j=i-2;
        while(j>=0 && arr[j]>key){
            arr[j+2]=arr[j];
            j=j-2;
            comp++;
        }
        arr[j+2]=key;
    }
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\nFor random numbers : ";
    cout<<"Number of comparisons : "<<comp<<endl;
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
}