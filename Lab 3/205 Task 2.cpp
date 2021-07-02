#include<iostream>
using namespace std;
class RationalNumber
{
  private:
  int numerator;
  int denominator;
  public:
      int temp;
    void assign(int num,int den)
    {
        if(num==0 || den==0)
        {
            cout<<"Error!!"<<endl;
            return;
        }
        numerator=num;
        denominator=den;
        temp=num;
    }
    double convert()
    {
        cout<<"Convertion is"<<" "<<numerator*1.0/denominator*1.0<<endl;
    }
    void invert()
    {
        numerator=denominator;
        denominator=temp;
    }
    void print()
    {
        cout<<"The Rational Number is "<<numerator<<"/"<<denominator<<endl;
    }

};
int main()
{
     RationalNumber r;
    int i;
    while(1)
  {
      cin>>i;
      int d,n;
      switch(i)
      {
      case 1:
        cin>>n>>d;
            r.assign(n,d);
        break;
      case 2:
       r.convert();
        break;
      case 3:
        r.invert();
        break;
        case 4:
        r.print();
        break;
      case 0:
          exit(0);
      }
  }

}
