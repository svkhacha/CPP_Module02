#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define RESET   "\x1b[0m"

class Point
{
    public:
        Point(void);
        Point(const Point& other);
        Point& operator=(const Point& other);
        ~Point(void);
        
        Point(const Fixed x, const Fixed y);
        Point(const Fixed x);
        Fixed getX(void) const;
        Fixed getY(void) const;
    
    private:
        Fixed const _x;
        Fixed const _y;
};

bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif