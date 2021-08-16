#include<iostream>
using namespace std;
class Furniture
{
protected:
    int regularPrice,discountPrice;
    string material;
public:
    Furniture()
    {
    regularPrice=0;
    discountPrice=0;
    material="Nothing";
    }
    Furniture(int a, int b, string c)
    {
    regularPrice=a;
    discountPrice=b;
    material=c;
    }
    virtual void getdata()
    {
     cout<<"void getdata furniture class"<<endl;
    }

};
class Bed : public Furniture
{
private:
    string bedSize;
public:
    Bed()
    {
    bedSize="Nothing";
    }
    Bed(int a, int b, string c, string d)
    {
    regularPrice=a;
    discountPrice=b;
    material=c;
    bedSize=d;
    }
    void getdata()
    {
        cout<<"Enter Regular Price: ";
        cin>>regularPrice;
        cout<<"Enter Discount Price: ";
        cin>>discountPrice;
        cout<<"Enter Material Type: ";
        cin>>material;
        cout<<"Enter Bed size : ";
        cin>>bedSize;
    }
};
class Sofa : public Furniture
{
private:
    int seatNumber;
public:
    Sofa()
    {
    seatNumber=0;
    }
    Sofa(int a, int b, string c, int d)
    {
    regularPrice=a;
    discountPrice=b;
    material=c;
    seatNumber=d;
    }
    void getdata()
    {
        cout<<"Enter Regular Price: ";
        cin>>regularPrice;
        cout<<"Enter Discount Price: ";
        cin>>discountPrice;
        cout<<"Enter Material Type: ";
        cin>>material;
        cout<<"Enter Seat Number : ";
        cin>>seatNumber;
    }

};
class DiningTable : public Furniture
{
private:
    int chairCount;
public:
    DiningTable()
    {
    chairCount=0;
    }
    DiningTable(int a, int b, string c, int d)
    {
    regularPrice=a;
    discountPrice=b;
    material=c;
    chairCount=d;
    }
    void getdata()
    {
        cout<<"Enter Regular Price: ";
        cin>>regularPrice;
        cout<<"Enter Discount Price: ";
        cin>>discountPrice;
        cout<<"Enter Material Type: ";
        cin>>material;
        cout<<"Enter Chair Count : ";
        cin>>chairCount;
    }

};
int main()
{
    Furniture *f[100];
    int n=0,i;
    bool temp;
    while(1)
  {
      cout<<"Enter choice:(1 for bed, 2 for sofa, 3 for dining table)"<<endl;
      cin>>i;
     switch(i)
      {
      case 1:
          {
            f[n]=new Bed(1000,800,"Wood","Single");
            //f[n]->getdata();
            cout<<"Info Has been stored"<<endl;
            n++;

          }
        break;
      case 2:
          {
            f[n]=new Sofa(1100,700,"Wood",4);
            f[n]->getdata();
            cout<<"Info Has been stored"<<endl;
            n++;
          }
        break;
      case 3:
          {
           f[n]=new DiningTable(1200,1000,"Glass",6);
           f[n]->getdata();
           cout<<"Info Has been stored"<<endl;
           n++;
          }
          break;
      case 0:
          {
            temp=true;
            break;
          }
      }

         if(n>=100-1||temp==true)
        {
            break;
        }

  }
  for(int i=0;i<n;i++)
  {
      delete f[i];
  }

return 0;
}
