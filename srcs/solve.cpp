/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 04:15:59 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/03 01:38:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.hpp"

int	solve(char const **values)
{
	grid	sudoku(values);

	sudoku.findAvailableOptions();
	sudoku.print();
	return (SUCCESS);
}
