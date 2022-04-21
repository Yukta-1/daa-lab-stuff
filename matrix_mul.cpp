#include <iostream>
using namespace std;
int main()
{
    int r1,c1,r2,c2,r3,c3;
    cout<<"Enter rows and columns of matrix 1:";
    cin>>r1>>c1;
    cout<<"Enter elements of matrix 1:\n";
    int arr1[10][10];
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            cin>>arr1[i][j];
        }
    }
    cout<<"Enter rows and columns of matrix 2:";
    cin>>r2>>c2;
    cout<<"Enter elements of matrix 1:\n";
    int arr2[10][10];
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            cin>>arr2[i][j];
        }
    }
    if(c1==r2)
    {
        int arr3[10][10];
        for(int i = 0; i < r1; ++i)
            for(int j = 0; j < c2; ++j)
            {
                arr3[i][j]=0;
                for(int k = 0; k < c1; ++k)
                {
                    arr3[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        cout<<"Result:\n";
        for(int i = 0; i < r1; ++i)
            for(int j = 0; j < c2; ++j)
            {
                cout << " " << arr3[i][j];
                if(j == c2-1)
                    cout << endl;
            }
    }
}