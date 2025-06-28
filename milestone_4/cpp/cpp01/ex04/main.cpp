/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:55:40 by ecarbona          #+#    #+#             */
/*   Updated: 2025/06/28 19:25:40 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	replaceFile(std::string filename, std::string target, std::string replace)
{
	std::ifstream file(filename);

	if (!file.is_open())
	{
		std::cerr << "Error, file not open" << std::endl;
		return ;
	}
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error, new file not create" << std::endl;
		return ;
	}
	std::string line;
	size_t pos;
	while (std::getline(file, line))
	{
		pos = 0;
		while ((pos = line.find(target, pos)) != std::string::npos)
		{
			line.erase(pos, target.length());
			line.insert(pos, replace);
			pos += replace.length();
		}
		outfile << line << std::endl;
	}
	file.close();
	outfile.close();
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cerr << "Invalid Arguments" << std::endl, 1);
	replaceFile(argv[1], argv[2], argv[3]);
	return (0);
}