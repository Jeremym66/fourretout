/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:39:30 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/14 10:22:38 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av)
{
	std::cout << "constructor PmergeMe" << std::endl;
    srand(time(NULL));
    for (int i = 1; i < ac; ++i)
    {
        int value = atoi(av[i]);
        if (value <= 0)
        {
            std::cerr << "Error: Invalid input value \"" << av[i] << "\". Only positive integers are allowed." << std::endl;
			exit(1);
        }
        _vec.push_back(value);
        _list.push_back(value);
    }
    std::cout << "Before: ";
    display(_vec);
	
    long long int start1 = getTime();
	mergeSort(_vec, 0, _vec.size() - 1);
    long long int end1 = getTime();
    double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

    long long int start2 = getTime();
	mergeSortList(_list, _list.begin(), _list.end());
    long long int end2 = getTime();
    double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

    std::cout << "After: ";
    display(_vec);
    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector container: " << time1 << " us" << std::endl;
    std::cout << "Time to process a range of " << _list.size() << " elements with std::list container: " << time2 << " us" << std::endl;
    if (_vec == std::vector<int>(_list.begin(), _list.end()))
        std::cout << "The sorted sequences(vector and list) are equal. GOOD JOB !" << std::endl;
    else
        std::cout << "The sorted sequences(vector and list) are not equal." << std::endl;
}

long long int	PmergeMe::getTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000LL) + tv.tv_usec;
}

PmergeMe::~PmergeMe() 
{
    std::cout << "destructor PmergeMe" << std::endl << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe & src)
{
	*this = src;
	std::cout << "constructor PmergeMe copy" << std::endl;
}

PmergeMe & PmergeMe::operator=(const PmergeMe & rhs)
{
	if (this != &rhs)
	{
		this->_vec = rhs._vec;
	}
    return *this;
}

template <typename T>
void PmergeMe::display(const T& container)
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::merge(std::vector<int> & arr, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) 
	{
        if (L[i] <= R[j]) 
		{
            arr[k] = L[i];
            i++;
        }
		else
		{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
	{
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
	{
        arr[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::mergeSort(std::vector<int> & arr, int left, int right)
{
    if (left < right) 
	{
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

void PmergeMe::mergeList(std::list<int>& arr, std::list<int>::iterator left, std::list<int>::iterator middle, std::list<int>::iterator right)
{
    std::list<int> L(left, middle);
    std::list<int> R(middle, right);

    auto itL = L.begin();
    auto itR = R.begin();
    auto it = left;

    while (itL != L.end() && itR != R.end()) {
        if (*itL <= *itR) {
            *it = *itL;
            ++itL;
        } else {
            *it = *itR;
            ++itR;
        }
        ++it;
    }

    while (itL != L.end()) {
        *it = *itL;
        ++itL;
        ++it;
    }

    while (itR != R.end()) {
        *it = *itR;
        ++itR;
        ++it;
    }
}

void PmergeMe::mergeSortList(std::list<int>& arr, std::list<int>::iterator left, std::list<int>::iterator right)
{
    if (std::distance(left, right) > 1)
	{
        auto middle = std::next(left, std::distance(left, right) / 2);

        mergeSortList(arr, left, middle);
        mergeSortList(arr, middle, right);

        mergeList(arr, left, middle, right);
    }
}