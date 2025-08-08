/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:28:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/08/08 13:58:09 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINTEXCHANGE_HPP
# define BITCOINTEXCHANGE_HPP

# include <algorithm>
# include <vector>
# include <climits>
# include <iomanip>
# include <set>
# include <stack>
# include <iostream>
# include <fstream>
# include <map>

class BitcoinExchange
{
private:
	std::map<int, double> data;
public:
	BitcoinExchange();
	BitcoinExchange(std::string str);
	BitcoinExchange(BitcoinExchange const& copy);
	BitcoinExchange& operator=(BitcoinExchange const& copy);
	~BitcoinExchange();

	class FileNotFound : public std::exception
	{
		virtual const char* what() const throw();
	};
	double	searchValue(std::string input);
};

void trim(std::string (&arr)[2]);
bool ft_split(const std::string& s, char delimiter, std::string values[2]);
int convertData(const std::string& data);

#endif