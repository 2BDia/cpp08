/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:22:17 by rvan-aud          #+#    #+#             */
/*   Updated: 2022/01/17 16:59:27 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <exception>

class	Span
{
	public:

		Span(void);
		Span(unsigned int N);
		Span(Span const &src);
		~Span(void);

		Span	&operator=(Span const &rhs);

		void	addNumber(int n);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan(void);
		int		longestSpan(void);

		class	VectorFullException : public std::exception
		{
			public:

				const char	*what() const throw()
				{
					return ("Class is full, can't add more numbers!");
				}
		};

		class	NotEnoughNumbersException : public std::exception
		{
			public:

				const char	*what() const throw()
				{
					return ("You need at least 2 numbers stored to know the span between them!");
				}
		};

	private:

		unsigned int		_size;
		std::vector<int>	_vector;
};
