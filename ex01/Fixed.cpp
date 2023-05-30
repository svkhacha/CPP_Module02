#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout<<"Default constructor called"<<std::endl;
    _fixedPointVal = 0;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout<<"Copy constructor called"<<std::endl;
    *this = other; //shallow copy
}

Fixed::Fixed(const int num)
{
    std::cout<<"Int constructor called"<<std::endl;
    this->setRawBits(num << this->_fractional);
}

Fixed::Fixed(const float num)
{
    std::cout<<"Float constructor called"<<std::endl;
    this->setRawBits((int)roundf(num * (1 << this->_fractional)));
}

Fixed::~Fixed(void) {std::cout<<"Destructor called"<<std::endl;}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout<<"Copy assignment operator called"<<std::endl;
    if (this ==  &other)
        return *this;
    this->setRawBits(other.getRawbits());
        return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
    out<<obj.toFloat();
    return out;
}

void    Fixed::setRawBits(int const raw) {this->_fixedPointVal = raw;}

int     Fixed::getRawbits(void) const {return this->_fixedPointVal;}

int     Fixed::toInt(void) const
{
    return (this->_fixedPointVal >> this->_fractional);
}

float   Fixed::toFloat(void) const
{
    return (float)(this->_fixedPointVal) / (1 << this->_fractional);
}