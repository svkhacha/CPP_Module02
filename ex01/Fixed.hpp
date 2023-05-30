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
        Fixed& operator=(const Fixed& other);
        ~Fixed(void);

        void    setRawBits(int const raw);
        int     getRawbits(void) const;
        int     toInt(void) const;
        float   toFloat(void) const;

    private:
        int _fixedPointVal;
        static const int _fractional = 8;
};

 std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif