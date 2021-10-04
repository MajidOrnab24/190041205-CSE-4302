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
    T & operator [](int  n)
    {
        if( n< 0 || n>=LIMIT )
        {
            cout << "\nIndex out of bounds";
            exit(1);
        }
        return arr[n];
    }
};
int main()
{
    safearay<int> sa1;
    for(int j=0; j<LIMIT; j++)
        sa1[j] = j*10;
    for(int j=0; j<LIMIT; j++)
    {
        int temp = sa1[j];
        cout << "Element " << j << " is   " << temp << endl;
    }
    cout<<endl;
    safearay<double> sa2;
    for(int j=0; j<LIMIT; j++)
        sa2[j]= j*2.01;
    for(int j=0; j<LIMIT; j++)
    {
        double temp = sa2[j];
        cout << "Element " << j << " is   " << temp << endl;
    }
    return 0;




}

