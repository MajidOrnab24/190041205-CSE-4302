#include <bits/stdc++.h>
using namespace std;

template< class T>
T amax(T *arr, int n )
{
    int i=0;
    T mx=-1e18;
    for(i=0;i<n;i++)
    {
        if(arr[i]>mx)
            mx=arr[i];
    }
    return mx;
}

int main()
{


      int arr[]={1,2,3,4,5,6,7,456545};
      cout<<amax<int>(arr,8)<<endl;
      double arr1[]={1.2020,1.222,1.333,1.454};
      cout<<amax<double>(arr1,4)<<endl;
      char arr2[]={'a','d','b','b'};
      cout<<amax<char>(arr2,4)<<endl;

}

