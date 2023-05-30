#include "Point.hpp"

static void barycentric_coordinates(Point a, Point b, Point c, Point point, Fixed& alpha, Fixed& betta, Fixed& gamma)
{
    //using cross product to calculate the area of the triangle abc
    Fixed denominator = (b.getY() - c.getY()) * (a.getX() - b.getX()) + 
        (c.getX() - b.getX()) * (a.getY() - c.getY());
    //calculating the barycentric coordinates of point
    alpha = ((b.getY() - c.getY()) * (point.getX() - c.getX()) + 
        (c.getX() - b.getX()) * (point.getY()- c.getY())) / denominator;
    betta = ((c.getY() - a.getY()) * (point.getX() - c.getX()) +
        (a.getX() - c.getX()) * (point.getY() - c.getY())) / denominator;
    gamma = Fixed(1.0f) - alpha - betta;
}

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed alpha, betta, gamma, null(0.0f);
    barycentric_coordinates(a, b, c, point, alpha, betta, gamma);
    if (alpha > null && betta > null && gamma > null)
        return true;
    return false;
}
