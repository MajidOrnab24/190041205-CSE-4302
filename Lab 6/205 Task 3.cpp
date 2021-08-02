#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
class Coordinate
{
private:
    float ordinate, abcissa;
public:
    Coordinate ()
    {
      ordinate =0;
      abcissa=0;
    }
    Coordinate(float a=0,float b=0)
    {
      ordinate =b;
      abcissa=a;
    }
    float getDistance(Coordinate c)
    {
        return sqrt(pow(abcissa-c.abcissa,2)+pow(ordinate-c.ordinate,2)*1.0);
    }
    float getDistance()
    {
        return sqrt(pow(abcissa, 2) + pow(ordinate, 2) * 1.0);
    }
    void move_x(float val)
    {
        abcissa+=val;
    }
    void move_y(float val)
    {
        ordinate+=val;
    }
    void move(float val)
    {
        move_x(val);
        move_y(val);
    }
    bool operator < (Coordinate a)
    {
      float x= this->getDistance();
      float  y=a.getDistance();
       return(x<y)? true : false;
    }
    bool operator > (Coordinate a)
    {
      float x= this->getDistance();
      float  y=a.getDistance();
       return(x>y)? true : false;
    }
    bool operator <= (Coordinate a)
    {
      float x= this->getDistance();
      float  y=a.getDistance();
       return(x<=y)? true : false;
    }
    bool operator >= (Coordinate a)
    {
      float x= this->getDistance();
      float  y=a.getDistance();
       return(x>=y)? true : false;
    }
    bool operator == (Coordinate a)
    {
      float x= this->getDistance();
      float  y=a.getDistance();
       return(x==y)? true : false;
    }
     bool operator != (Coordinate a)
     {
      float x= this->getDistance();
      float  y=a.getDistance();
       return(x!=y)? true : false;
    }
    Coordinate operator ++ ()
    {
       return Coordinate(++abcissa,++ordinate);
    }
    Coordinate operator -- ()
    {
       return Coordinate(--abcissa,--ordinate);
    }
     Coordinate operator ++ (int)
    {
        return Coordinate(abcissa++,ordinate++);
    }
     Coordinate operator -- (int)
    {
        return Coordinate(abcissa--,ordinate--);
    }
    void display()
    {
        cout<<"Co-ordinates are x= "<<abcissa<<" y= "<<ordinate<<endl;
    }
    ~Coordinate()
    {
    }

};
main()
{    Coordinate c1(8,9),c2(7.2,10.36),c3(1.6,5);
      cout<<"c1 "; c1.display();
      cout<<"c2 "; c2.display();
      cout<<"c3 "; c3.display();
      cout<<"Distance of c1 from 0,0 is "<< c1.getDistance()<<endl;
       cout<<"Distance of c1 from c2 is "<< c1.getDistance(c2)<<endl;
       c1.move_x(9);
       c1.move_y(10);
       cout<<"c1 "; c1.display();
       c1.move(20);
       cout<<"c1 "; c1.display();
       if( c1 < c2 )
      cout << "\nDistance of c1 is less than Distance of c2"<<endl;
      else
       cout << "\nDistance of c1 is not less than Distance of c2"<<endl;

      c1++;
      cout<<"c1 "; c1.display();
      ++c1;
      cout<<"c1 "; c1.display();
      c2--;
      cout<<"c2 "; c2.display();
      --c2;
      cout<<"c2 "; c2.display();

      if( c2 > c3 )
      cout << "\nDistance of c2 is greater than Distance of c3"<<endl;
      else
       cout << "\nDistance of c2 is not greater than Distance of c3"<<endl;
       if( c2 < c3 )
      cout << "\nDistance of c2 is less than Distance of c3"<<endl;
      else
       cout << "\nDistance of c2 is not less than Distance of c3"<<endl;
       if( c2 >= c3 )
      cout << "\nDistance of c2 is greater or equal than Distance of c3"<<endl;
      else
       cout << "\nDistance of c2 is not greater or equal than Distance of c3"<<endl;
              if( c2 <= c3 )
      cout << "\nDistance of c2 is less or equal than Distance of c3"<<endl;
      else
       cout << "\nDistance of c2 is not less or equal than Distance of c3"<<endl;
       if( c2 != c3 )
      cout << "\nDistance of c2 is is not equal to Distance of c3"<<endl;
      else
       cout << "\nDistance of c2 is  equal to Distance of c3"<<endl;
       if( c2 == c3 )
      cout << "\nDistance of c2 is is  equal to Distance of c3"<<endl;
      else
       cout << "\nDistance of c2 is  not equal to Distance of c3"<<endl;


     return 0;


}
