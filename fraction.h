/*
*Fraction()
*Descriptor: Initializes class Fraction
*preconditions: none
*postconditions: sets the private data
*setnum(const int)
*Descriptor: sets the numerator
*preconditions: must be an int
*postconditions: changes num from its default value
*setden(const int)
*Descriptor: sets the denominator
*preconditions: must be int
*postconditions: changes den from its default value
*setwhole(const int)
*Descriptor: sets the whole number
*preconditions: must be an int
*setsign(const char)
*Descriptor: sets the sign for a fraction
*preconditions: must be -
*postconditions:changes the sign from its default value
*postconditions: changes whole from its default value
*getnum(void)
*Descriptor: gets the numerator
*preconditions: see setnum
*postconditions: gets the numerator for comparisons or for cout
*getden(void)
*Descriptor: gets the denominator
*preconditions: see setden
*postconditions: gets the denominator for comparisons or for cout
*getwhole(void)
*Descriptor: gets the whole number
*preconditions: see setwhole
*postconditions: gets the whole number for comparisons or for cout
*getsign(void):
*Descriptor: gets the sign
*preconditions: see setsign
*postconditions: gets the sign for comparisons or cout
*convert(Fraction&)
*Descriptor: converts the fraction
*preconditions: num, den, whole must be int or 0
*postconditions: converts the mixed number into fraction, or does nothing if its fraction only
*reduce(Fraction&)
*Descriptor: reduces the fraction
*preconditions: num, den must be int or 0
*postconditions: converts the mixed number back into a fraction, and reduces the fraction 
*reset(fraction&)
*Descriptor: resets the fractions
*preconditions: none
*postconditions: makes the fractions their default #
*isteram operator>>(std:: istream&, Fraction&)
*Descriptor: changes the istream to read fractions
*preconditions: must be a whole #, fraction, mixed number, with or without negatives (which can be placed -whole frac/frac or whole -frac/frac or whole frac/-frac etc
*postconditions: will set whole#, num, den, and sign
*ostream operator<<(std::ostream, Fraction&)
*Descriptor: outputs the appropriate fraction type
*preconditions: has to be a whole, mixed, or fraction with or without sign,
*postconditions: displays correct output
*operator+(const Fraction&, const Fraction&)
*Descriptor: adds 2 fractions
*preconditions: num must be int, den must be int, sign must be - or nothing
*postconditions: adds the fractions appropriately depending on if they are negative or not
*operator-(const Fraction&, const Fraction&)
*Descriptor: subtracts 2 fractions
*preconditions: num must be int, den must be int, sign must be - or nothing
*postconditions: subtracts the fractions appropriately according to their signs
*operator*(const Fraction&, const Fraction&)
*Descriptor: mutliplies 2 fractions
*preconditions: num must be int, den must be int, sign must be - or nothing
*postconditions:multiplies 2 fractions appropriately according to their sign
*operator/(const Fraction&, const Fraction&)
*Descriptor divides 2 fractions
*preconditions: num and den must be int, sign must be - or nothing
*postconditions: divides 2 fractions appropriately according to  their sign
*operator<(const Fraction&)
*Descriptor: check if f1<f2
*preconditions: num and den must be int, sign must be - or nothing
*postconditions: checks f1 < f2 appropriately according to its sign
*operator>(const Fraction&, const Fraction&)
*Descriptor: check if f1>f2
*preconditions: num and den must be int, sign must be - or nothing
*postconditions: checks f1 > f2 appropriately according to its sign
*operator==(const Fraction&, const Fraction&)
*Descriptor: check if f1==f2
*preconditions: num and den must be int, sign must be - or nothing
*postconditions: checks f1 == f2 appropriately according to its sign
*operator<=(const Fraction&, const Fraction&)
*Descriptor: check if f1<=f2
*preconditions: num and den must be int, sign must be - or nothing
*postconditions: checks f1 <= f2 appropriately according to its sign
*operator>=(const Fraction&, const Fraction&)
*Descriptor: check if f1>=f2
*preconditions: num and den must be int, sign must be - or nothing
*postconditions: checks f1 >= f2 appropriately according to its sign
*operator!=(const Fraction&, const Fraction&)
*Descriptor: check if f1!=f2
*preconditions: num and den must be int, sign must be - or nothing
*postconditions: checks f1!=f2 appropriately according to its sign
*/

#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
class Fraction{

public:
      
    Fraction(); //Constructor
    //sets
    void setnum(const int);
    void setden(const int);
    void setwhole(const int);
    void setsign( const char);
    //gets
    int getnum(void) const;
    int getden(void) const;
    int getwhole(void)const;
    char getsign(void) const;
    
    //other
    friend Fraction convert(Fraction&); // converts wholes into fractions
    friend Fraction reduce(Fraction&); // reduces fractions
    friend Fraction reset(Fraction&);
    friend std::istream& operator>>(std::istream&, Fraction&); // input function
    friend std::ostream& operator<<(std::ostream&, const Fraction&); // output function
    // Mathmatical Operators
    friend Fraction operator+(const Fraction&, const Fraction&);
    friend Fraction operator-(const Fraction&, const Fraction&);
    friend Fraction operator*(const Fraction&, const Fraction&);
    friend Fraction operator/(const Fraction&, const Fraction&);
    
    //Relational operators
    friend bool operator>(const Fraction&, const Fraction&);
    friend bool operator<(const Fraction&, const Fraction&);
    friend bool operator==(const Fraction&, const Fraction&);
    friend bool operator!=( const Fraction&, const Fraction&);
    friend bool operator>=(const Fraction&, const Fraction&);
    friend bool operator<=( const Fraction&, const Fraction&);
       
private:
    //private variables
    int num;
    int den;
    int whole;
    char sign;
};
#endif
