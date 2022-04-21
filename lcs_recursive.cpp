#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int lcs(int i, int j,char *a,char *b){
    if(a[i]=='\0' || b[j]=='\0'){
        return 0;
    }
    else if(a[i]==b[j]){
        return 1+lcs(i+1,j+1,a,b);
    }
    else{
        return max(lcs(i+1,j,a,b),lcs(i,j+1,a,b));
    }
}
int main()
{
    char x[20],y[20];
    cin>>x;
    cin>>y;
    cout<<lcs(0,0,x,y);
    return 0;
}