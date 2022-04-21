#include<iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


int main(){
    int num=10000;
    int key,j;
    int arr[num];
    //random
    for(int i=0;i<num;i++){
        arr[i]=rand();
    }

    auto start = high_resolution_clock::now();
    int comp=0;
    for(int i=1;i<num;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
            comp++;
        }
        arr[j+1]=key;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout<<"For random numbers : ";
    cout<<"Number of comparisons : "<<comp<<endl;
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
}