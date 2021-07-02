#include<iostream>
<<<<<<< HEAD

=======
>>>>>>> 5a06033209a97cd84ee544a60e435d7eae994b46
using namespace std;
class Rectangle
{
 private:
    float length;
    float width;
 public:
    Rectangle()
    {
        length=1;
        width=1;
    }
    Rectangle(float i=1,float j=1)
    {
        length=i;
        width=j;
    }
    void setvalue(float a, float b)
      {
          if(!(a>=1.0&&a<20.0)&&(b>=1.0&&b<20.0))
          {return;}
          length=a;
          width=b;
      }
      void get()
      {
          float a,b;
          cin>>a>>b;
          setvalue(a,b);
      }
      float perimeter()
      {
          float p;
          p=2*(length+width);
          return p;
      }
      float area()
      {
          float a;
          a=length*width;
          return a;
      }

};
main()
{
    Rectangle r1(7,9);
    cout<<"Perimeter: "<<r1.perimeter()<<endl;
    cout<<"Area: "<<r1.area()<<endl;

    Rectangle r(8);
    cout<<"Perimeter: "<<r.perimeter()<<endl;
    cout<<"Area: "<<r.area()<<endl;

    r.get();
    cout<<"Perimeter: "<<r.perimeter()<<endl;
    cout<<"Area: "<<r.area()<<endl;
    return 0;
}
