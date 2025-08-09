/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:28:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/08/09 11:36:10 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <vector>
# include <climits>
# include <string.h>
# include <iomanip>
# include <set>
# include <list>
# include <iostream>
# include <fstream>
# include <map>
#include <sys/time.h>

class PmergeMe
{
private:
	std::vector<unsigned int>	_unsort_vect;
	std::vector<unsigned int>	_sort_vect;
	double	_time_sort_vect;

	std::list<unsigned int>	_unsort_list;
	std::list<unsigned int>	_sort_list;
	double	_time_sort_list;
public:
	PmergeMe();
	PmergeMe(PmergeMe const& copy);
	PmergeMe& operator=(PmergeMe const& copy);
	~PmergeMe();

	void	store_numbers(int argc, char **argv);
	void	sort_vector();
	void	sort_list();
	void	fordJohnsonSortVect(std::vector<unsigned int> &data);
	void	fordJohnsonSortList(std::list<unsigned int> &data);
};

template <typename Container>
void print_container(const Container& container);

template <typename Container>
void sorted_result(const Container& unsorted, const Container& sorted, double time_ms, const std::string& container_name);

#endif