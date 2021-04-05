/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 04:15:59 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/05 02:01:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.hpp"

int	solve(char const **values)
{
	grid	sudoku(values);
	int		ret;
	int		i;

	sudoku.findAvailableOptions();
	i = -1;
	while (++i < 10)
	{
		ret = sudoku.reduceAvailableOptions();
		if (ret != SUCCESS)
			return (ret);
	}
	sudoku.print();
	return (SUCCESS);
}
