/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:28:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/07/29 13:36:06 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <algorithm>
# include <vector>
# include <iostream>
# include <climits>
# include <iomanip>
# include <set>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack<T>()
	{
		std::cout << "Costructor created" << std::endl;
	}

	MutantStack<T>(MutantStack<T> const &copy)
	{
		std::cout << "Copy Costructor" << std::endl;
		*this = copy;
	}

	~MutantStack<T>(void)
	{
		std::cout << "Distructor called" << std::endl;
	}

	MutantStack<T> &operator=(const MutantStack<T> &copy)
	{
		if (this != &copy)
			*this = copy;
		return (*this);
	}

	typedef typename MutantStack<T>::container_type::iterator iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

	typedef typename MutantStack<T>::container_type::const_iterator const_iterator;
	const_iterator begin() const { return this->c.cbegin(); }
	const_iterator end() const { return this->c.cend(); }

	typedef typename MutantStack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }

	typedef typename MutantStack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator rbegin() const { return this->c.crbegin(); }
	const_reverse_iterator rend() const { return this->c.crend(); }

	using std::stack<T>::pop;
	using std::stack<T>::push;
};

#endif