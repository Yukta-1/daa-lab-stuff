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

void max(list<int> g)
{
    list <int> ::iterator it;
    int max=0;
    for(it = g.begin(); it != g.end(); ++it)
    {
        if(*it>max)
        {
            max=*it;
        }
    }
    cout<<max;
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

    cout << "list: ";
    showlist(l1);
    cout<<"Max element in list: ";
    max(l1);
    return 0;
}