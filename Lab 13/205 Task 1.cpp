#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10];
    int i,c;
    for(i=0;i<10;i++)
    {
        arr[i]=i*2+2;
    }
    cout<<"The even Array is"<<endl;
    for(int i=0;i<10;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    set<int>st;
    for( i=0;i<10;i++)
    {
        st.insert(i*2+1);
    }
    cout<<"The odd Set is"<<endl;
    for(auto x:st)
    cout<<x<<" ";

    vector<int>v(20);
    merge(arr,arr+10,st.begin(),st.end(),v.begin());
    cout<<"\nAfter merging the vector is"<<endl;
    for(auto x:v)
        cout<<x<<" ";

}
