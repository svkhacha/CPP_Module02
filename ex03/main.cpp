#include "Point.hpp"

int main()
{
    //===========================SOME TESTS===============================
    // //outside
    // Point   a(1, 4), b, c(9);
    // Point   point(2, 7);

    // //inside
    // Point   a(-4, 2), b(6, 6), c(-7.5f, -5.75f);
    // Point   point(-2.5f, 2);

    // //outside
    // Point   a(-4, 2), b(6, 6), c(-7.5f, -5.75f);
    // Point   point(-9, 7);

    //inside
    Point   a(0, 3), b(2), c(6);
    Point   point(3, 1);

	// //outside
	//   Point   a(0, 3), b(2), c(6);
	//   Point   point(0, 3);
    //=====================================================================

    if (bsp(a, b, c, point))
        std::cout << GREEN "Point is inside triangle" RESET<<std::endl;
    else
        std::cout << RED "Point is outside of triangle" RESET <<std::endl;
    return 0;
}
