#include<iostream>
using namespace std;
class Seats
{
private:
    string comfortability;
    string seat_warmer;
public:
    void getdata()
    {
        cout<<"Enter comfortability level of the car"<<endl;
        cin>>comfortability;
        cout<<"Enter about seat warmer(if there is one enter 'one' else 'no' )"<<endl;
        cin>>seat_warmer;
    }
    void showdata()
    {
        cout<<"The Car experience is "<<comfortability<<endl;
        cout<<"The Car has "<<seat_warmer<<" seat warmer."<<endl;
    }

};
class Wheels
{
private:
    float circumferance;
public:
    Wheels()
    {
        circumferance=0;
    }
     void getdata()
     {
         cout<<"Enter Circumferance: ";
         cin>>circumferance;
     }
     void showdata()
     {
         cout<<"The Circumferance is : "<<circumferance<<endl;
     }
};
class Engine
{
private:
    float MFRC; //Maximum Fuel Consumption Rate
    float MERC; //Maximum Energy Production Rate
    float avg_rpm;
public:
    void getdata()
     {
         cout<<"Enter Maximum Fuel Consumption Rate: ";
         cin>>MFRC;
         cout<<"Enter Maximum Energy Production: ";
         cin>>MERC;
         cout<<"Enter Average RPM: ";
         cin>>avg_rpm;
     }
     void showdata()
     {
         cout<<"Maximum Fuel Consumption Rate is: "<<MFRC<<endl;
         cout<<"Maximum Energy Production Rate is: "<<MERC<<endl;
         cout<<"Average RPM is: "<<avg_rpm<<endl;
     }

};
class Doors
{
private:
    string op_mode; // Opening mode
public:
    void getdata()
    {
        cout<<"Enter opening mode of doors of the car :";
        cin>>op_mode;
    }
    void showdata()
    {
        cout<<"Opening mode of the car is "<<op_mode<<endl;
    }

};
class Car
{
private:
    float max_accl; //maximum_acceleration
    float fuel_capacity;
public:
    Car()
    {
        max_accl=0;
        fuel_capacity=0;
    }
    Seats s[3];
    Wheels w[3];
    Engine e;
    Doors d[3];
    void showdata()
    {
        cout<<"\nThe Car details are as follows: \n"<<endl;
        for(int i=0;i<3;i++)
        {
            cout<<"For Seat "<<i+1<<endl;
            s[i].showdata();
        }
        for(int i=0;i<3;i++)
        {
            cout<<"For Wheel "<<i+1<<endl;
            w[i].getdata();
        }
        e.showdata();
        for(int i=0;i<3;i++)
        {
            cout<<"For Door "<<i+1<<endl;
            d[i].getdata();
        }
        cout<<"Maximum Accelaration is : "<<max_accl<<endl;
        cout<<"Fuel Capacity is : "<<fuel_capacity<<endl;

    }
    void getdata()
    {
        cout<<"Enter Maximum Accelaration : ";
        cin>>max_accl;
        cout<<"Enter Fuel Capacity : ";
        cin>>fuel_capacity;
        for(int i=0;i<3;i++)
        {
            cout<<"For Seat "<<i+1<<endl;
            s[i].getdata();
        }
        for(int i=0;i<3;i++)
        {
            cout<<"For Wheel "<<i+1<<endl;
            w[i].getdata();
        }
        e.getdata();
        for(int i=0;i<3;i++)
        {
            cout<<"For Door "<<i+1<<endl;
            d[i].getdata();
        }
    }
};
int main()
{
    Car c;
    c.getdata();
    c.showdata();
    return 0;
}
