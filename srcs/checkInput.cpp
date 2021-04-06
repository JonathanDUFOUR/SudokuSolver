/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkInput.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:40:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/06 21:46:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.hpp"

int	checkInput(int ac, char const **av)
{
	int	i;
	int	j;

	if (ac != 10)
		return (WRONG_AC);
	i = 0;
	while (++i < 10)
	{
		j = -1;
		while (av[i][++j])
		{
			if (strchr(av[i][j], ALLOWED_CHARS) == ERROR)
				return (WRONG_AV);
		}
		if (j != 9)
			return (WRONG_AV);
	}
	return (SUCCESS);
}
