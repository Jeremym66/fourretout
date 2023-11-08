/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:22:16 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/08 14:41:32 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _size(0), _size_max(N)
{
    std::cout << "constructor Span" << std::endl;
}

Span::~Span() 
{
    std::cout << "destructor Span" << std::endl << std::endl;
}

Span::Span(const Span & src)
{
	this->_vec = src._vec;
	this->_size_max = src._size_max;
	this->_size = src._size;
}

Span & Span::operator=(const Span & rhs)
{
	if (this != &rhs)
	{
		this->_vec = rhs._vec;
		this->_size_max = rhs._size_max;
		this->_size = rhs._size;
	}
    return *this;
}

void	Span::addNumber(int nb)
{
	this->_size++;
	if (this->_size > this->_size_max)
		throw Exception("Span is full !");
	this->_vec.push_back(nb);
	std::cout << "Number : " << nb << " added to list." << std::endl;
}

void	Span::addManyNumbers(int n)
{
	if (this->_size + n > this->_size_max) 
	{
		std::cout << "Can't add " << n << " elements to the array, size_max(" << this->_size_max << ") will be reached" << std::endl;
		return;
	}
	int nb = 0;
	
	srand(time(NULL));
	for (unsigned int i = 0; i != n; i++)
	{
		if (i % 2)
			nb = rand() % 100000;
		else
			nb = (rand() % 100000) * (-1);
		this->addNumber(nb);
		// std::cout << this->_size << " / " << this->_size_max << " : " << nb << std::endl;
	}
}

unsigned int     Span::shortestSpan()
{
	if (this->_size < 2)
		throw Exception("Not enough number in the list");

	unsigned int	shortest = 4294967295;	
	std::vector<int> sorted = _vec;

	std::sort(sorted.begin(), sorted.end());
	if (this->_size == 2)
	{
		shortest = sorted.back() - sorted.front();
		return (shortest);
	}
	std::vector<int>::const_iterator	it = sorted.begin();
	std::vector<int>::const_iterator	ite = sorted.end();
	while (it != ite)
    {
		if (shortest > abs(*it - *(++it)))
		{
			it--;
			shortest = abs(*it - *(++it));
		}
	}
	return (shortest);
}

unsigned int     Span::longestSpan()
{
	if (this->_size < 2)
		throw Exception("Not enough number in the list");
	std::vector<int> sorted = _vec;
	std::sort(sorted.begin(), sorted.end());
	unsigned int longest = sorted.back() - sorted.front();
	return (longest);
}
