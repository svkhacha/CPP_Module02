#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed(void);
        Fixed(const Fixed& other);
        Fixed(const int num);
        Fixed(const float num);
        ~Fixed(void);
        Fixed& operator=(const Fixed& other);

        void    setRawBits(int const raw);
        int     getRawBits(void) const;
        int     toInt(void) const;
        float   toFloat(void) const;

        //comparision operators
        bool    operator==(const Fixed& rhs) const;
        bool    operator<(const Fixed& rhs) const;
        bool    operator>(const Fixed& rhs) const;
        bool    operator<=(const Fixed& rhs) const;
        bool    operator>=(const Fixed& rhs) const;
        bool    operator!=(const Fixed& rhs) const;

        //arithmetic operators
        Fixed   operator+(const Fixed& rhs) const;
        Fixed   operator-(const Fixed& rhs) const;
        Fixed   operator*(const Fixed& rhs) const;
        Fixed   operator/(const Fixed& rhs) const;

        //increment / decrement operators
        Fixed&  operator++(void); // prefix
        Fixed   operator++(int); //postfix
        Fixed&  operator--(void); //prefix
        Fixed   operator--(int); //postfix;

        //overloaded member functions
        static  Fixed&  min(Fixed& a, Fixed& b);
        static  const Fixed&  min(const Fixed& a, const Fixed& b);
        static  Fixed&  max(Fixed& a, Fixed& b);
        static  const Fixed&  max(const Fixed& a, const Fixed& b);
        
    private:
        int _fixedPointVal;
        static const int _fractional = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif