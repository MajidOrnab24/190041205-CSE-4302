#include <iostream>
#include"doctor.h"
#include<windows.h>
using namespace std;

void print()
{
    cout << "***************************** HOSPITAL MANAGEMENT SYSTEM***************************************"
         "\n'a' -- FOR THE ADMIN PANEL"
         "\n'p' -- FOR PATIENTS MENU"
         "\n'd' -- FOR DOCTOR MENU"
         "\n'l' -- FOR LAB TEST"
         "\n'w' -- FOR ADMISSION IN A WARD"
         "\n's' -- FOR SAVING ALL DOCTOR DATA"
         "\n'r' -- FOR READING ALL DOCTOR DATA"
         "\n'x' -- exit"
         "\nEnter selection: ";

}
void printDept()
{

    for(int i=0; i<12; i++)
    {
        cout<<"Department no: "<<i+1<<"  & Name: "<<deptartment[i]<<endl;
    }
    cout<<"Enter Department No of the Department required: ";

}
int main()
{
    admin a;
    a.setAdata();
    char ch;

    while(true)
    {
        system("cls");
        print();
        cin >> ch;
        switch(ch)
        {
        case 'a':
            system("cls");
            if(a.ad==0)
            {
               a.verify();
            }
            if(a.ad==1)
            {
            system("cls");
            a.showdata();
            cout<<"Enter Choice: "<<"\nPRESS 1 FOR HIRING A DOCTOR"<<
                "\nPRESS 2 FOR INCREASING OR DECREASING WARDS"<<"\nPRESS 4 FOR INCREASING OR DECREASING BEDS IN ALL WARDS"<<endl;
            int adminC;
            cin>>adminC;
            switch(adminC)
            {
            case 1:
                system("cls");
                doctor::add();
                system("pause");
                break;
            case 2:
                system("cls");
                doctor::WardInDe();
                system("pause");
                break;
            case 4:
                system("cls");
                doctor::BedInDe();
                system("pause");
                break;
            default:
                cout << "\nUnknown command";

            }
             }
            break;
        case 'd':
            system("cls");
            cout<<"Enter Doctor ID: ";
            int Did;
            cin>>Did;
            doctor::searchAllpatientsOfDoc(Did);
            break;
        case 'w':
            system("cls");
            doctor::assignWardBed();
            break;
        case 's':
             doctor::write();
             system("pause");
             break;
        case 'r':
            doctor::deleteArr();
            doctor::read();
            system("pause");
             break;
        case 'l':
            system("cls");
            doctor::assignLab();
            break;
        case 'x':

            system("cls");
            exit(0);
            break;
        default:
            cout << "\nUnknown command"<<endl;
            system("pause");
            break;
        case 'p':
            int flag,d;
            int k=0;
            system("cls");
            cout<<"ENTER DOCTOR TYPE: "<<"\nPRESS 1 FOR PHYSICIAN"<<"\nPRESS 2 FOR DOCTOR OF EMERGENCY MEDICINE"<<
                "\nPRESS 3 FOR INDOOR DOCTOR"<<"\nPRESS 4 FOR SURGEON"<<endl;
                cin>>flag;
                switch(flag)
                {
                case 1:
                    printDept();
                    cin>>d;
                    doctor::searchD_ID(d,flag);
                    k=1;
                    break;
                case 2:
                    printDept();
                    cin>>d;
                    doctor::searchD_ID(d,flag);
                    k=1;
                    break;
                case 3:
                    printDept();
                    cin>>d;
                    doctor::searchD_ID(d,flag);
                    k=1;
                    break;
                case 4:
                    printDept();
                    cin>>d;
                    doctor::searchD_ID(d,flag);
                    k=1;
                    break;
                default:
                    cout << "\nUnknown command\n";
                    system("pause");
                    break;
                }

            break;


        }
    }
    return 0;
}
