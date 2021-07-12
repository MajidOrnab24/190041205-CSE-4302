#include<iostream>
using namespace std;
class Counter
{
private:
    int count;
    int x;
public:
    Counter()
    {
        count=0;
        x=1;
    }
    Counter(int a,int b)
    {
        count=a;
        x=b;
    }

    void setIncrementStep(int step_val)
    {
        if(step_val<0)
        {
                cout<<"Wrong Input"<<endl;
        }
        else
            x=step_val;
    }
    void increment()
    {
        count=count+x;

    }
    int getCount()
    {
        return count;
    }
    int getStepval()
    {
        return x;
    }
   void resetCount()
    {
        count=0;
    }
    Counter operator + (Counter c)
    {
        int m = count +  c.count;
        int n = min(x,c.x);
        return Counter(m,n);
    }
     Counter operator += (Counter c)
    {
        count += c.count;
        x = c.x;

    }
    friend Counter  operator + (int  &c,Counter  &b) ;

    Counter operator ++ ()
    {
       return Counter(++count,x);
    }

    Counter operator ++ (int)
    {
        return Counter(count++,x);
    }
    ~Counter(){}
};
 Counter operator + (int  &c,Counter  &b)
    {

        return Counter(b.count+c,b.x);
    }
int main()
{
    Counter c(8,10),c3;
    int var=100;
    int step_val;
    cin>>step_val;
    c.setIncrementStep(step_val);
    c.increment();
     cout << "\n c=" <<c.getCount();
    cout << "\n c Stepval=" <<c.getStepval();
    c.resetCount();
    cout << "\n c=" <<c.getCount();
    cout << "\n c Stepval=" <<c.getStepval();
    //c.setIncrementStep(step_val);
    c.increment();
        cout << "\n c=" <<c.getCount();
    cout << "\n c Stepval=" <<c.getStepval();
    Counter c2(7,15);
    cout << "\n c2=" <<c2.getCount();
    cout << "\n c2 Stepval=" <<c2.getStepval();
    cout << "\n c3=" <<c3.getCount();
    cout << "\n c3 Stepval=" <<c3.getStepval();
    c3=c2+c;
    cout << "\n c3=" <<c3.getCount();
    cout << "\n c3 Stepval=" <<c3.getStepval();
    c2++;
    cout << "\n c2=" <<c2.getCount();
    cout << "\n c2 Stepval=" <<c2.getStepval();
    ++c2;
    cout << "\n c2=" <<c2.getCount();
    cout << "\n c2 Stepval=" <<c2.getStepval();
    c3=var+c2;
   cout << "\n c3=" << c3.getCount();
   cout << "\n c3 Stepval=" <<c3.getStepval();
   c2+=c;
    cout << "\n c2=" <<c2.getCount();
    cout << "\n c2 Stepval=" <<c2.getStepval();

}

