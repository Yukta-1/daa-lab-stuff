#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
using namespace std;
using namespace std::chrono;
int insertion(int arr[], int n) 
{ 
    int i,key,comp=0;
    for(int j=1;j<n;j++){
        key=arr[j];
        i=j-1;
        while(i>=0 && arr[i]>key){
            arr[i+1]=arr[i];
            i=i-1;
            comp++;
        }
        arr[i+1]=key;
    }
    return comp;
} 
int main() 
{ 
    /*int arr[] = { 8,2,4,9,3,6 }; 
    int n = sizeof(arr) / sizeof(arr[0]); */
    vector<int> values(10000);
    int arr[values.size()];
    
    // Generate Random values
    auto f = []() -> int { return rand() % 10000; };
    // Fill up the vector
    generate(values.begin(), values.end(), f);  //random 10k input
    for(int i = 0; i < values.size(); i++) 
    {
        arr[i] = values[i];
    }
    // Get starting timepoint
    auto start = high_resolution_clock::now();
    int comp_rand=insertion(arr, 10000); 
    // Get ending timepoint
    auto stop = high_resolution_clock::now();
  
    // Get duration. Substart timepoints to 
    // get durarion. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << "Time taken by function to sort random: "<< duration.count() << " microseconds" << endl;
    cout<<"Number of comparisons : "<<comp_rand<<endl;
     
    int ascending_arr[10000];
    int descending_arr[10000];
    for(int i=0;i<=10000;i++){ //generated ascending input
        ascending_arr[i]=i;
    }
    for(int i=0;i<=10000;i++){ //generated descending input
        descending_arr[i]=10000-i;
    }
    auto start2 = high_resolution_clock::now();
    int comp_asc=insertion(ascending_arr, 10000); 
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Time taken by function to sort ascending: "<< duration2.count() << " microseconds" << endl;
    cout<<"Number of comparisons : "<<comp_asc<<endl;
    auto start3 = high_resolution_clock::now();
    int comp_desc=insertion(descending_arr, 10000); 
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout << "Time taken by function to sort descending: "<< duration3.count() << " microseconds" << endl;
    cout<<"Number of comparisons : "<<comp_desc<<endl;
    return 0; 
} 