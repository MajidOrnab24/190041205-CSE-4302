#include <process.h>
#include<iostream>
#include <typeinfo>
#include"patient.h"
#include <stdio.h>
#include <string.h>
#include<string>
#include <vector>
#include<fstream>
using namespace std;
vector<patient*> pat;
enum doctor_type {d_p,d_e,d_i,d_s};
class doctor
{
protected:
    char degree[len],instituition[len],c_specialist[len],d_name[len];
    static int n;
    static int money;
    char dept[len];
    int d_id,doctorID;
    int p,i_shift,e_shift,wardAssign;
    static int wardno,bedno;
    int income;
    static int ward[][MAX];
    static doctor* arr[];
    int patient_no=0;
    int keeper[6][19];
public:
    doctor() {};
    ~doctor()
    {
        for(int i=0;i<n;i++)
        {
            delete arr[i];
        }
         delete []arr;
    };
    patient* patientPointer[108];
    static void add();
    static void WardInDe();
     static void deleteArr();
    static void BedInDe();
    static void display();
    static void read();
    static void assignWardBed();
    static void assignLab();
    static void write();
    static void searchD_ID(int,int);
    static void searchAllpatientsOfDoc(int);
    virtual doctor_type get_type();
    virtual void setD_data()
    {
        deptartment_no d=Cardiology;
        cout<<"Enter Doctor name: ";
        cin.ignore();
        cin.getline(d_name,len);
        cout<<"Enter Degree of Doctor: ";
        cin.getline(degree, len);
        cout<<"Enter instituition of doctor: ";
        cin.getline(instituition, len);
        cout<<"Enter Designation of the doctor: ";
        cin.getline(c_specialist, len);
        doctorID=1900+n;
        cout<<"Enter Department of Doctor:\n";
        for(int i=0; i<12; i++)
        {
            cout<<"Press  "<<i+1<<"  for   "<<deptartment[i]<<endl;;
        }
        int ch;
        cin>>ch;
        strcpy(dept,deptartment[ch-1]);
        d_id=d+ch;
        income=0;


    }
    virtual void showDetails()
    {
        cout<<"Doctor ID: "<<doctorID<<"\nDoctor Name: "<<d_name<<"\nDesignation:  " <<c_specialist<<"\nDegree : "<<degree<<"\nInstituition: "<<instituition<<
            "\nDepartment: "<<dept<<". Department ID: "<<d_id<<endl;
    }

};
int doctor::n;
int doctor::money;
int doctor::wardno=10;
int doctor::bedno=18;
int doctor::ward[MAX][MAX];
doctor* doctor::arr[MAX];

class physician : public doctor
{
private:


public:
    physician()
    {
    }
    ~physician() {}

    void setD_data()
    {
        doctor::setD_data();
        cout<<"Select the day in which the doctor will not work"<<endl;
        for(int i=0; i<7; i++)
        {
            cout<<"Press "<<i+1<<" for "<<week[i]<<endl;

        }
        cin>>p;
        int k=0;
        for(int i=0; i<7; i++)
        {
            if(i==p-1)
                continue;
            keeper[k][0]=i+1;
            k++;
        }
        for(int i=0; i<6; i++)
        {
            for(int j=1; j<19; j++)
            {
                keeper[i][j]=0;
            }
        }

    }
    void showDetails()
    {
        doctor::showDetails();
        int k=0;
        for(int i=0; i<7; i++)
        {
            if(i==p-1)
            {
                cout<<week[i]<<":- Not available any appointments"<<endl;
            }
            else
            {

                cout<<"DAY : "<<week[i]<<"; Working Day No: "<<i+1<<" Available Times slot:-\n";
                for(int j=1; j<19; j++)
                {
                    if(keeper[k][j]==0)

                        cout<<j<<" timeslot :-"<<timeslot[j-1]<<endl;


                }
                k++;

            }
        }
    }
};
class emergencyDoc : public doctor
{
private:

public:
    emergencyDoc() {}
    ~emergencyDoc() {}
    void setD_data()
    {
        doctor::setD_data();
        cout<<"Select Shift"<<endl;
        cout<<"Press 1 for 09 A.M - 08 P.M  or  Press 2 for 09 PM - 08 A.M "<<endl;
        cin>>e_shift;
        cout<<"Select the day in which the doctor will not work"<<endl;
        for(int i=0; i<7; i++)
        {
            cout<<"Press "<<i+1<<" for "<<week[i]<<endl;

        }
        cin>>p;
        int k=0;
        for(int i=0; i<7; i++)
        {
            if(i==p-1)
                continue;
            keeper[k][0]=i+1;
            k++;
        }
        for(int i=0; i<6; i++)
        {
            for(int j=1; j<13; j++)
            {
                keeper[i][j]=0;
            }
        }
    }
    void showDetails()
    {
        doctor::showDetails();
        int k=0;
        for(int i=0; i<7; i++)
        {
            if(i==p-1)
            {
                cout<<week[i]<<":- Not available any appointments"<<endl;
            }
            else
            {

                cout<<"DAY :"<<week[i]<<";  Working Day No: "<<i+1<<" Available Times slot:-\n";
                for(int j=1; j<13; j++)
                {
                    if(keeper[k][j]==0)
                    {
                        if(e_shift==1)
                            cout<<j<<" timeslot :-"<<timeslot1[j-1]<<endl;
                        else if(e_shift==2)
                            cout<<j<<" timeslot :-"<<timeslot2[j-1]<<endl;

                    }

                }
                k++;

            }
        }


    }


};
class indoorDoc : public doctor
{
private:

public:
    indoorDoc() {}
    ~indoorDoc() {}
    void setD_data()
    {
        doctor::setD_data();
        cout<<"Select Shift"<<endl;
        cout<<"Press 1 for 09 A.M - 08 P.M  or  Press 2 for 09 PM - 08 A.M "<<endl;
        cin>>i_shift;
        cout<<"Select the day in which the doctor will not work"<<endl;
        for(int i=0; i<7; i++)
        {
            cout<<"Press "<<i+1<<" for "<<week[i]<<endl;

        }
        cin>>p;
        cout<<"Enter Ward no. for Duty starting from 1 to "<<wardno<<endl;
        cin>>wardAssign;
        ward[wardAssign-1][0]=doctorID;
        int k=0;
        for(int i=0; i<7; i++)
        {
            if(i==p-1)
                continue;
            keeper[k][0]=i+1;
            k++;
        }
        for(int i=0; i<6; i++)
        {
            for(int j=1; j<13; j++)
            {
                keeper[i][j]=0;
            }
        }
    }
    void showDetails()
    {
        doctor::showDetails();
        int k=0;
        for(int i=0; i<7; i++)
        {
            if(i==p-1)
            {
                cout<<week[i]<<":- Not available any appointments"<<endl;
            }
            else
            {

                cout<<"DAY :"<<week[i]<<"; Working Day No: "<<i+1<<" Available Times slot:-\n";
                for(int j=1; j<13; j++)
                {
                    if(keeper[k][j]==0)
                    {
                        if(i_shift==1)
                            cout<<j<<" timeslot :-"<<timeslot1[j-1]<<endl;
                        else if(i_shift==2)
                            cout<<j<<" timeslot :-"<<timeslot2[j-1]<<endl;

                    }

                }
                k++;

            }
        }
         cout<<"Ward no: "<<wardAssign<<endl;
    }



};
class surgeon : public doctor
{
private:
    int p;

public:
    surgeon() {}
    ~surgeon() {}
    void setD_data()
    {
        doctor::setD_data();
        cout<<"Select the day in which the doctor will not work"<<endl;
        for(int i=0; i<7; i++)
        {
            cout<<"Press "<<i+1<<" for "<<week[i]<<endl;

        }
        cin>>p;
        int k=0;
        for(int i=0; i<7; i++)
        {
            if(i==p-1)
                continue;
            keeper[k][0]=i+1;
            k++;
        }
        for(int i=0; i<6; i++)
        {
            for(int j=1; j<19; j++)
            {
                keeper[i][j]=0;
            }
        }

    }
    void showDetails()
    {
        doctor::showDetails();
        int k=0;
        for(int i=0; i<7; i++)
        {
            if(i==p-1)
            {
                cout<<week[i]<<":- Not available any appointments"<<endl;
            }
            else
            {

                cout<<"DAY :"<<week[i]<<"; Working Day No: "<<i+1<<" Available Times slot:-\n";
                for(int j=1; j<19; j++)
                {
                    if(keeper[k][j]==0)
                        cout<<j<<" timeslot :-"<<timeslot[j-1]<<endl;


                }
                k++;

            }
        }
    }

};
void doctor::add()
{
    char ch;
    cout << "'P' to add a Physician"
         "\n'E' to add a Doctor of Emergency Medicine"
         "\n'I' to add a Indoor Doctor"
         "\n'S' to add a Surgeon"
         "\nEnter selection: ";
    cin >> ch;
    switch(ch)
    {
    case 'p':
        arr[n] = new physician;
        break;
    case 'e':
        arr[n] = new emergencyDoc;
        break;
    case 'i':
        arr[n] = new indoorDoc;
        break;
    case 's':
        arr[n] = new surgeon;
        break;
    default:
        cout << "\nUnknown doctor type\n";
        return;
    }
    arr[n++]->setD_data();
}
void doctor::display()
{
    for(int j=0; j<n; j++)
    {
        cout << (j+1);
        switch( arr[j]->get_type() )
        {
        case d_p:
            cout << ". Type: Physician\n";
            break;
        case d_e:
            cout << ". Type: Emergency\n";
            break;
        case d_i:
            cout << ". Type: Indoor\n";
            break;
        case d_s:
            cout << ". Type: Surgeon\n";
            break;
        default:
            cout << ". Unknown type";
        }
        arr[j]->showDetails();
        cout << endl;
    }
}
doctor_type doctor::get_type()
{
    if( typeid(*this) == typeid(physician) )
        return d_p;
    else if( typeid(*this)==typeid(emergencyDoc) )
        return d_e;
    else if( typeid(*this)==typeid(indoorDoc) )
        return d_i;
    else if( typeid(*this)==typeid(surgeon) )
        return d_s;
    else
    {
        cerr << "\n Error employe type";
        exit(1);
    }
    return d_p;
}
void doctor::write()
{
    int size;
    cout << "Al doctor info saved sucessfully\n";
    ofstream ouf;
    doctor_type Dtype;
    ouf.open("Doctor.DAT", ios::trunc | ios::binary);
    if(!ouf)
    {
        cout << "\nCan’t open file\n";
        return;
    }
    for(int j=0; j<n; j++)
    {
        Dtype = arr[j]->get_type();

        ouf.write( (char*)&Dtype, sizeof(Dtype) );
        switch(Dtype)
        {
        case d_p:
            size=sizeof(physician);
            break;
        case d_e:
            size=sizeof(emergencyDoc);
            break;
        case d_i:
            size=sizeof(indoorDoc);
            break;
        case d_s:
            size=sizeof(surgeon);
            break;
        }
        ouf.write((char*)(arr[j]),size);
        if(!ouf)
        {
            cout << "\nCan’t write to file\n";
            return;
        }
    }
}
void doctor::read()
{
    int size;
    doctor_type Dtype;
    ifstream inf;
    inf.open("Doctor.DAT", ios::binary);
    if(!inf)
    {
        cout << "\nCan’t open file\n";
        return;
    }
    n = 0;
    while(true)
    {
        inf.read( (char*)&Dtype, sizeof(Dtype) );
        if( inf.eof() )
            break;
        if(!inf)
        {
            cout << "\nCan’t read type from file\n";
            return;
        }
        switch(Dtype)
        {
        case d_p:
            arr[n] = new physician;
            size=sizeof(physician);
            break;
        case d_e:
            arr[n] = new emergencyDoc;
            size=sizeof(emergencyDoc);
            break;
        case d_i:
            arr[n] = new indoorDoc;
            size=sizeof(indoorDoc);
            break;
        case d_s:
            arr[n] = new surgeon;
            size=sizeof(surgeon);
            break;
        default:
            cout << "\nUnknown type in file\n";
            return;
        }
        inf.read( (char*)arr[n], size );
        if(!inf)
        {
            cout << "\nCan’t read data from file\n";
            return;
        }
        arr[n]->patient_no=0;
        n++;
    }
    cout << "All doctor data retrived succesfully\n";
}
void doctor::assignWardBed()
{
    cout<< "Patient MUST be under a indoor Doctor and concerned doctor must be assigned to a ward"<<endl;
    cout<<"Enter Doctor ID: ";
    int did,b,temp=0,pid,dockeep,c,bed;
    cin>>did;
    for(int i=0;i<n;i++)
    {
        if(arr[i]->doctorID==did)
        {
            b=arr[i]->wardAssign-1;
            temp++;
            dockeep=i;
            break;
        }
    }
    if(temp==0)
    {
        cout<<"Doctor assigned to ward not found"<<endl;
        system("pause");
        return;
    }
    else
    {
        cout<<"Patient ID: ";
        cin>>pid;
        for(int i=0; i<arr[dockeep]->patient_no; i++)
        {
            if(arr[dockeep]->patientPointer[i]->patientID==pid)
            {
                cout<<"Enter bed no (Must be from 1 to )"<<bedno<<endl;
                cin>>bed;
                if(bed<1||bed>bedno)
                {
                    cout<<"Invalid bed no try again"<<endl;
                     break;
                }
                ward[arr[dockeep]->wardAssign-1][bed]=arr[dockeep]->patientPointer[i]->patientID;
                arr[dockeep]->patientPointer[i]->pWard=arr[dockeep]->wardAssign;
                arr[dockeep]->patientPointer[i]->pBed=bed;
                 cout<<"Successfully Got into Ward"<<endl;
                 break;
            }
        }
    }
    system("pause");

}
void doctor::assignLab()
{
    cout<<"THE PATIENT MUST APPOINTED TO ANY DOCTOR BEFORE ANY LAB TEST"<<endl;
    int DId,PId,temp=0,dock,mon;
    char lab[len];
    cout<<"Enter Doctor ID: ";
    cin>>DId;
    for(int i=0;i<n;i++)
    {
        if(arr[i]->doctorID==DId)
        {
            temp++;
            dock=i;
            break;
        }
    }
    if(temp==0)
    {
        cout<<"Doctor not found"<<endl;
        system("pause");
        return;
    }
    else
    {
        cout<<"Patient ID: ";
        cin>>PId;
        for(int i=0; i<arr[dock]->patient_no; i++)
        {
            if(arr[dock]->patientPointer[i]->patientID==PId)
            {
                cout<<"Enter Name of lab test: ";
                cin.ignore();
                cin.getline(lab,len);
                cout<<"Enter your money";
                cin>>mon;
                money+=mon;
               arr[dock]->patientPointer[i]->labTest.push_back(lab);
               arr[dock]->patientPointer[i]->labCount++;
                 cout<<"Successfully Paid for Lab test and ready for lab"<<endl;
                 break;
            }
        }
    }
    system("pause");



}
void doctor::deleteArr()
{
    for(int i=0;i<n;i++)
        {
            delete arr[i];
        }
    delete []arr;
}
void doctor::WardInDe()
{
    cout<<"Present Number of Wards: "<<wardno<<endl;
    int a;
    cout<<"New number of Wards: ";
    cin>>a;
    wardno=a;


}
void doctor ::BedInDe()
{
    cout<<"Present Number of beds in each ward: "<<wardno<<endl;
    int a;
    cout<<"New number of beds in each ward: ";
    cin>>a;
    bedno=a;

}
void doctor::searchAllpatientsOfDoc(int d)
{
    int temp=-1,al,a;
    if(n==0)
    {
        cout<<"No Doctors available"<<endl;
        system("pause");
        return;
    }

    for(int i=0; i<n; i++)
    {
        if(arr[i]->doctorID==d)
        {
            cout<<"////////////////////////////////////////////////////"<<endl;
            cout<<"Doctor no: "<<i+1<<endl;
                        cout<<"Doctor ID: "<< arr[i]->doctorID<<"\nDoctor Name: "<<arr[i]->d_name<<"\nDesignation:  " <<arr[i]->c_specialist<<"\nDegree : "<<arr[i]->degree<<"\nInstituition: "
            <<arr[i]->instituition<<"\nDepartment: "<<arr[i]->dept<<". Department ID: "<<arr[i]->d_id<<endl;
            temp++;
        }
    }
    if(temp<0)
    {
        cout<<"No Doctors in that Doctor ID available"<<endl;
        system("pause");
        return;
    }
    cout<<"Press Doctor no. to find out about All his patients"<<endl;
    cin>>al;
    a=al-1;
    for(int i=0; i<arr[a]->patient_no; i++)
    {
        cout<<"****************************************************************"<<endl;
        arr[a]->patientPointer[i]->showPdetails();
    }
    if(arr[a]->patient_no==0)
        cout<<"No patients currently"<<endl;

    system("pause");

}
void doctor:: searchD_ID(int d,int flag)
{
    doctor_type Dtype;
    int mon;
    int temp=-1;
    if(n==0)
    {
        cout<<"No Doctors available"<<endl;
        system("pause");
        return;
    }

    for(int i=0; i<n; i++)
    {
        Dtype=arr[i]->get_type();
        if(arr[i]->d_id==d&&Dtype+1==flag)
        {
            cout<<"////////////////////////////////////////////////////"<<endl;
            cout<<"Doctor no: "<<i+1<<endl;
            arr[i]->showDetails();

            temp++;

        }

    }
    if(temp<0)
    {
        cout<<"No Doctors in that Department available"<<endl;
        system("pause");
        return;
    }

    cout<<"Press the Doctor No.for taking appointment: "<<endl;
    int al,a;
    int b,q,z,v,dayCount;
    switch(flag)
    {
    case 1:
        cin>>al;
        a=al-1;
        b=arr[a]->patient_no;
        if(b==108)
        {
            cout<<"No more appointments available";
            break;
        }
        arr[a]->patientPointer[b] = new regularPatient();
        arr[a]->patientPointer[b]->setP_data();
        q=arr[a]->patientPointer[b]->d;
        z=arr[a]->patientPointer[b]->t;
        dayCount=q;
        if(dayCount==arr[a]->p)
        {
            cout<<"Invalid Day to take appointment!!!! Try Again";
            system("pause");
            delete arr[a]->patientPointer[b];
            return;
        }
        v=arr[a]->patientPointer[b]->patientID;
        arr[a]->keeper[q-1][z]=v;
        arr[a]->patientPointer[b]->prevDoc.push_back(arr[a]->d_name);
        strcpy(arr[a]->patientPointer[b]->dayName,week[dayCount-1]);
        strcpy(arr[a]->patientPointer[b]->timeslotName,timeslot[z-1]);
        strcpy(arr[a]->patientPointer[b]->currDoc,arr[a]->d_name);
        cout<<"Enter Payment for appointment 500 tk"<<endl;
        while(true)
        {
             cin>>mon;
             if(mon==500)
             {
                 cout<<"Thank You for your kind Cooperation"<<endl;
                 break;
             }
             else if(mon>500)
             {
                 cout<<"Returned money :"<<mon-500<<" tk"<<endl;
                 cout<<"Thank You for your kind Cooperation"<<endl;
                 break;
             }
             else if(mon<500)
             {
                 cout<<"Requirement of money not met please provide 500 tk"<<endl;
             }
        }
        arr[a]->income=arr[a]->income+450;
        money=money+50;
        arr[a]->patientPointer[b]->totalPayment+=mon;
        b+=1;
        arr[a]->patient_no=b;
        break;
    case 2:
        cin>>al;
        a=al-1;
        b=arr[a]->patient_no;
        if(b==84)
        {
            cout<<"No more appointments available";
            break;
        }
        arr[a]->patientPointer[b] = new emergencyPatient();
        arr[a]->patientPointer[b]->setP_data();
        q=arr[a]->patientPointer[b]->d;
        z=arr[a]->patientPointer[b]->t;
        dayCount=q;
        if(dayCount==arr[a]->p)
        {
            cout<<"Invalid Day to take appointment!!!! Try Again";
            system("pause");
            delete arr[a]->patientPointer[b];
            return;
        }
        v=arr[a]->patientPointer[b]->patientID;
        arr[a]->keeper[q-1][z]=v;
        arr[a]->patientPointer[b]->prevDoc.push_back(arr[a]->d_name);
        strcpy(arr[a]->patientPointer[b]->dayName,week[dayCount-1]);
        if(arr[a]->e_shift==1)
        {
            strcpy(arr[a]->patientPointer[b]->timeslotName,timeslot1[z-1]);
        }
        else if(arr[a]->e_shift==2)
        {
            strcpy(arr[a]->patientPointer[b]->timeslotName,timeslot2[z-1]);
        }
        strcpy(arr[a]->patientPointer[b]->currDoc,arr[a]->d_name);
        cout<<"Enter Payment for appointment 1000tk"<<endl;
        while(true)
        {
            cin>>mon;
            if(mon==1000)
             {
                 cout<<"Thank You for your kind Cooperation"<<endl;
                 break;
             }
             else if(mon>1000)
             {
                 cout<<"Returned money :"<<mon-1000<<" tk"<<endl;
                 cout<<"Thank You for your kind Cooperation"<<endl;
                 break;
             }
             else if(mon<1000)
             {
                 cout<<"Requirement of money not met please provide 1000 tk"<<endl;
             }
        }
        arr[a]->income=arr[a]->income+900;
        money=money+100;
        arr[a]->patientPointer[b]->totalPayment+=mon;
        b+=1;
        arr[a]->patient_no=b;
        break;
    case 3:
        cin>>al;
        a=al-1;
        b=arr[a]->patient_no;
        if(b==84)
        {
            cout<<"No more appointments available";
            break;
        }
        arr[a]->patientPointer[b] = new indoorPatient();
        arr[a]->patientPointer[b]->setP_data();
        q=arr[a]->patientPointer[b]->d;
        z=arr[a]->patientPointer[b]->t;
        dayCount=q;
        if(dayCount==arr[a]->p)
        {
            cout<<"Invalid Day to take appointment!!!! Try Again";
            system("pause");
            delete arr[a]->patientPointer[b];
            return;
        }
        v=arr[a]->patientPointer[b]->patientID;
        arr[a]->keeper[q-1][z]=v;
        arr[a]->patientPointer[b]->prevDoc.push_back(arr[a]->d_name);
        strcpy(arr[a]->patientPointer[b]->dayName,week[dayCount-1]);
        if(arr[a]->i_shift==1)
        {
            strcpy(arr[a]->patientPointer[b]->timeslotName,timeslot1[z-1]);
        }
        else if(arr[a]->i_shift==2)
        {
            strcpy(arr[a]->patientPointer[b]->timeslotName,timeslot2[z-1]);
        }
        strcpy(arr[a]->patientPointer[b]->currDoc,arr[a]->d_name);
        cout<<"Enter Payment for appointment 1000tk"<<endl;
        while(true)
        {
             cin>>mon;
              if(mon==1000)
             {
                 cout<<"Thank You for your kind Cooperation"<<endl;
                 break;
             }
             else if(mon>1000)
             {
                 cout<<"Returned money :"<<mon-1000<<" tk"<<endl;
                 cout<<"Thank You for your kind Cooperation"<<endl;
                 break;
             }
             else if(mon<1000)
             {
                 cout<<"Requirement of money not met please provide 1000 tk"<<endl;
             }
        }
        arr[a]->income=arr[a]->income+900;
        money=money+100;
        arr[a]->patientPointer[b]->totalPayment+=mon;
        b+=1;
        arr[a]->patient_no=b;
        break;
    case 4:
        cin>>al;
        a=al-1;
        b=arr[a]->patient_no;
        if(arr[a]->patient_no==108)
        {
            cout<<"No more appointments available";
            break;
        }
        arr[a]->patientPointer[b] = new forSurgeryPatient();
        arr[a]->patientPointer[b]->setP_data();
        q=arr[a]->patientPointer[b]->d;
        z=arr[a]->patientPointer[b]->t;
        dayCount=q;
        if(dayCount==arr[a]->p)
        {
            cout<<"Invalid Day to take appointment!!!! Try Again";
            system("pause");
            delete arr[a]->patientPointer[b];
            return;
        }
        v=arr[a]->patientPointer[b]->patientID;
        arr[a]->keeper[q-1][z]=v;
        arr[a]->patientPointer[b]->prevDoc.push_back(arr[a]->d_name);
        strcpy(arr[a]->patientPointer[b]->dayName,week[dayCount-1]);
        strcpy(arr[a]->patientPointer[b]->timeslotName,timeslot[z-1]);
        strcpy(arr[a]->patientPointer[b]->currDoc,arr[a]->d_name);
        cout<<"Enter Payment for appointment 2000tk"<<endl;
        while(true)
        {
             cin>>mon;
              if(mon==2000)
             {
                 cout<<"Thank You for your kind Cooperation"<<endl;
                 break;
             }
             else if(mon>2000)
             {
                 cout<<"Returned money :"<<mon-2000<<" tk"<<endl;
                 cout<<"Thank You for your kind Cooperation"<<endl;
                 break;
             }
             else if(mon<2000)
             {
                 cout<<"Requirement of money not met please provide 2000 tk"<<endl;
             }
        }
        arr[a]->income=arr[a]->income+1800;
        money=money+200;
        arr[a]->patientPointer[b]->totalPayment+=mon;
        b+=1;
        arr[a]->patient_no=b;
        break;
    default:
        cout << "\nUnknown command";
    }
    pat.push_back(arr[a]->patientPointer[arr[a]->patient_no]);
    cout<<"Patient has taken appointment succesfully"<<endl;
    system("pause");

}
