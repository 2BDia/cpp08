/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:25:42 by rvan-aud          #+#    #+#             */
/*   Updated: 2022/01/17 17:12:37 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int	main(void)
{
	{
		Span	sp(5);

		try
		{
			sp.addNumber(5);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span = " << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		Span	span(15000);
		std::vector<int>	vect;

		for (int i = 0; i < 20000; i++)
			vect.push_back(i);
		try
		{
			span.addNumber(vect.begin(), vect.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Shortest span = " << span.shortestSpan() << std::endl;
		std::cout << "Longest span = " << span.longestSpan() << std::endl;
	}
	return (0);
}
