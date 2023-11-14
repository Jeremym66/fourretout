/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:08:23 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/14 10:18:36 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdexcept>
#include <vector>
#include <list>
#include <thread>
#include <ctime>

class PmergeMe
{
    private :

        std::vector<int> _vec;
        std::list<int> _list;

        PmergeMe(void);
        
    public :

        
        PmergeMe(int ac, char **av);
        ~PmergeMe(void);
        PmergeMe(const PmergeMe & src);
        PmergeMe & operator=(const PmergeMe & rhs);


        void    merge(std::vector<int> & arr, int left, int middle, int right);
        void    mergeSort(std::vector<int> & arr, int left, int right);
        void    mergeList(std::list<int>& arr, std::list<int>::iterator left, std::list<int>::iterator middle, std::list<int>::iterator right);
        void    mergeSortList(std::list<int>& arr, std::list<int>::iterator left, std::list<int>::iterator right);

        long long int	getTime();
        
        template <typename T>
	    void    display(const T& container);

        class Exception : public std::exception
        {
            private :

                const char  *_msg;
            
            public :

                Exception(void) : _msg("error") {}
                Exception(const char *msg) : _msg(msg) {}
                const char* what() const throw()
                {
                    return this->_msg;
                }
        };
};
