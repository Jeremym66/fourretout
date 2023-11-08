/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 06:55:26 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/07 08:17:23 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp" 

template <typename T>
Array<T>::Array(void) : data(NULL), _size(0) 
{
    std::cout << "Data constructor" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]), _size(n) 
{
    std::cout << "Data constructor (unsigned int)" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& copy) : _size(copy._size)
{
    data = new T[_size];
    int i = -1;

    std::cout << "Data constructor copy" << std::endl;
	
    while (++i < copy._size)
		this->data[i] = copy.data[i];
}

template <typename T>
Array<T>::~Array(void)
{
    std::cout << "Data destructor" << std::endl;
	delete[] this->data;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other)
{
	if (this == &other)
		return (*this);
	if (this->_size > 0)
		delete[] this->data;

    int i = -1;
	this->_size = other._size;
	this->data = new T[_size];
	while (++i < _size)
		this->data[i] = other.data[i];
	return (*this);
}

template <typename T>
T&			Array<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= _size)
		throw typename Array<T>::Exception::Exception("Index out of bounds");
	return (this->data[idx]);
}

template <typename T>
int			Array<T>::getsize(void) const
{
	return (this->_size);
}

template <typename T>
Array<T>::Exception::Exception(const char *msg) : _msg(msg)
{
}

template <typename T>
Array<T>::Exception::Exception(void)
{
    this->_msg = "error";
}

template <typename T>
std::ostream&	operator<<(std::ostream& out, const Array<T>& array)
{
    int i = -1;
	out << "Array = { ";
	while (++i < array.getsize())
	{
		out << array[i];
		if (i != array.getsize() - 1)
			out << ", ";
	}
	out << " }";
	return (out);
}

