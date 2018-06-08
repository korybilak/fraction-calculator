#include <iostream>
#include "fraction.h"
#include <string>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;

//Constructor
Fraction :: Fraction()
{
//default variables (den must be = 1 cant divide by 0, so I set everything to 1)
          num = 0;
          den = 1;
          whole = 0;
          sign = '0';
}

//sets
void Fraction :: setnum(const int num)
{
         num == num;
         
}

void Fraction :: setden(const int den)
{

         den == den;
}

void Fraction :: setwhole(const int whole)
{

         whole == whole;
}

void Fraction :: setsign( const char sign)
{

         sign == sign;

}

//gets
int Fraction :: getnum(void) const
{
      return num;
}

int Fraction :: getden(void) const
{
      return den;
}
int Fraction :: getwhole(void) const
{
      return whole;
}
char Fraction :: getsign(void) const
{
      return sign;
}
// simplifies and returns whole numbers
Fraction reduce(Fraction& f3)
{
         if(f3.getnum() == 0)
         {
         f3.den = 0;
         }
do
         {
         if( f3.num > 0 && f3.num %2 == 0 && f3.den  %2 ==0)
         {
         f3.num = f3.num/2;
         f3.den = f3.den/2;
         }
}while(f3.den%2 == 0 && f3.num%2== 0 && f3.num > 0);
do
         {
         if (f3.num >= f3.den && f3.num >0)
         {
         f3.whole = f3.whole + 1;
         f3.num = f3.num - f3.den;
         }
}while (f3.num>= f3.den && f3.num > 0);
}

//converts the mixed numbers into fraction, for comparing and math later (made code smaller by doing this).
Fraction convert(Fraction& f1)
{
do
{
         if(f1.whole > 0)
         {
         f1.num =f1.num +  f1.den;
         if(f1.getden() == 0)
         f1.den = 1;
         f1.whole = f1.whole - 1;
         }
}while(f1.whole > 0);
}
//resets the fractions
Fraction reset(Fraction& f3)
{
         f3.whole = 0;
         f3.num = 0;
         f3.den = 1;
         f3.sign = '+';
}
//adds 2 fractions and returns result.
Fraction operator+(const Fraction& f1, const Fraction& f2)
{
 Fraction f3;
                 if(f1.getsign() == '-' && f2.getsign() != '-' || f2.getsign() == '-' && f1.getsign() != '-')
                 {
                 f3.num = abs(f1.getnum() * f2.getden() - f1.getden() * f2.getnum());
                 f3.den = f1.getden() * f2.getden();
                 }
                 else
                 {   
                  f3.num = f1.getnum() * f2.getden() + f1.getden() * f2.getnum();
                  f3.den = f1.getden() * f2.getden();	
                  }
                  if((f1.getsign() == '-' && abs(f1.getnum()) >= f2.getnum() &&  f1.getden() <= f2.getden() && f2.getsign() != '-') || (f2.getsign() == '-' && f1.getnum() <= abs(f2.getnum())  && f2.getden() <= f1.getden() && f1.getsign() != '-')|| (f1.getsign() == '-' && f2.getsign() == '-'))
                  {
                  f3.sign = '-';
                  }
 return f3;
}
//subtracts 2 fractions and returns result
Fraction operator-(const Fraction& f1, const Fraction& f2)
{
 Fraction f3;
          if(f2.getsign() == '-' && f1.getsign() != '-' || f1.getsign() == '-' && f2.getsign() != '-')
          {
          f3.num = f1.getnum() * f2.getden() + f1.getden() * f2.getnum();
          f3.den = f1.getden() * f2.getden();
          }
          else
          {
          f3.num = abs(f1.getnum() * f2.getden() - f1.getden() * f2.getnum());
          f3.den = f1.getden() * f2.getden();
          }
          if(f1.getsign() == '-' &&  f2.getsign() != '-' || f1.getnum() <= f2.getnum() && f2.getsign() != '-' && f1.getsign() != '-')
          {
          f3.sign = '-';
          }
 return f3;
}

//multiplies 2 fractions and returns result
Fraction operator*(const Fraction& f1, const Fraction& f2)
{
 Fraction f3;
 f3.num = f1.getnum() * f2.getnum();
 f3.den = f1.getden() * f2.getden();
       if(f1.getsign() == '-' && f2.getsign() != '-' || f2.getsign() == '-' && f1.getsign() != '-')
       {
       f3.sign = '-';
       }
 return f3;
}
//divdes 2 fractions and returns result
Fraction operator/(const Fraction& f1, const Fraction& f2)
{
 Fraction f3;
 f3.num = f1.getnum() * f2.getden();
 f3.den = f1.getden() * f2.getnum();
       if(f1.getsign() == '-' && f2.getsign() != '-' || f2.getsign() == '-' && f1.getsign() != '-')
       {
       f3.sign = '-';
       }
 return f3;
}

// checks to see if the first fraction is > than the second
bool operator>(const Fraction& f1, const Fraction& f2)
{
 bool flag = false;
  float temp1 = static_cast<float>(f1.getnum())/(f1.getden());
  float temp2 = static_cast<float> (f2.getnum())/(f2.getden());
  if (temp1 > temp2 && f1.getsign() == f2.getsign() && f1.getsign() != '-' || temp1 < temp2 && f1.getsign() == f2.getsign() && f1.getsign() == '-' || f1.getsign() != f2.getsign() && f2.getsign() == '-')
  flag = true;
  return flag;
}
// checks to see if fraction 1 is < fraction 2
 bool operator<(const Fraction& f1, const Fraction& f2)
{
 bool flag = false;
  float temp1 = static_cast<float>(f1.getnum())/(f1.getden());
  float temp2 = static_cast<float> (f2.getnum())/(f2.getden());
  if (temp1 < temp2 && f1.getsign() == f2.getsign() && f1.getsign() != '-' || temp1 > temp2 && f1.getsign() == f2.getsign() && f1.getsign() == '-' || f1.getsign() != f2.getsign() && f1.getsign() == '-')
  flag = true;
  return flag;
}
// checks to see if the absolute value of fraction 1 is = to fraction 2
bool operator==(const Fraction& f1, const Fraction& f2)
{
 bool flag = false;
  float temp1 = static_cast<float>(f1.getnum())/(f1.getden());
  float temp2 = static_cast<float> (f2.getnum())/(f2.getden());
  float temp3 = temp1-temp2;
  if (abs(temp3) <.00001)
  
  flag = true;
  return flag;
}
//checks to see if fraction 1 is > or = fraction 2
bool operator>=(const Fraction& f1, const Fraction& f2)
{
 bool flag = false;
  float temp1 = static_cast<float>(f1.getnum())/(f1.getden());
  float temp2 = static_cast<float> (f2.getnum())/(f2.getden());
  if( temp1 > temp2 && f1.getsign() == f2.getsign() && f1.getsign() != '-'|| temp1 < temp2 && f1.getsign() == f2.getsign() && f1.getsign() == '-' || f1.getsign() != f2.getsign() && f1.getsign() != '-' || temp1 == temp2 && f1.getsign() == f2.getsign())
  flag = true;
  return flag;
}
//checks to see if fraction 1 is < or = fraction 2
bool operator<=( const Fraction& f1, const Fraction& f2)
{
 bool flag = false;
  float temp1 = static_cast<float>(f1.getnum())/(f1.getden());
  float temp2 = static_cast<float> (f2.getnum())/(f2.getden());
  if( temp1 < temp2 && f1.getsign() == f2.getsign() && f1.getsign() != '-' || temp1 > temp2 && f1.getsign() == f2.getsign() && f1.getsign() == '-' || temp1 == temp2 && f1.getsign() ==  f2.getsign() || f1.getsign() != f2.getsign() && f1.getsign() == '-')
  flag = true;
  return flag;
}
// checks to see if the fractions are not = to each other
bool operator!=(const Fraction& f1, const Fraction& f2)
{
 bool flag = false;
  float temp1 = static_cast<float>(f1.getnum())/(f1.getden());
  float temp2 = static_cast<float> (f2.getnum())/(f2.getden());
  float temp3 = temp1-temp2;
  if (abs(temp3) >.00001)
  flag = true;
  return flag;
}         
//depending on what is typed, will display the correct result
ostream& operator<< (ostream& outp, const Fraction& f1) 
{
 if(f1.whole != 0 && f1.num != 0 && f1.sign == '-')
 outp << f1.sign << f1.whole << " " << f1.num << '/' << f1.den; 
 else if(f1.whole != 0 && f1.num != 0 && f1.sign != '-')
 outp << f1.whole << " " << f1.num << '/' << f1.den;
 else if(f1.num != 0 && f1.sign == '-')
 outp << f1.sign << f1.num << '/' << f1.den;
 else if( f1.whole == 0 && f1.sign != '-' && f1.num != 0)
 outp << f1.num << '/' << f1.den;
 else if( f1.num == 0 && f1.whole != 0 && f1.sign == '-')
 outp << f1.sign << f1.whole;
 else if(f1.num == 0 &&f1.whole == 0)
 outp << f1.whole;
 else if( f1.num == f1.den && f1.sign == '-')
 outp << f1.sign << f1.whole;
 else if(f1.num == f1.den && f1.sign != '-')
 outp << f1.whole;
 else
 outp << f1.whole;
 return outp;
}
//overloads the cin function, for whole numbers, fractions, mixed numbers, with or without negatives.
istream& operator>> (istream& inp, Fraction& f1)
{
string check1,check2,check3, substring;
string temp;

char x = '-';
char x2 = ' ';
char x3 = '/';
int found = 0;
int found2 = 0;
int found3 = 0;
int flag = 0;
int i = 0;

do{
reset(f1); //resets f1
  flag = 0;
  found = 0;
  found2 = 0;
  found3 = 0;

  getline(inp, temp);
    for (i = 0; i < temp.size() ; i++)
    {

    if(temp[i] == '/')
    found3 = i+1;
    if(temp[i] == '-')
    found = i+1;
    if(temp[i] == ' ') 
    found2 = i+1;
    }
      if(found > found3+1 && found3 != 0||  found != 1 && found != 0 || found > found3 && found3 != 0 || found2 > found3 && found3 != 0|| found+1 == found3  || found2+1 == found3 || found3 == temp.size() || found == temp.size() || found2 == temp.size() || found2+1 > found3 && found3 != 0 || found2 == 1 || found2+1 == found3 || temp.find_first_of('-') < temp.find_last_of('-') || temp.find_first_of(' ') < temp.find_last_of(' ') || temp.find_first_of('/') < temp.find_last_of('/') || temp.find_first_not_of("0123456789- /") != -1 || temp.size() == 0 || found == temp.size() || found2 != 0 && found3 == 0)
      {
      cout << "You typed in something invalid. Please try again.\n";
      flag = 1;
      }
      else if (found == 0 && found2 == 0 && found3 == 0 )
      {
      substring = temp.substr(0,temp.size());
      f1.whole = atoi(substring.c_str());
      }
      else if (found == 0 && found2 == 0 && found3 != 0)
      {
      substring = temp.substr(0, found3);
      f1.num = atoi(substring.c_str());
      substring = temp.substr(found3, temp.size());
      f1.den = atoi(substring.c_str());
      }
      else if(found2 == 0 && found3 == 0 && found != 0)
      {
      substring = temp.substr(0, found);
      f1.sign = '-';
      substring = temp.substr(found, temp.size());
      f1.whole = atoi(substring.c_str());
      }
      else if(found != 0 && found3 != 0 && found2 == 0)
      {
      substring = temp.substr(found,found+1);
      f1.sign = '-';
              if( found < found3)
              {
              substring = temp.substr(found, found3);
              f1.num = atoi(substring.c_str());
              substring = temp.substr(found3, temp.size());
              f1.den = atoi(substring.c_str());
              }
      }
      else if(found == 0 && found2 != 0 && found3 != 0)
      {
      substring = temp.substr(0,found2);
      f1.whole = atoi(substring.c_str());
      substring = temp.substr(found2,found3);
      f1.num = atoi(substring.c_str());
      substring = temp.substr(found3,temp.size());
      f1.den = atoi(substring.c_str());
      }
      else if(found != 0 && found2 != 0 && found3 == 0)
      {
      substring = temp.substr(found,found+1);
      f1.sign = '-';
              if(found2 > found)
              {
              substring = temp.substr(found, found2);
              f1.whole = atoi(substring.c_str());
              }
      }
      else if(found != 0 && found3 != 0 && found2 != 0)
      {
              if (found < found3)
              {
              f1.sign = '-';
              substring = temp.substr(found,found2);
              f1.whole = atoi(substring.c_str());          
              substring = temp.substr(found2, found3);
              f1.num = atoi(substring.c_str());
              substring = temp.substr(found3,temp.size());
              f1.den = atoi(substring.c_str());
              }
      }
  if( f1.den == 0)
  {
  cout << "Error cannot divide by 0\n";
  flag = 1;
  }
}while(flag == 1);
return inp;
}
