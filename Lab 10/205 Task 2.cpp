#include<iostream>
using namespace std;
class test
{
private:
    int data1,data2;
public:
    test()
    {
        data1=0;
        data2=0;
    }
    test(int a, int b)
    {
        data1=a;
        data2=b;
    }
    void getdata()
    {
        cin>>data1>>data2;
    }
    void showdata()
    {
        cout<<"Data1 = "<<data1<<"\nData2 = "<<data2<<endl;
    }
    test operator = (const test& t)
    {
        data1=t.data1;
        data2=t.data2;
        return *this;
    }
    test (const test& t)
    {
       data1=t.data1;
       data2=t.data2;

    }
};
/*
class test //this class is for showing the limitation of default copy constructor and assignment operator  why they are not suitable
{
private:
    int data1,data2;
public:
    test()
    {
        data1=0;
        data2=0;
    }
    test(int a, int b)
    {
        data1=a;
        data2=b;
    }
    void getdata()
    {
        cin>>data1>>data2;
    }
    void showdata()
    {
        cout<<"Data1 = "<<data1<<"\nData2 = "<<data2<<endl;
    }
    test operator = (const test& t) //we only want to assign value of data1 not data2 of t to this object, keeping value of data2=100
    {
        data1=t.data1;
        data2=100;
        return *this;
    }
    test (const test& t)//we only want to copy value of data1 not data2 of t to this object,keeping value of data2=100
    {
       data1=t.data1;
       data2=100;

    }
};*/
   //since in case of default copy constructor and assignment operator both values would be copied or assigned but after overloading we
  //control which values need to be copied which not to be we can assign a value like 100 to other variable as here assigned
  // otherwise the console will show some garbage values since their value is not given in this particular object

/*
class test // class to restrict a class from copying from one object to another
{
private:
    int data1,data2;
    test operator = (const test& t){} // Since both assignment operator and copy constructor are defined in private,from main class these
    test (const test& t){}            //can't be used restricting usage of assignment operator and copy constructor
public:
    test()
    {
        data1=0;
        data2=0;
    }
    test(int a, int b)
    {
        data1=a;
        data2=b;
    }
    void getdata()
    {
        cin>>data1>>data2;
    }
    void showdata()
    {
        cout<<"Data1 = "<<data1<<"\nData2 = "<<data2<<endl;
    }

};*/
int main()
{
    test a(10,6),b(1,2),c(7,8);
    cout<<"For object a"<<endl;
    a.showdata();
    cout<<"For object b"<<endl;
    b.showdata();
    cout<<"For object c"<<endl;
    c.showdata();
    a=b;
    cout<<"For object a after assignment"<<endl;
    a.showdata();
    cout<<"For object b after assignment"<<endl;
    b.showdata();
    test d(c); //test d=c; another way of writing

    cout<<"For object d after initialization"<<endl;
    d.showdata();
    test fun=d;

}
