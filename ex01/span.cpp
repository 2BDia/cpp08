/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:25:02 by rvan-aud          #+#    #+#             */
/*   Updated: 2022/01/17 17:11:27 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(void) : _size(0)
{
}

Span::Span(unsigned int N) : _size(N)
{
}

Span::Span(Span const &src)
{
	*this = src;
}

Span::~Span(void)
{
}

Span	&Span::operator=(Span const &rhs)
{
	this->_size = rhs._size;
	this->_vector = rhs._vector;
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->_vector.size() < this->_size)
		this->_vector.push_back(n);
	else
		throw(Span::VectorFullException());
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	unsigned int dist = std::distance(begin, end);
	if (dist > this->_size)
	{	
		this->_vector.insert(this->_vector.end(), begin, begin + this->_size);
		std::cout << *(this->_vector.begin()) << std::endl;
		throw(Span::VectorFullException());
	}
	else
		this->_vector.insert(this->_vector.end(), begin, end);
}

int	Span::shortestSpan(void)
{
	if (this->_vector.size() <= 1)
		throw(Span::NotEnoughNumbersException());
	else
	{
		std::vector<int>::iterator  it = this->_vector.begin();
		std::vector<int>::iterator  ite = this->_vector.end();
		std::vector<int>::iterator	meta = this->_vector.begin();
		std::vector<int>::iterator	tmp;

		int	gap = INT_MAX;

		tmp = ++it;
		while (meta != ite)
		{
			while (it != ite)
			{
				if (gap > abs(*it - *meta))
					gap = abs(*it - *meta);
				it++;
			}
			it = ++tmp;
			meta++;
		}
		return (gap);
	}
	return (0);
}

int	Span::longestSpan(void)
{
	if (this->_vector.size() <= 1)
		throw(Span::NotEnoughNumbersException());
	else
	{
		std::vector<int>::iterator  it = this->_vector.begin();
		std::vector<int>::iterator  ite = this->_vector.end();

		int	min = *it;
		int	max = *it;

		while (it != ite)
		{
			if (*it < min)
				min = *it;
			if (*it > max)
				max = *it;
			it++;
		}
		return (max - min);
	}
}
