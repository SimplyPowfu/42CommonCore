/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:28:12 by ecarbona          #+#    #+#             */
/*   Updated: 2025/08/08 16:40:49 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::fstream	file("data.csv");
	std::string		line;
	std::string		values[2];

	if (!file.is_open())
		throw FileNotFound();
	else
	{
		while (std::getline(file, line))
		{
			if (line == "date | value")
				continue;
			if (ft_split(line, ',', values))
			{
				trim(values);
				int key = convertData(values[0]);
				double value = std::atof(values[1].c_str());
				if (key != -1)
					data[key] = value;
			}
		}
	}
	// std::cout << "Costructor created" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& copy)
{
	std::cout << "Copy Costructor" << std::endl;
	*this = copy;
}

BitcoinExchange::~BitcoinExchange()
{
	// std::cout << "Distructor called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
		*this = copy;
	data = copy.data;
	return (*this);
}

const char* BitcoinExchange::FileNotFound::what() const throw()
{
	return ("File Not Found");
}

double BitcoinExchange::searchValue(std::string line)
{
	std::string		values[2];

	ft_split(line, '|', values);
	trim(values);
	int date = convertData(values[0]);
	if (date == -1)
		return (std::cout << "Error: bad input => " << line << std::endl, -1);
	double quantity = std::atof(values[1].c_str());
	if (quantity < 0)
		return (std::cout << "Error: not a positive number." << std::endl, -1);
	if (quantity > 1000)
		return (std::cout << "Error: too large a number." << std::endl, -1);
	while (data.find(date) == data.end() && date > 0)
		date--;
	return (quantity * data[date]);
}

bool ft_split(const std::string& s, char delimiter, std::string values[2])
{
	size_t pos = s.find(delimiter);
	if (pos == std::string::npos)
		return (false);
	values[0] = s.substr(0, pos);
	values[1] = s.substr(pos + 1);
	return (true);
}

bool parseDate(const std::string& str, int& year, int& month, int& day)
{
	if (str.length() != 10 || str[4] != '-' || str[7] != '-')
		return (false);
	year = std::atoi(str.substr(0, 4).c_str());
	month = std::atoi(str.substr(5, 2).c_str());
	day = std::atoi(str.substr(8, 2).c_str());
	return (true);
}

bool isLeapYear(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int getDaysInMonth(int year, int month)
{
	static const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if (month == 2 && isLeapYear(year))
		return 29;
	return (days[month - 1]);
}

int convertData(const std::string& data)
{
	int year, month, day;
	if (!parseDate(data, year, month, day))
		return (-1);
	if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > getDaysInMonth(year, month))
		return (-1);
	int days = year * 365 + year / 4;
	for (int i = 1; i < month; ++i)
		days += getDaysInMonth(year, i);
	days += day;
	return (days);
}

void trim(std::string (&arr)[2])
{
    while (!arr[0].empty() && std::isspace(static_cast<unsigned char>(arr[0].back()))) {
        arr[0].pop_back();
    }
    while (!arr[1].empty() && std::isspace(static_cast<unsigned char>(arr[1].front()))) {
        arr[1].erase(0, 1);
    }
}
