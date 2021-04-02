/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:50:07 by jodufour          #+#    #+#             */
/*   Updated: 2021/03/31 23:19:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.hpp"

int	strchr(char const c, char const *s)
{
	char const	*p = s;

	while (*p)
	{
		if (c == *p)
			return (p - s);
		++p;
	}
	return (ERROR);
}
