#include "Fixed.hpp"

Fixed::Fixed(void) {_fixedPointVal = 0;}

Fixed::Fixed(const Fixed& other) {*this = other;}

Fixed::Fixed(const int num) {this->setRawBits(num << this->_fractional);}

Fixed::Fixed(const float num) {this->setRawBits((int)roundf(num * (1 << this->_fractional)));}

Fixed::~Fixed(void) { }

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this == &other)
        return *this;
    this->setRawBits(other.getRawBits());
        return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
    out<<obj.toFloat();
    return out;
}

void    Fixed::setRawBits(int const raw) {this->_fixedPointVal = raw;}
int     Fixed::getRawBits(void) const {return this->_fixedPointVal;}

int     Fixed::toInt(void) const
{
    return (this->_fixedPointVal >> this->_fractional);
}

float   Fixed::toFloat(void) const
{
    return static_cast<float>(this->_fixedPointVal) / (1 << this->_fractional);
}

//comparision operators

bool    Fixed::operator==(const Fixed& rhs) const
{
    return (this->_fixedPointVal == rhs._fixedPointVal);
}

bool    Fixed::operator<(const Fixed& rhs) const
{
    return (this->_fixedPointVal < rhs._fixedPointVal);
}

bool    Fixed::operator>(const Fixed& rhs) const
{
    return (this->_fixedPointVal > rhs._fixedPointVal);
}

bool    Fixed::operator<=(const Fixed& rhs) const
{
    return (this->_fixedPointVal <= rhs._fixedPointVal);
}

bool    Fixed::operator>=(const Fixed& rhs) const
{
    return (this->_fixedPointVal >= rhs._fixedPointVal);
}

bool    Fixed::operator!=(const Fixed& rhs) const
{
    return (this->_fixedPointVal != rhs._fixedPointVal);
}

//arithmetic operators

Fixed   Fixed::operator+(const Fixed& rhs) const
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed   Fixed::operator-(const Fixed& rhs) const
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed   Fixed::operator*(const Fixed& rhs) const
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed   Fixed::operator/(const Fixed& rhs) const
{
    if (Fixed(rhs.toFloat()) == 0)
		throw (std::logic_error("division by zero"));
    return Fixed(this->toFloat() / rhs.toFloat());
}

//increment / decrement operators

Fixed&  Fixed::operator++(void) //prefix
{
    this->_fixedPointVal += 1;
    return *this;
}

Fixed   Fixed::operator++(int) //postfix
{
    Fixed tmp(*this);
    this->_fixedPointVal += 1;
    return tmp;
}

Fixed&  Fixed::operator--(void) //prefix
{
    this->_fixedPointVal -= 1;
    return *this;
}

Fixed   Fixed::operator--(int) //postfix
{
    Fixed tmp(*this);
    this->_fixedPointVal -= 1;
    return tmp;
}

//overloaded member functions
Fixed&  Fixed::min(Fixed& a, Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    return  b;
}
const Fixed&    Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

Fixed&  Fixed::max(Fixed& a, Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

const Fixed&    Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}
