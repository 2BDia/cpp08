/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:18:28 by rvan-aud          #+#    #+#             */
/*   Updated: 2022/01/18 15:21:54 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>

template<typename T, typename Container = std::deque<T> >
class	MutantStack : public std::stack<T, Container>
{
	public:

		MutantStack(void) {};
		MutantStack(MutantStack const &src) : MutantStack<T, Container>::stack(src) {};
		~MutantStack(void) {};

		MutantStack	&operator=(MutantStack const &rhs)
		{
			this->MutantStack::stack::operator=(rhs);
			return (*this);
		}

		typedef typename Container::iterator	iterator;

		iterator	begin(void)
		{
			return (this->c.begin());
		}

		iterator	end(void)
		{
			return (this->c.end());
		}
};
