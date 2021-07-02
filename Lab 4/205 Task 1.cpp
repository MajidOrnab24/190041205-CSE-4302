#include<iostream>
<<<<<<< HEAD

=======
>>>>>>> 5a06033209a97cd84ee544a60e435d7eae994b46
using namespace std;
class Calculator
{
private:
    int val;

public:
    Calculator():val(0){}
    Calculator(int r):val(r){}
    void add(int value)
    {
        int result;
        result=getvalue()+value;
        setvalue(result);
    }
    void setvalue(int result)
    {
        val=result;

    }
    int getvalue()
    {
        return val;
    }
    void substract(int value)
    {
        int result;
        result=getvalue()-value;
        setvalue(result);
    }
    void multiply(int value)
    {
        int result;
        result=getvalue()*value;
        setvalue(result);
    }
    void divide(int value)
    {
        if(value==0)
        {
            cout<<"Divide by 0 is undefined"<<endl;
            return;
        }
        int result;
        val=getvalue()+value;
        setvalue(result);
    }
   void clear()
    {
        val=0;
    }
    void display()
    {
        cout<<"Calculator display: "<<val<<endl;

    }
    ~Calculator(){cout<<"Calculator object is destroyed."<<endl;}
};
int main()
{
    Calculator c;
    int i;
    int value;
    while(1)
  {
      cout<<"Enter 1 to add"<<"\n"
               <<"Enter 2 to substract"<<"\n"
               <<"Enter 3 to multiply"<<"\n"
               <<"Enter 4 to divide"<<"\n"
               <<"Enter 5 to clear"<<"\n";
      cin>>i;
      switch(i)
      {


      case 1:
        cout<<"Enter Value to add"<<"\n";
        cin>>value;
            c.add(value);
        break;
      case 2:
       cout<<"Enter Value to substract"<<"\n";
        cin>>value;
            c.substract(value);
        break;
      case 3:
        cout<<"Enter Value to multiply"<<"\n";
        cin>>value;
            c.multiply(value);
        break;
        case 4:
        cout<<"Enter Value to divide"<<"\n";
        cin>>value;
            c.divide(value);
        break;
        case 5:
            c.clear();
            c.~Calculator();
            break;
      case 0:
          exit(0);
      }
      c.display();

  }

}
