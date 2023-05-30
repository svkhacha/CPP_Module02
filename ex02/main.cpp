#include "Fixed.hpp"

int main(void)
{
	try
	{	
		Fixed       a;
    	Fixed const b(Fixed(5.05f) * Fixed(2));
    	Fixed       c;
    
		std::cout << a << std::endl;
    	std::cout << ++a << std::endl;
    	std::cout << a << std::endl;
    	std::cout << a++ << std::endl;
    	std::cout << a << std::endl;

    	std::cout << b << std::endl;

    	std::cout << Fixed::max(a, b) << std::endl;
		//std::cout<<a / 0<<std::endl;
	}
	catch(const std::logic_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
