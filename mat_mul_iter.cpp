#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;

void matrix_mul(int A[][32], int B[][32], int C[][32])
{
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < 32; k++)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

int main(){
    int A[32][32];
    int B[32][32];
    int C[32][32];
    for (int i=0;i< 32;i++){
        for(int j=0;j<32;j++){
            A[i][j] = rand()%32;
        }
    }

    for(int i=0;i<32;i++){
        for(int j=0;j<32;j++){
            B[i][j]= rand()%32;
        }
    }

  

    auto start = high_resolution_clock::now();
    matrix_mul(A,B,C);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    
    for(int i=0;i<32;i++){
        for(int j=0;j<32;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout << "Time taken by function is : "<< duration.count() << " ns" << endl;

}