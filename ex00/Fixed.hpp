#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed(void);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed(void);
        
        void    setRawBits(int const raw);
        int     getRawBits(void) const;
    
     private:
        int _fixedPointVal;
        static const int _fractional = 8;
};

#endif