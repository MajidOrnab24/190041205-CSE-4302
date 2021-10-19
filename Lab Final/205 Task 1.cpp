#include<iostream>
using namespace std;
class Fruit
{
private:
    string name;
    double price;
    enum taste  {sour, sweet, salty, bitter, umami};
    enum condition {best, better, good, bad};
public:
    Fruit()
    {
        name=" ";
        price=0;
        taste t="";
    }
    Fruit(string str,taste t1)
    {
        name=str;
        taste t=t1;
    }
    void getdata()
    {
        cout<<"name :"<<name<<endl;
        cout<<"price :"<<price<<endl;
        cout<<"taste :"<<taste<<endl;
        cout<<"condition :"<<condition<,endl;

    }
    void setdata()
    {
        cin>>name;
        cin>>price;
        cin>>taste;
        cin>>condition;
    }
    void conditionReduced()
    {

    }



};
