/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errMsg.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:32:50 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/02 21:09:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "sudoku.hpp"

int	errMsg(int errCode)
{
	printw("\e[31m");
	if (errCode == WRONG_AC)
		printw("Error: Wrong argument count\n");
	else if (errCode == WRONG_AV)
		printw("Error: Wrong argument value(s)\n");
	printw("\e[0m");
	return (errCode);
}
