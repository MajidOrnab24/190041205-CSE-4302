#include<iostream>
<<<<<<< HEAD

=======
>>>>>>> 5a06033209a97cd84ee544a60e435d7eae994b46
using namespace std;
class Plane
{
    private:
    int Flight;
    string  Destination;
    float Distance;
    float MaxFuelCapacity;
    float Fuel;
    void CalFuel()
    {
        if(Distance<=1000)
            Fuel=500;
        else if(Distance>=1000&&Distance<=2000)
            Fuel=1100;
        else if(Distance>=2000)
            Fuel=2200;
    }
    public:
        Plane()
        {
            Flight=0;
            Destination="Not Chosen";
            Distance=0;
            MaxFuelCapacity=0;
        }
        void FeedInfo()
        {
            cin>>Flight>>Destination>>Distance>>MaxFuelCapacity;
            CalFuel();
            if(Fuel>=MaxFuelCapacity)
                cout<<"Fuel Capacity is fit for this flight"<<endl;
                else
                    cout<<"Not sufficient Fuel Capacity for this flight"<<endl;

        }
        void ShowInfo()
        {
            cout<<"Flight Number: "<<Flight<<"\n"
            "Destination: "<<Destination<<"\n"
            "Distance: "<<Distance<<"\n"
            "Max Fuel Capacity: "<<MaxFuelCapacity<<"\n";

        }

};
main()
{
    Plane p;
    p.ShowInfo();
    p.FeedInfo();
    p.ShowInfo();
}
