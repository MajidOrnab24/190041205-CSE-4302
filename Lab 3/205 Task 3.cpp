#include<iostream>
using namespace std;
class BankAccount
{
private:
    string customer_name;
    string type_of_account;
    int account_number=0;
    int balance=0;
    int withdraw;
public:
    void customerDetails_(string s,int a)
    {
        customer_name=s;
        account_number=a;
    }
    void accountType(string s2)
    {
        type_of_account=s2;
    }
    void Balance()
    {
        cout<<balance<<endl;
    }
    void Deposit(int d)
    {
        balance=balance+d;
        cout<<"Final balance :"<<balance<<endl;
    }
    void Withdraw(int w)
    {
        if (balance>=w)
        {
           balance=balance-w;
            cout<<"Amount Withdrawn: "<<w<<"\n"
            <<"Final Balance: "<<balance<<endl;
        }
        else
            cout<<"withdraw error"<<endl;

    }
    void display()
    {
        cout<<"Customer name: "<<customer_name<<"\n"
        <<"Account_number: "<<account_number<<"\n"<<
        "Type of Account: "<<type_of_account<<"\n"
        <<"Balance: "<<balance <<endl;
    }
};
int main()
{
     BankAccount customer;
    int i,d,d1,w;
    while(1)
  {
      cin>>i;
      string s,s1;
      int n;
      switch(i)
      {
      case 1:
        cin>>s>>d;
        customer.customerDetails_(s,d);
        break;
      case 2:
          cin>>s1;
       customer.accountType(s1);
        break;
      case 3:
        customer.Balance();
        break;
        case 4:
            cin>>d1;
        customer.Deposit(d1);
        break;
      case 5:
          cin>>w;
        customer.Withdraw(w);
        break;
      case 6:
        customer.display();
        break;
      }
  }

}

