#include<iostream>
using namespace std;
namespace my_namespace
{
   void print()
   {
       cout<<"From namespace print funtion"<<endl;
   }
}
void print()
{
    cout<<"A print function "<<endl;
}
int main()
{
    print();
    my_namespace::print();
}

