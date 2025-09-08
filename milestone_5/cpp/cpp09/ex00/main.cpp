/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:06:57 by ecarbona          #+#    #+#             */
/*   Updated: 2025/09/08 10:43:38 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Error: could not open file" << std::endl, 1);
	try {
		BitcoinExchange btc;
		std::ifstream	file(argv[1]);
		std::string		line, values[2];
		double			ret;

		if (!file.is_open())
			return (std::cerr << "Error: could not open file" << std::endl, 1);
		if (file.peek() == std::ifstream::traits_type::eof())
			return (std::cerr << "Error: file is empty" << std::endl, 1);
		while(std::getline(file, line))
		{
			if (line == "date | value")
				continue;
			ret = btc.searchValue(line);
			if (ret == -1)
				continue;
			ft_split(line, '|', values);
			trim(values);
			std::cout << values[0] << " => " << values[1] << " = " << ret << std::endl;
		}
	} catch (const std::exception &e) {
		return (std::cerr << "Error: " << e.what() << std::endl, 1);
	}
	return (0);
}
