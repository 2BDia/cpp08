/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:37:45 by rvan-aud          #+#    #+#             */
/*   Updated: 2022/01/15 16:09:03 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <algorithm>

class	NoMatchException : public std::exception
{
	public:

		const char	*what() const throw()
		{
			return ("Didn't find the number");
		}
};

template<typename T>
typename T::iterator	easyfind(T &container, int toFind)
{
	typename T::iterator	it = container.begin();
	typename T::iterator	ite = container.end();

	while (it != ite)
	{
		if (*it == toFind)
			return (it);
		it++;
	}
	throw(NoMatchException());
}
