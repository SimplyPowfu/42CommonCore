/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:28:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/08/09 11:57:41 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<int>	RPN::_stack;

RPN::RPN() {}

RPN::RPN(RPN const& copy) { *this = copy; }

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &copy)
{
	if (this != &copy)
		_stack = copy._stack;
	return (*this);
}

int		operation(std::string operate, int a, int b)
{
	if (operate == "+")
		return (a + b);
	if (operate == "-")
		return (a - b);
	if (operate == "*")
		return (a * b);
	if (operate == "/")
		return (a / b);
	return (0);
}

bool	isNum(std::string word)
{
	size_t	i;
	for (i = 0; i < word.size(); i++)
	{
		if (!std::isdigit(word[i]))
			break;
	}
	if (i == word.size() && word.size() != 0)
		return (true);
	return (false);
}

void	RPN::calculate(char *input)
{
	std::stringstream	ss(input);
	std::string			word;
	std::string			operators = "+-/*";
	int					res = 0;

	while (std::getline(ss, word, ' '))
	{
		if (word == "+" || word == "-" || word == "*" || word == "/")
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error");
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			res = operation(word, a, b);
			_stack.push(res);
		}
		else if (isNum(word) && atoi(word.c_str()) >= 0 && atoi(word.c_str()) < 10)
		{
			_stack.push(atoi(word.c_str()));
		}
		else
			throw std::runtime_error("Error");
	}
	if (_stack.size() == 1)
		std::cout << _stack.top() << std::endl;
	else
		throw std::runtime_error("Error");
}
