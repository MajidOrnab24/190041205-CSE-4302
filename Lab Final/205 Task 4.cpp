#include<iostream>
using namespace std;
class Furniture
{
protected:
    int model;
    string name;
    int a;
public:
    public:
    Furniture()
    {
    name="";
    model=0;
    a=0;
    }
    Furniture(int a,string b)
    {
    name="";
    model=0;
    a=0;
    }
    virtual void getdata()
    {
     cout<<"Name :"<<name<<endl;
     cout<<"Model :"<<model<<endl;
    }
    virtual void setdata()
    {
     cin>>name;
     cin>>model;
    }
     virtual int get_a()
    {
        return a;
    }
};
class Bed : public Furniture
{
private:
    int a;
    string bedsize;
public:
    public:
    Bed()
    {
    name=" ";
    model=0;
    bedsize=" ";
    a=1;
    }
    Bed(int a,string b,string c)
    {
    name=b;
    model=a;
    bedsize=c;
    a=1;
    }
   void getdata()
    {
     Furniture::getdata();
     cout<<"Bed Size :"<<bedsize<<endl;
    }
  void setdata()
    {
        Furniture::setdata();
        cin>>bedsize;
    }
    int get_a()
    {
        return a;
    }
};

class Almirah : public Furniture
{
private:
    int a;
    int height;
public:
    public:
    Almirah()
    {
    name=" ";
    model=0;
    height=0;
    a=2;
    }
    Almirah(int a,string b,int c)
    {
    name=b;
    model=a;
    height=c;
    a=2;
    }
   void getdata()
    {
     Furniture::getdata();
     cout<<"Height :"<<height<<endl;
    }
  void setdata()
    {
        Furniture::setdata();
        cin>>height;
    }
    int get_a()
    {
        return a;
    }
};
class Sofa : public Furniture
{
private:
    int a;
    int seat;
public:
    public:
    Sofa()
    {
    name=" ";
    model=0;
    seat=0;
    a=3;
    }
    Sofa(int a,string b,int c)
    {
    name=b;
    model=a;
    seat=c;
    a=3;
    }
   void getdata()
    {
     Furniture::getdata();
     cout<<"Seat no :"<<seat<<endl;
    }
  void setdata()
    {
        Furniture::setdata();
        cin>>seat;
    }
    int get_a()
    {
        return a;
    }
};
void swap(Furniture** f1,Furniture** f2)
{
    if((*f1)->get_a()<(*f2)->get_a())
    {
        Furniture* temp = *f1;
        *f1=*f2;
        *f2=temp;
    }
}
void sortByFurnitureType(Furniture** f, int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        swap(f+i,f+j);
}
int main()
{
    Furniture* f[20];
    for (int i=0;i<20;i++)
        f[i]=nullptr;
    int n=0,i;
    bool temp;
    while(1)
  {
      cout<<"Enter choice:(1 for bed, 2 for sofa, 3 for Almirah)"<<endl;
      cin>>i;
     switch(i)
      {
      case 1:
          {
            f[n]=new Bed(1,"Bed1","large");
            f[n]->setdata();
            f[n]->getdata();
            n++;
          }
        break;
      case 2:
          {
            f[n]=new Sofa(1,"Sofa",4);
            f[n]->setdata();
            f[n]->getdata();
            n++;
          }
        break;
      case 3:
          {
           f[n]=new Almirah(1,"Almirah1",5);
           f[n]->setdata();
           f[n]->getdata();

           n++;
          }
          break;
      case 0:
          {
            temp=true;
            break;
          }
      }
         if(n>=20-1||temp==true)
        {
            break;
        }

  }
  cout<<"Unsorted :"<<endl;
  for(int i=0;i<n;i++)
  {
      f[i]->getdata();
  }
  cout<<"Sorted :"<<endl;
    sortByFurnitureType(f,n);
  for(int i=0;i<n;i++)
  {
      f[i]->getdata();
  }
  for(int i=0;i<n;i++)
  {
      delete f[i];
  }
return 0;
}
