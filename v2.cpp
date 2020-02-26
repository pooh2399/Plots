#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

static int p = 0;   //static int implementation

class a
{
  char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
    public:
        a();
        ~a();
        a(const a &A1)  //copy constructor
        {
            busn[5]=A1.busn[5];
            driver[10]=A1.driver[10];
            arrival[5]=A1.arrival[5];
            depart[5]=A1.depart[5];
            from[10]=A1.from[10];
            to[10]=A1.to[10];
            seat[8][4][10]=A1.seat[8][4][10];
        }
        void install();
        void allotment();
        void emp();
        void show();
        void avail();
        void position(int i);
        void position(float i);
        void position(char i);

}
bus[10];
//constructor
a::a()
{
    strcpy(busn,"1234");
    strcpy(driver,"abcd");
    strcpy(arrival,"7:00");
    strcpy(depart,"5:00");
    strcpy(from,"Udupi");
    strcpy(to,"Mangalore");
   bus[p].emp();
   p++;
    cout<<"\nConstructor";
}
//destructor
a::~a()
{
    cout<<"\nDestructor";
}

inline void vline(char ch)
{
  for (int i=80;i>0;i--)
  cout<<ch;
}
void a::install()
{
  cout<<"Enter bus no: ";
  cin>>bus[p].busn;
  cout<<"\nEnter Driver's name: ";
  cin>>bus[p].driver;
  cout<<"\nArrival time: ";
  cin>>bus[p].arrival;
  cout<<"\nDeparture: ";
  cin>>bus[p].depart;
  cout<<"\nFrom: \t\t\t";
  cin>>bus[p].from;
  cout<<"\nTo: \t\t\t";
  cin>>bus[p].to;
  bus[p].emp();
 p++;
}
void a::allotment()
{
  int seat;
  char number[5];
  top:
  cout<<"Bus no: ";
  cin>>number;
  int n;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
  while(n<=p)
  {
    cout<<"\nSeat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\nThere are only 32 seats available in this bus.";
    }
    else
    {
    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
      {
        cout<<"Enter passanger's name: ";
        cin>>bus[n].seat[seat/4][(seat%4)-1];
        break;
      }
    else
      cout<<"The seat no. is already reserved.\n";
      }
      }
    if(n>p)
    {
      cout<<"Enter correct bus no.\n";
      goto top;
    }
  }
void a::emp()
{
  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
    {
      strcpy(bus[p].seat[i][j], "Empty");
    }
  }
}

void a::show()
{
  int n;
  char number[5];
  cout<<"Enter bus no: ";
  cin>>number;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
while(n<=p)
{
  vline('*');
  cout<<"\nBus no: \t"<<bus[n].busn
  <<"\t\tDriver: \t"<<bus[n].driver<<"\nArrival time: \t"
  <<bus[n].arrival<<"\t\tDeparture time:"<<bus[n].depart
  <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<
  bus[n].to<<"\n";
  vline('*');
  bus[0].position(n);
  int a=1;
  /*for (int i=0; i<8; i++)
  {
    for(int j=0;j<4;j++)
    {
      a++;
      if(strcmp(bus[n].seat[i][j],"Empty")!=0)
      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
    }
  }*/
  break;
  }
  if(n>p)
    cout<<"Enter correct bus no: ";
}

void a::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[l].seat[i][j];
          p++;
        }
        else
        {
        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];
        }
      }
    }
  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
  }
//function overloading
void a::position(float l)
{
    cout<<"i cannot be a float value"<<endl;
}
//function overloading
void a::position(char l)
{
    cout<<"i cannot be a char value"<<endl;
}
void a::avail()
{
  for(int n=0;n<p;n++)
  {
   vline('*');
    cout<<"\nBus no: \t"<<bus[n].busn<<"\t\tDriver: \t"<<bus[n].driver
    <<"\nArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"
    <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"
    <<bus[n].to<<"\n";
    vline('*');
    cout<<"\n";
    vline('_');
  }
}

class Concatenate {

public:
    char str[100];
    // No Parameter Constructor
    Concatenate() {}

    // Parametrized constructor to initialize class Variable
    Concatenate(char str[])
    {
        strcpy(this->str, str);
    }

    // Overload Operator+ to concatenate the strings
    Concatenate operator+(Concatenate& S2)
    {
        // Object to return the copy of concatenation
        Concatenate S3;

        // Use strcat() to concat two specified string
        strcat(this->str, S2.str);

        // Copy the string to string to be return
        strcpy(S3.str, this->str);

        // return the object
        return S3;
    }
};

int main()
{

int ch;

char str1[] = "OOP ";
char str2[] = "Assignment 1";
    Concatenate a1(str1);
    Concatenate a2(str2);
    Concatenate a3;

    // Call the operator function
    a3 = a1 + a2;
    cout << "\n\nConcatenation: " << a3.str<<"\n\n";

do
{
    a();
    //system("cls");
  cout<<"\n\n\n\n\n";
  cout<<"\t\t\t1.Install\n\t\t\t"
  <<"2.Reservation\n\t\t\t"
  <<"3.Show\n\t\t\t"
  <<"4.Buses Available. \n\t\t\t"
  <<"5.Exit";
  cout<<"\n\t\t\tEnter your choice:-> ";
  cin>>ch;
  switch(ch)
  {
    case 1:  bus[p].install();
      break;
    case 2:  bus[p].allotment();
      break;
    case 3:  bus[0].show();
      break;
    case 4:  bus[0].avail();
      break;
    case 5:  exit(0);
  }
}while(ch!='4');
return 0;
}
