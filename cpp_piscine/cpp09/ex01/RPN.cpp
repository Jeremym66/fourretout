/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:39:30 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/13 14:53:37 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	// std::cout << "constructor RPN" << std::endl;
}

RPN::~RPN() 
{
    // std::cout << "destructor RPN" << std::endl << std::endl;
}

RPN::RPN(const RPN & src)
{
	*this = src;
	// std::cout << "constructor RPN copy" << std::endl;
}

RPN & RPN::operator=(const RPN & rhs)
{
	if (this != &rhs)
	{
		this->_stack = rhs._stack;
	}
    return *this;
}

void    RPN::fillStack(char *str)
{
	int i = 5;
	char arg2;
	char arg1;
	int	result;
	if (str[0] < 58 && str[0] >= 48 && str[2] < 58 && str[2] >= 48 && str[1] == ' ' && str[3] == ' ')
	{
		arg2 = str[0];
		arg1 = str[2];
		if (str[4] == '+')
			result = (arg2 - 48) + (arg1 - 48);
		else if (str[4] == '-')
			result = (arg2 - 48) - (arg1 - 48);
		else if (str[4] == '*')
			result = (arg2 - 48) * (arg1 - 48);
		else if (str[4] == '/')
			result = (arg2 - 48) / (arg1 - 48);
		this->_stack.push(result + 48);
	}
	else
		throw Exception("Error argument");
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		if (str[i] < 58 && str[i] >= 48)
		{
			if (str[i + 1] == 0)
				throw Exception("Error argument : need Sign");
			if (str[i + 1] == ' ')
			{
				this->_stack.push(str[i]);
				i += 2;
			}
			else
				throw Exception("Error argument : number too high");
			if (str[i] == '*' || str[i] == '/' || str[i] == '-' || str[i] == '+')
			{
				arg2 = _stack.top();
				_stack.pop();
				arg1 = _stack.top();
				_stack.pop();
				if (str[i] == '+')
					result = (arg1 - 48) + (arg2 - 48);
				else if (str[i] == '-')
					result = (arg1 - 48) - (arg2 - 48);
				else if (str[i] == '*')
					result = (arg1 - 48) * (arg2 - 48);
				else if (str[i] == '/')
					result = (arg1 - 48) / (arg2 - 48);
				i++;
				this->_stack.push(result + 48);
			}
			else
				throw Exception("Error");
		}
		else
				throw Exception("Error argument : need number <0 - 9>");
	}
	std::cout << result << " is result final" << std::endl;
}

// void    RPN::fillStack(char *str)
// {
// 	int i = 0;
// 	char arg1;	
// 	char arg2;
// 	int	result;

	
// 	while (str[i])
// 	{
// 		std::cout << "i = " << i << std::endl;
// 		if (str[i] == ' ')
// 			i++;
// 		if (str[i] < 57 && str[i] >= 48)
// 		{
// 			if (str[i + 1] == ' ' || str[i + 1] == 0)
// 			{
// 				this->_stack.push(str[i]);
// 				std::cout << str[i] << " is puched" << std::endl;
// 				i++;	
// 			}
// 			else
// 				throw Exception("error argument's size 2");
// 		}
// 		else if (str[i] == '*' || str[i] == '/' || str[i] == '-' || str[i] == '+')
// 		{
// 			arg2 = _stack.top();
// 			_stack.pop();
// 			arg1 = _stack.top();
// 			_stack.pop();
// 			if (str[i] == '+')
// 				result = (arg1 - 48) + (arg2 - 48);
// 			std::cout << result << " is result" << std::endl;
// 			i++;
// 			this->_stack.push(result + 48);
// 		}
// 		else
// 			throw Exception("error argument's size");
// 	}
// 	i--;
// 	if (str[i] == '*' || str[i] == '/' || str[i] == '-' || str[i] == '+')
// 		std::cout << result << " is result final" << std::endl;
// 	else
// 		throw Exception("Error");
// }
