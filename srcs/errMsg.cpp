/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errMsg.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:32:50 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/05 01:57:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "sudoku.hpp"

void	errMsg(int errCode)
{
	attron(COLOR_PAIR(ERROR_MESSAGE));
	if (errCode == WRONG_AC)
		printw("Error: Wrong argument count\n");
	else if (errCode == WRONG_AV)
		printw("Error: Wrong argument value(s)\n");
	else if (errCode == IMPOSSIBLE)
		printw("Error: No solution for this input\n");
	attroff(COLOR_PAIR(ERROR_MESSAGE));
}
