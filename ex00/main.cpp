/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:48:31 by rvan-aud          #+#    #+#             */
/*   Updated: 2022/01/15 16:16:10 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
#include "easyfind.hpp"

int	main(void)
{
	std::vector<int>	vect;
	std::list<float>	list;

	std::vector<int>::iterator	found_i;
	std::list<float>::iterator	found_f;

	std::cout << "*** Vector ***" << std::endl;
	for (int i = 0; i <= 10; i++)
		vect.push_back(i * 10);
	try
	{
		found_i = easyfind(vect, 50);
		std::cout << *found_i << std::endl;
		found_i = easyfind(vect, 84);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "*** List ***" << std::endl;
	for (float f = 0.0; f <= 10; f++)
		list.push_back(f * 10.5);
	try
	{
		found_f = easyfind(list, 21.0);
		std::cout << *found_f << std::endl;
		found_f = easyfind(list, 80.0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
