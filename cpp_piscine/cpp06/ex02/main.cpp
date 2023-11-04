/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 07:09:39 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/03 07:28:55 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.class.hpp"
#include "A.class.hpp"
#include "B.class.hpp"
#include "C.class.hpp"

void	identify(Base * p) 
{
    std::cout << "*****************************" << std::endl;
    std::cout << "Identify the pointer's type :" << std::endl;
    std::cout << "*****************************" << std::endl;
    if (dynamic_cast<A *>(p))
		std::cout << "The pointer is a A type." << std::endl;
    else
        std::cout << "The pointer is not a A type." << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "The pointer is a B type." << std::endl;
	else
        std::cout << "The pointer is not a B type." << std::endl;
    if (dynamic_cast<C *>(p))
		std::cout << "The pointer is a C type." << std::endl;
    else
        std::cout << "The pointer is not a C type." << std::endl;
}

void	identify(Base & p) 
{
    std::cout << "*****************************" << std::endl;
    std::cout << "Identify the reference's type :" << std::endl;
    std::cout << "*****************************" << std::endl;

	try 
    {
		A &	a = dynamic_cast<A &>(p);
		(void) a;
		std::cout << "The pointer is a A type." << std::endl;
	}
	catch(const std::exception& e) 
    {
        std::cout << "The pointer is not a A type." << std::endl;
    }
	try 
    {
		B &	b = dynamic_cast<B &>(p);
		(void) b;
		std::cout << "The pointer is a B type." << std::endl;
	}
	catch(const std::exception& e)
    {
        std::cout << "The pointer is not a B type." << std::endl;
    }
	try
    {
		C &	c = dynamic_cast<C &>(p);
		(void) c;
		std::cout << "The pointer is a C type." << std::endl;
	}
	catch(const std::exception& e)
    {
        std::cout << "The pointer is not a C type." << std::endl;
    }
}

Base *  generate(void)
{
	Base *	ptr;
	srand(time(NULL));
	
	int n = rand() % 3;
	
	if (n == 0)
    {
		ptr = new A;
		std::cout << "A constructor" << std::endl;
	}
	else if (n == 1)
    {
		ptr = new B;
		std::cout << "B constructor" << std::endl;
	}
	else if (n == 2)
    {
		ptr = new C;
		std::cout << "C constructor" << std::endl;
	}
	return ptr;
}

int	main()
{
	Base *	ptr = generate();

	identify(ptr);
	identify(*ptr);

	delete ptr;

	return 0;
}