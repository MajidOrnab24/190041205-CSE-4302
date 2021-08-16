#include<iostream>
using namespace std;
class Furniture
{
protected:
    int regularPrice,discountPrice;
    string material,name;
public:
    Furniture()
    {
    regularPrice=0;
    discountPrice=0;
    material="Nothing";
    name="Null";
    }
    Furniture(int a, int b, string c,string d)
    {
    regularPrice=a;
    discountPrice=b;
    material=c;
    name=d;
    }
    virtual int getDprice()
    {
        return discountPrice;
    }
    virtual void getdata()
    {
     cout<<"void getdata furniture class"<<endl;
    }
    virtual void productDetails()
    {
        cout<<"void productDetails furniture class"<<endl;
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
    Bed(int a, int b, string c, string d,string e)
    {
    regularPrice=a;
    discountPrice=b;
    material=c;
    bedSize=d;
    name=e;
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
        cout<<"Enter Name : ";
        cin>>name;
    }
    int getDprice()
    {
        return discountPrice;
    }
    void productDetails()
    {
        cout<<"-------------------------------------------------------------------------"<<endl;
        cout<<"Name : "<<name<<"\nRegular Price: "<<regularPrice<<"\nDiscount Price: "<<discountPrice<<"\nMaterial: "<<material
        <<"\nBed Size : "<<bedSize<<endl;
        cout<<"##########################################################################"<<endl;
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
    Sofa(int a, int b, string c, int d,string e)
    {
    regularPrice=a;
    discountPrice=b;
    material=c;
    seatNumber=d;
    name=e;
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
        cout<<"Enter Name : ";
        cin>>name;
    }
    int getDprice()
    {
        return discountPrice;
    }
    void productDetails()
    {
        cout<<"-------------------------------------------------------------------------"<<endl;
        cout<<"Name : "<<name<<"\nRegular Price: "<<regularPrice<<"\nDiscount Price: "<<discountPrice<<"\nMaterial: "<<material
        <<"\nSeat Number : "<<seatNumber<<endl;
        cout<<"##########################################################################"<<endl;
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
    DiningTable(int a, int b, string c, int d,string e)
    {
    regularPrice=a;
    discountPrice=b;
    material=c;
    chairCount=d;
    name=e;
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
        cout<<"Enter Name : ";
        cin>>name;
    }
    int getDprice()
    {
        return discountPrice;
    }
    void productDetails()
    {
        cout<<"-------------------------------------------------------------------------"<<endl;
        cout<<"Name : "<<name<<"\nRegular Price: "<<regularPrice<<"\nDiscount Price: "<<discountPrice<<"\nMaterial: "<<material
        <<"\nChair Count : "<<chairCount<<endl;
        cout<<"##########################################################################"<<endl;
    }

};
void swap(Furniture** f1,Furniture** f2)
{
    if((*f1)->getDprice()<(*f2)->getDprice())
    {
        Furniture* temp = *f1;
        *f1=*f2;
        *f2=temp;
    }
}
void sort_furniture_price(Furniture** f, int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        swap(f+i,f+j);
}
int main()
{
    Furniture* f[100];
    for (int i=0;i<100;i++)
        f[i]=nullptr;
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
            f[n]=new Bed(1000,800,"Wood","Single","Deluxe");
            //f[n]->getdata();
            f[n]->productDetails();
            n++;

          }
        break;
      case 2:
          {
            f[n]=new Sofa(1100,700,"Wood",4,"Exclusive");
            f[n]->getdata();
            f[n]->productDetails();
            n++;
          }
        break;
      case 3:
          {
           f[n]=new DiningTable(1200,1000,"Glass",6,"glassp");
           f[n]->getdata();
           f[n]->productDetails();
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
  cout<<"Unsorted :"<<endl;
  for(int i=0;i<n;i++)
  {
      f[i]->productDetails();
  }
  cout<<"Sorted :"<<endl;
    sort_furniture_price(f,n);
  for(int i=0;i<n;i++)
  {
      f[i]->productDetails();
  }
  for(int i=0;i<n;i++)
  {
      delete f[i];
  }
return 0;
}
