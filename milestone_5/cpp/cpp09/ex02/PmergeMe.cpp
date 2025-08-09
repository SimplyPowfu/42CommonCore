/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:28:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/08/09 16:46:09 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _time_sort_vect(0) {}

PmergeMe::PmergeMe(PmergeMe const& copy) { *this = copy; }

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		this->_unsort_vect = copy._unsort_vect;
		this->_sort_vect = copy._sort_vect;
		this->_time_sort_vect = copy._time_sort_vect;
		this->_unsort_list = copy._unsort_list;
		this->_sort_list = copy._sort_list;
		this->_time_sort_list = copy._time_sort_list;
	}
	return (*this);
}

void	PmergeMe::store_numbers(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		for (unsigned int j = 0; j < strlen(argv[i]); j++)
		{
			if (!std::isdigit(argv[i][j]))
				throw std::runtime_error("Error: Invalid character");
		}
		int value = std::atoi(argv[i]);
		if (value < 0)
			throw std::runtime_error("Error: Negative number");
		_unsort_vect.push_back(value);
		_unsort_list.push_back(value);
	}
	_sort_vect = _unsort_vect;
	_sort_list = _unsort_list;
	sort_vector();
	sort_list();
}

void PmergeMe::fordJohnsonSortVect(std::vector<unsigned int> &data)
{
	if (data.size() < 2)
		return;
	std::vector<unsigned int> sorted;
	std::vector<unsigned int> buffer_min;

	if (data[0] < data[1]) {
		sorted.push_back(data[0]);
		sorted.push_back(data[1]);
	} else {
		sorted.push_back(data[1]);
		sorted.push_back(data[0]);
	}
	for (size_t i = 2; i + 1 < data.size(); i += 2) {
		int a = data[i];
		int b = data[i + 1];
		if (a < b) {
			buffer_min.push_back(a);
			sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), b), b);
		}
		else {
			buffer_min.push_back(b);
			sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), a), a);
		}
	}
	if (data.size() % 2 != 0) {
		int last = data.back();
		sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), last), last);
	}
	for (int val : buffer_min) {
		sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), val), val);
	}
	data = sorted;
}

void insertSorted(std::list<unsigned int> &lst, unsigned int value)
{
	std::list<unsigned int>::iterator it = lst.begin();
	while (it != lst.end() && *it < value) {
		++it;
	}
	lst.insert(it, value);
}

void PmergeMe::fordJohnsonSortList(std::list<unsigned int> &data)
{
	if (data.size() < 2)
		return;
	std::list<unsigned int> sorted;
	std::list<unsigned int> buffer_min;

	std::list<unsigned int>::iterator it = data.begin();
	unsigned int first = *it++;
	unsigned int second = *it++;

	if (first < second) {
		sorted.push_back(first);
		sorted.push_back(second);
	} else {
		sorted.push_back(second);
		sorted.push_back(first);
	}
	while (it != data.end()) {
		unsigned int a = *it++;
		if (it != data.end()) {
			unsigned int b = *it++;
			if (a < b) {
				buffer_min.push_back(a);
				insertSorted(sorted, b);
			}
			else {
				buffer_min.push_back(b);
				insertSorted(sorted, a);
			}
		}
		else {
			insertSorted(sorted, a);
		}
	}
	for (unsigned int val : buffer_min) {
		insertSorted(sorted, val);
	}
	data = sorted;
}

void PmergeMe::sort_vector()
{
	struct timeval start, stop;

	gettimeofday(&start, NULL);
	fordJohnsonSortVect(_sort_vect);
	gettimeofday(&stop, NULL);
	_time_sort_vect = (stop.tv_sec - start.tv_sec) * 1000.0;
	_time_sort_vect += (stop.tv_usec - start.tv_usec) / 1000.0;
	sorted_result(_unsort_vect, _sort_vect, _time_sort_vect, "std::vector");
}

void PmergeMe::sort_list()
{
	struct timeval start, stop;

	gettimeofday(&start, NULL);
	fordJohnsonSortList(_sort_list);
	gettimeofday(&stop, NULL);
	_time_sort_list = (stop.tv_sec - start.tv_sec) * 1000.0;
	_time_sort_list += (stop.tv_usec - start.tv_usec) / 1000.0;
	sorted_result(_unsort_list, _sort_list, _time_sort_list, "std::list");
}

template <typename Container>
void sorted_result(const Container& unsorted, const Container& sorted, double time_ms, const std::string& container_name)
{
	if (container_name == "std::vector")
	{
		std::cout << "Before: ";
		print_container(unsorted);
		std::cout << "After: ";
		print_container(sorted);
	}
	std::cout	<< "Time to process a range of " << unsorted.size()
				<< " elements with " << container_name << ": "
				<< time_ms << " ms" << std::endl;
}

template <typename Container>
void print_container(const Container& container)
{
	size_t count = 0;
	for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		if (count == 10)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << *it << " ";
		++count;
	}
	std::cout << std::endl;
}
