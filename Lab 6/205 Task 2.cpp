#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Matrix3D
{
private:

    enum {s=3};
    double arr[s][s];
public:
    Matrix3D()
    {
        for(int i=0;i<s;i++)
        {
            for(int j=0;j<s;j++)
            {
                arr[i][j]=0;
            }
        }

    }
    void getElements()
    {
        for(int i=0;i<s;i++)
        {
            for(int j=0;j<s;j++)
            {
                cin>>arr[i][j];
            }
        }

    }
    double det()
    {
       double determinant = arr[0][0] * ((arr[1][1]*arr[2][2]) - (arr[2][1]*arr[1][2])) -arr[0][1] * (arr[1][0]
         * arr[2][2] - arr[2][0] * arr[1][2]) + arr[0][2] * (arr[1][0] * arr[2][1] - arr[2][0] * arr[1][1]);
         return determinant;
    }
    Matrix3D operator + (Matrix3D m)
    {
        Matrix3D temp;
        for(int i=0;i<s;i++)
        {
            for(int j=0;j<s;j++)
            {
                temp.arr[i][j]=arr[i][j]+m.arr[i][j];
            }
        }
        return temp;
    }
    Matrix3D operator - (Matrix3D m)
    {
        Matrix3D temp;
        for(int i=0;i<s;i++)
        {
            for(int j=0;j<s;j++)
            {
                temp.arr[i][j]=arr[i][j]-m.arr[i][j];
            }
        }
        return temp;
    }
     Matrix3D operator * (Matrix3D m)
    {
        Matrix3D temp;
        for(int i=0;i<s;i++)
        {
           for(int j=0;j<s;j++)
            {
            for(int k=0;k<s;k++)
              {
                temp.arr[i][j] += arr[i][k] *m.arr[k][j];
              }
            }
        }

        return temp;
    }
    Matrix3D inverse()
    {
        Matrix3D temp;
     if(this->det()==0)
     {
         cout<<"Error! Singular matrix, So no determinant "<<endl;
         return temp;
     }

         for(int i=0;i<s;i++)
        {
            for(int j=0;j<s;j++)
            {
                temp.arr[i][j]=((arr[(j+1)%3][(i+1)%3] * arr[(j+2)%3][(i+2)%3]) - (arr[(j+1)%3][(i+2)%3] * arr[(j+2)%3][(i+1)%3]));
                temp.arr[i][j]/=this->det();
            }
        }
        return temp;

    }
    void  display()
    {
         for(int i=0;i<s;i++)
        {
            for(int j=0;j<s;j++)
            {
                cout << " " << arr[i][j];
              if(j == s-1)
                 cout << endl;
            }
        }
        cout<<endl;

    }
    ~Matrix3D(){}

};
main()
{
    Matrix3D c1,c2,c3,c4,c5;
    c1.display();
    c1.getElements();
    c1.display();
    cout<<"Determinant of c1= "<<c1.det()<<endl;
    c2.getElements();
    c2.display();
    c3=c1+c2;
    cout<<"Sum of c1 & c2"<<endl;
    c3.display();
    c3=c1-c2;
    cout<<"Subtraction of c1 & c2"<<endl;
    c3.display();
    c3=c1*c2;
    cout<<"Multiplication of c1 & c2"<<endl;
    c3.display();
    c4.getElements();
    c5=c4.inverse();
    cout<<"Inverse Matrix of c4 is :"<<endl;
    c5.display();


}
