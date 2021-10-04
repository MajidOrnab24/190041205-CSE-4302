#include <bits/stdc++.h>
using namespace std;
#include <process.h>
const int LIMIT = 10;
template<typename T>
class safearay
{
private:
    T arr[LIMIT];
public:
    class error_class
    {};
    T & operator [](int  n)
    {
        if( n< 0 || n>=LIMIT )
        {
           throw error_class();
        }
        return arr[n];
    }
};
int main()
{
    try{
    safearay<int> sa1;
    for(int j=0; j<LIMIT; j++)
        sa1[j] = j*10;
    for(int j=0; j<=LIMIT; j++)
    {
        int temp = sa1[j];
        cout << "Element " << j << " is   " << temp << endl;
    }
    }
    catch(safearay<int>::error_class)
    {
        cout<<"Index out of bound error "<<endl;
    }



}
