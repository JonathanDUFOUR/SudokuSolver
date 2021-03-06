/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 04:15:59 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/06 21:50:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.hpp"

int	solve(char const **values)
{
	Grid	sudoku(values);
	int		ret;
	int		i;

	ret = sudoku.findAvailableOptions();
	if (ret != SUCCESS)
		return (ret);
	i = -1;
	while (++i < 10)
	{
		ret = sudoku.reduceAvailableOptions();
		if (ret != SUCCESS)
			return (ret);
	}
	ret = sudoku.backtrack(0);
	if (ret == SUCCESS)
		sudoku.print();
	return (ret);
}
