#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout<<"Default constructor called"<<std::endl;
    _fixedPointVal = 0;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout<<"Copy constructor called"<<std::endl;
    this->_fixedPointVal = other.getRawBits(); // deep copy
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout<<"Copy assignment operator called"<<std::endl;
    if (this == &other)
        return *this;
    this->setRawBits(other.getRawBits());
        return *this;
}

Fixed::~Fixed(void) {std::cout<<"Destructor called"<<std::endl;}

void    Fixed::setRawBits(int const raw) {this->_fixedPointVal = raw;}

int Fixed::getRawBits(void) const
{
    std::cout<<"getRawBits member function called"<<std::endl;
    return this->_fixedPointVal;
}