/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:25:31 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/13 08:28:05 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream &file, char **av)
{
	std::ifstream	ifdata;

    std::cout << "constructor BitcoinExchange" << std::endl;
	ifdata.open("data.csv", std::ifstream::in);
	this->fillMap(ifdata);
	this->fillInput(file, av);
}

BitcoinExchange::~BitcoinExchange() 
{
    std::cout << "destructor BitcoinExchange" << std::endl << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & src)
{
	*this = src;
	std::cout << "constructor BitcoinExchange copy" << std::endl;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & rhs)
{
	if (this != &rhs)
	{
		this->_data = rhs._data;
	}
    return *this;
}

void	BitcoinExchange::fillMap(std::ifstream &file)
{
	std::string		date;
	std::string		line;
	float			value;

	while (getline(file, line))
	{
		date = strtok((char *)line.c_str(), ",");
		value = std::atof(strtok(NULL, "\n"));
		this->_data.insert(std::pair<std::string, float>(date, value));
	}
}

void	BitcoinExchange::printMap()
{
	std::map<std::string, float>::iterator it;

	for (it = this->_data.begin(); it != this->_data.end(); it++)
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}
}

void	BitcoinExchange::fillInput(std::ifstream &inputs, char **av)
{
	std::string		date;
	std::string		line;
	float			value;

	inputs.open(av[1], std::ifstream::in);
	getline(inputs, line);
	while (getline(inputs, line))
	{
		if (line.find("|") == std::string::npos)
			std::cout << "Error: bad input => " << line << std::endl;
		else
		{
			date = strtok((char *)line.c_str(), "|");
			value = std::atof(strtok(NULL, "\n"));
			try
			{
				verifyInput(date, value);
				this->_data.insert(std::pair<std::string, float>(date, value));
				findDate(date, value);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
}

void BitcoinExchange::findDate(std::string date, float value)
{
	std::map<std::string, float>::iterator it = this->_data.find(date);
	if (it != this->_data.end())
	{
		it--;
		std::cout << it->first << " => " << value << " = " << (value * it->second) << std::endl;
		this->_data.erase(date);
	}
}

void BitcoinExchange::verifyInput(std::string date, float value)
{
	std::string	year;
	std::string	month;
	std::string	day;
	std::string	dates;

	year = strtok((char *)date.c_str(), "-");
	month = strtok(NULL, "-");
	day = strtok(NULL, "\0");
	dates = year + month + day;
	if (dates.length() > 10 || dates.length() < 9)
		throw std::logic_error("error: bad input => " + date);
	if ((std::atoi(dates.c_str()) > 20220329) || std::atoi(dates.c_str()) < 20090102)
		throw std::logic_error("error: bad input => " + date);
	if (std::atoi(month.c_str()) > 12 || std::atoi(day.c_str()) > 31)
		throw std::logic_error("error: bad input => " + date);
	if (value > 1000)
		throw std::logic_error("error: too large number.");
	if (value < 0)
		throw std::logic_error("error: not positive number.");
	std::map<std::string, float>::iterator it = this->_data.find(date);
	if (it != this->_data.end())
	{
		float valueF = value * it->second;
		std::ostringstream oss;
		oss << valueF;
		std::string myString = oss.str();
		throw std::logic_error(it->first + " => " + myString);
	}
}
