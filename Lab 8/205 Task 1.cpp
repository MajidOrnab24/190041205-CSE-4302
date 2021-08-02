#include<iostream>
#include <cmath>
using namespace std;

class Shape //Base class shape
{
protected:
     float length; // length for the shapes 2d & 3d in case of shapes like circle will be used as radius
public:
    Shape()
    {
        length=0;
        //cout<<"I am a Shape"<<endl;
    }
    void getdata()
    {
        cin>>length;
    }
    void whoAmI() //Dummy function for knowing Shape
    {
        cout<<"I am a Shape "<<endl;
    }

};

class TwoDimentionalShape:public Shape //Derived class TwoDimentionalShape
{
protected :
    float area,perimeter;
public:
    TwoDimentionalShape()
    {
        area=0;
        perimeter=0;
        //cout<<"I am a two-dimensional shape "<<endl;
    }

    void showdata()
    {
        cout<<"The required area and perimeter of is"<<"\n";
        cout<<"Area="<<area<<"\n"<<"Perimeter="<<perimeter<<endl;
    }
    void whoAmI()//Dummy overridden function for knowing Shape dimention
    {
        Shape::whoAmI();
        cout<<"I am a two-dimensional shape "<<endl;
    }
};

class Square : public TwoDimentionalShape //Square the derived class from  TwoDimentionalShape derived class
{
public:
    Square() //contructor
    {
        area=0;
        perimeter=0;
        length=0;
    }
    void showdata()
    {
      area=length*length; //calculation
      perimeter=4*length;
      TwoDimentionalShape:: showdata(); //overridden showdata() from derived TwoDimentionalShape class
    }
    void getdata()
    {
        cout<<"Provide a side for square"<<endl;
        Shape::getdata(); //overridden getdata() from shape class
    }
    void whoAmI() // for knowing class name
    {
        TwoDimentionalShape::whoAmI();
        cout<<"I am a Square "<<endl;
    }

};
class Rectangle : public TwoDimentionalShape //Rectangle the derived class from  TwoDimentionalShape derived class
{
private:
    float breadth;
public:
    Rectangle() //constructor
    {
        area=0;
        perimeter=0;
        length=0;
        breadth=0;
    }
    void showdata()
    {
      area=length*breadth;//calculation
      perimeter=2*length+2*breadth;
      TwoDimentionalShape:: showdata(); //overridden showdata() from derived TwoDimentionalShape class
    }
    void getdata()
    {
        cout<<"Provide length & breadth for rectangle"<<endl;
        cin>>breadth;
        Shape::getdata();//overridden getdata() from shape class
    }
    void whoAmI() // for knowing class name
    {
        TwoDimentionalShape::whoAmI();
        cout<<"I am a Rectangle "<<endl;
    }

};
class Circle : public TwoDimentionalShape//Circle the derived class from  TwoDimentionalShape derived class
{
public:
    Circle() //constructor
    {
        area=0;
        perimeter=0;
        length=0;
    }
    void showdata()
    {
      area=length*length*3.14; //calculation
      perimeter=2*length*3.14;
      TwoDimentionalShape:: showdata();//overridden showdata() from derived TwoDimentionalShape class
    }
    void getdata()
    {
        cout<<"Provide a radius for Circle"<<endl;
        Shape::getdata();//overridden getdata() from shape class
    }
    void whoAmI() // for knowing class name
    {
        TwoDimentionalShape::whoAmI();
        cout<<"I am a Circle "<<endl;
    }

};
class Triangle : public TwoDimentionalShape //Triangle the derived class from  TwoDimentionalShape derived class
{

public:
    Triangle() //constructor
    {
        area=0;
        perimeter=0;
        length=0;

    }
    void showdata()
    {
      area=sqrt(3)/4*(length*length); //calculation
      perimeter=length*3;
      TwoDimentionalShape:: showdata(); //overridden showdata() from derived TwoDimentionalShape class
    }
    void getdata()
    {
        cout<<"Provide a side for Triangle"<<endl;
        Shape::getdata();//overridden getdata() from shape class
    }
    void whoAmI() // for knowing class name
    {
        TwoDimentionalShape::whoAmI();
        cout<<"I am a Triangle "<<endl;
    }

};
class ThreeDimentionalShape:public Shape //Derived class ThreeDimentionalShape from class Shape
{
protected :
    float surface_area,volume;
public:
    ThreeDimentionalShape()
    {
        surface_area=0;
        volume=0;
       // cout<<"I am a three-dimensional shape"<<endl;
    }
   void showdata()
    {
        cout<<"The required Volume and Surface Area of is"<<"\n";
        cout<<"Volume="<<volume<<"\n"<<"Surface Area="<<surface_area<<endl;
    }
    void whoAmI() //Dummy overridden function for knowing Shape dimension
    {
        Shape::whoAmI();
        cout<<"I am a three-dimensional shape "<<endl;
    }
};
class Cube: public ThreeDimentionalShape //Cube the derived class from  ThreeDimentionalShape derived class
{
public:
    Cube() //constructor
    {
        length=0;
        surface_area=0;
        volume=0;
    }
    void showdata()
    {
      surface_area=length*length*6; //calculation
      volume=length*length*length;
      ThreeDimentionalShape:: showdata();//overridden showdata() from derived ThreeDimentionalShape class
    }
        void getdata()
    {
        cout<<"Provide a side for Cube"<<endl;
        Shape::getdata();//overridden getdata() from shape class
    }
    void whoAmI() // for knowing class name
    {
        ThreeDimentionalShape::whoAmI();
        cout<<"I am a Cube "<<endl;
    }

};
class Sphere: public ThreeDimentionalShape //Sphere the derived class from  ThreeDimentionalShape derived class
{
public:
    Sphere() //constructor
    {
        length=0;
        surface_area=0;
        volume=0;
    }
    void showdata()
    {
      surface_area=4*3.14*length*length; //calculation
      volume=(4/3)*3.14*length*length*length;
      ThreeDimentionalShape:: showdata(); //overridden showdata() from derived ThreeDimentionalShape class
    }
        void getdata()
    {
        cout<<"Provide a radius for Sphere"<<endl;
        Shape::getdata();//overridden getdata() from shape class
    }
    void whoAmI() // for knowing class name
    {
        ThreeDimentionalShape::whoAmI();
        cout<<"I am a Sphere "<<endl;
    }

};
class Cylinder: public ThreeDimentionalShape //Cylinder the derived class from  ThreeDimentionalShape derived class
{
private:
    float height;
public:
    Cylinder() //contructor
    {
        length=0;
        surface_area=0;
        volume=0;
        height=0;
    }
    void showdata()
    {
      surface_area=2*3.14*length*(length+height); //calculation
      volume=3.14*length*length*height;
      ThreeDimentionalShape:: showdata(); //overridden showdata() from derived ThreeDimentionalShape class
    }
        void getdata()
    {
        cout<<"Provide a radius and height for Cylinder"<<endl;
        Shape::getdata();//overridden getdata() from shape class
        cin>>height;
    }
    void whoAmI() // for knowing class name
    {
        ThreeDimentionalShape::whoAmI();
        cout<<"I am a Cylinder "<<endl;
    }

};
class Tetrahedron: public ThreeDimentionalShape //Tetrahedron the derived class from  ThreeDimentionalShape derived class
{
public:
    Tetrahedron() //constructor
    {
        length=0;
        surface_area=0;
        volume=0;
    }
    void showdata()
    {
      surface_area=sqrt(3)*length*length; //calculation
      volume=(length*length*length)/(6*sqrt(2));
      ThreeDimentionalShape:: showdata(); //overridden showdata() from derived ThreeDimentionalShape class
    }
        void getdata()
    {
        cout<<"Provide a edge for Tetrahedron"<<endl;
        Shape::getdata(); //overridden getdata() from shape class
    }
    void whoAmI() // for knowing class name
    {
        ThreeDimentionalShape::whoAmI();
        cout<<"I am a Tetrahedron "<<endl;
    }

};

int  main()
 {
     Square s;
     s.Square::whoAmI();
     s.Square::getdata();
     s.Square::showdata();
     Rectangle r;
     r.Rectangle::whoAmI();
     r.Rectangle::getdata();
     r.Rectangle::showdata();
     Circle c;
     c.Circle::whoAmI();
     c.Circle::getdata();
     c.Circle::showdata();
     Triangle t;
     t.Triangle::whoAmI();
     t.Triangle::getdata();
     t.Triangle::showdata();
     Cube c1;
     c1.Cube::whoAmI();
     c1.Cube::getdata();
     c1.Cube::showdata();
     Sphere s1;
     s1.Sphere::whoAmI();
     s1.Sphere::getdata();
     s1.Sphere::showdata();
     Cylinder c2;
     c2.Cylinder::whoAmI();
     c2.Cylinder::getdata();
     c2.Cylinder::showdata();
     Tetrahedron t1;
     t1.Tetrahedron::whoAmI();
     t1.Tetrahedron::getdata();
     t1.Tetrahedron::showdata();
  return 0;
 }
