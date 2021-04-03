/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 23:32:45 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/03 04:27:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "sudoku.hpp"

void	setup(void)
{
	start_color();
	init_pair(STRONG_BORDER, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(LIGHT_BORDER, COLOR_CYAN, COLOR_BLACK);
	init_pair(EMPTY_SLOT, COLOR_WHITE, COLOR_BLACK);
	init_pair(MULTIPLE_OPTIONS, COLOR_YELLOW, COLOR_BLACK);
	init_pair(FIXED_OPTION, COLOR_GREEN, COLOR_BLACK);
	curs_set(0);
	cbreak();
	noecho();
	scrollok(stdscr, TRUE);
}
