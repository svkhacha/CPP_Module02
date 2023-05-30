#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)) { }

Point::Point(const Point& other) : _x(other._x), _y(other._y) { }

Point& Point::operator=(const Point& other)
{
    if (this == &other)
        return *this;
    (Fixed)this->_x = other.getX();
    (Fixed)this->_y = other.getY();
        return *this;
}

Point::~Point(void) { }

Point::Point(const Fixed x) : _x(x), _y(0) { }

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) { }

Fixed Point::getX(void) const {return this->_x;}
Fixed Point::getY(void) const {return this->_y;}  