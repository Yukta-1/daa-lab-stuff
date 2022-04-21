#include <iostream>
#include <list>
#include <iterator>
using namespace std;
void showlist(list <int> g)
{
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout << "->" << *it;
    cout << '\n';
}
int main()
{
  
    list <int> l1;
  
  
    l1.push_back(10);
    l1.push_back(40);
    l1.push_back(20);
    l1.push_back(70);
    l1.push_back(30);
    l1.push_back(90);

    cout << "list before sorting: ";
    showlist(l1);
  
    cout << "list after sorting: ";
    l1.sort();
    showlist(l1);
    cout<<"Min element in list: "<<l1.front()<<endl;
    cout<<"Max element in list: " << l1.back()<<endl;
    return 0;
}