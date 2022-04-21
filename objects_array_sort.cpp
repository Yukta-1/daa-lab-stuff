#include <iostream>
#include<string>
using namespace std;
class Student{
    public:
        string name,reg_no;
        int marks;
};

void selection_sort(Student arr[],int n){
    int index;
    for(int i=0;i<n-1;i++){
        index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j].marks<arr[index].marks){
                index=j;
            }
            swap(arr[i],arr[index]);
        }
    }
}
int main()
{
    int n;
    cout<<"Enter number of students: ";
    cin >> n;
    Student *studs=new Student[n];
    for(int i=0;i<n;i++){
        cout<<"Enter details of student "<<(i+1)<<": "<<endl;
        cout<<"Enter name: ";
        cin>>studs[i].name;
        cout<<"Enter reg. no.: ";
        cin>>studs[i].reg_no;
        cout<<"Enter marks: ";
        cin>>studs[i].marks;
    }
    selection_sort(studs,n);
    cout<<"Students sorted on marks :"<<endl;
    for(int i=0;i<n;i++){
        cout<<studs[i].name<<" "<<studs[i].reg_no<<" "<<studs[i].marks<<endl;
    }
    return 0;
}