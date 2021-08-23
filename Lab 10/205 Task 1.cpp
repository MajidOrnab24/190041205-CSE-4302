#include<iostream>
using namespace std;
class base_class //base class with virtual function
{
protected:
    int data1,data2;
public:
    base_class()
    {
      data1=0;
      data2=0;
    }
    base_class(int a, int b)
    {
     data1=a;
     data2=b;
    }
    void getdata()
    {
        cin>>data1>>data2;
    }
    virtual void showdata() //virtual function
    {
        cout<<"From base_class class  :"<<data1*data2<<endl;
    }

};
/*
class base_class //base class with pure virtual function
{
protected:
    int data1,data2;
public:
    base()
    {
      data1=0;
      data2=0;
    }
    base(int a, int b)
    {
     data1=a;
     data2=b;
    }
    void getdata()
    {
        cin>>data1>>data2;
    }
    virtual void showdata() //pure virtual function
    {}

};
*/
class derived_class :public base_class
{
private:
    int data3;
public:
    derived_class()
    {
      data1=0;
      data2=0;
    }
    derived_class(int a, int b)
    {
     data1=a;
     data2=b;
    }
    void showdata()
    {
       data3=100;
       cout<<"from derived class  : "<<data1+data2*data3<<endl;
    }

};
/*
class derived_class :public base_class // derived class without overridden function tested to see if it will work on virtual or pure
{                                     //virtual function .it will work on virtual function as it has a statement defined in the function
private:                                //calling the base class's function but won't work in case of pure virtual function since there
    int data3;                         //is no sttatement
public:
    derived_class()
    {
      data1=0;
      data2=0;
    }
    derived_class(int a, int b)
    {
     data1=a;
     data2=b;
    }

};
*/
int main()
{
    base_class* b;

   // b=new base_class();
    //b->getdata();
    //b->showdata();
    b = new derived_class(6,7);
    b->getdata();
   b->showdata();
}
