#include<iostream>
using namespace std;
class Counter
{
private:
    int count=0,x;
public:
    void setIncrementStep(int step_val)
    {
        x=step_val;
    }
    void increment()
    {
        count=count+x;

    }
    int getCount()
    {
        cout<<count<<endl;
    }
   void resetCount()
    {
        count=0;
    }
};
int main()
{
    Counter c;
    int i;
    int step_val;
    while(1)
  {
      cin>>i;
      switch(i)
      {
      case 1:
        cin>>step_val;
            c.setIncrementStep(step_val);
        break;
      case 2:
       c.increment();
        break;
      case 3:
        c.resetCount();
        break;
        case 4:
        c.getCount();
        break;
      case 0:
          exit(0);
      }

  }

}
