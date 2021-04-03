/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:02:38 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/03 04:52:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include <string>
#include "sudoku.hpp"

//	Constructor
grid::grid(char const **values)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
		{
			if (values[i][j] >= '1' && values[i][j] <= '9')
				setCell(i * 9 + j, values[i][j] - '0');
			else
				cells[i * 9 + j] = 0;
		}
	}
}

//	Seter
void	grid::setCell(int index, int value)
{
	cells[index] = 1 << (value - 1);
}

//	Geter
short	grid::getCell(int index)
{
	return (cells[index]);
}

//////////////////////////////////  Methods  //////////////////////////////////

void	grid::print(void)
{
	int	i;

	printBorders();
	i = -1;
	while (++i < 81)
		printCellOptions(i);
}

void	grid::printBorders(void)
{
	int	i;

	move(0, 0);
	i = -1;
	while (++i < 37)
	{
		move(i, 0);
		if (!(i % 4))
		{
			if (!(i % 3))
			{
				attron(COLOR_PAIR(STRONG_BORDER));
				printw("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
				attroff(COLOR_PAIR(STRONG_BORDER));
			}
			else
			{
				
				attron(COLOR_PAIR(STRONG_BORDER));
				printw("#");
				attroff(COLOR_PAIR(STRONG_BORDER));
				attron(COLOR_PAIR(LIGHT_BORDER));
				printw("-------+-------+-------");
				attroff(COLOR_PAIR(LIGHT_BORDER));
				attron(COLOR_PAIR(STRONG_BORDER));
				printw("#");
				attroff(COLOR_PAIR(STRONG_BORDER));
				attron(COLOR_PAIR(LIGHT_BORDER));
				printw("-------+-------+-------");
				attroff(COLOR_PAIR(LIGHT_BORDER));
				attron(COLOR_PAIR(STRONG_BORDER));
				printw("#");
				attroff(COLOR_PAIR(STRONG_BORDER));
				attron(COLOR_PAIR(LIGHT_BORDER));
				printw("-------+-------+-------");
				attroff(COLOR_PAIR(LIGHT_BORDER));
				attron(COLOR_PAIR(STRONG_BORDER));
				printw("#");
				attroff(COLOR_PAIR(STRONG_BORDER));
			}
		}
		else
		{
			attron(COLOR_PAIR(STRONG_BORDER));
			printw("#");
			attroff(COLOR_PAIR(STRONG_BORDER));
			attron(COLOR_PAIR(LIGHT_BORDER));
			move(i, 8);
			printw("|");
			move(i, 16);
			printw("|");
			attroff(COLOR_PAIR(LIGHT_BORDER));
			attron(COLOR_PAIR(STRONG_BORDER));
			move(i, 24);
			printw("#");
			attroff(COLOR_PAIR(STRONG_BORDER));
			attron(COLOR_PAIR(LIGHT_BORDER));
			move(i, 32);
			printw("|");
			move(i, 40);
			printw("|");
			attroff(COLOR_PAIR(LIGHT_BORDER));
			attron(COLOR_PAIR(STRONG_BORDER));
			move(i, 48);
			printw("#");
			attroff(COLOR_PAIR(STRONG_BORDER));
			attron(COLOR_PAIR(LIGHT_BORDER));
			move(i, 56);
			printw("|");
			move(i, 64);
			printw("|");
			attroff(COLOR_PAIR(LIGHT_BORDER));
			attron(COLOR_PAIR(STRONG_BORDER));
			move(i, 72);
			printw("#");
			attroff(COLOR_PAIR(STRONG_BORDER));
		}
	}
	
}

void	grid::printCellOptions(int index)
{
	int	option;

	option = -1;
	if (isOptionFixed(index))
	{
		while (++option < 9)
		{
			move(	(((index / 9) * 4) + (option / 3) + 1),
					(((index % 9) * 8) + ((option % 3) * 2) + 2));
			if (isOptionSet(index, option))
			{
				attron(COLOR_PAIR(FIXED_OPTION));
				printw(std::string(std::to_string(option + 1)).c_str());
				attroff(COLOR_PAIR(FIXED_OPTION));
			}
			else
			{
				attron(COLOR_PAIR(EMPTY_SLOT));
				printw("-");
				attroff(COLOR_PAIR(EMPTY_SLOT));
			}
		}
	}
	else
	{
		while (++option < 9)
		{
			move(	(((index / 9) * 4) + (option / 3) + 1),
					(((index % 9) * 8) + ((option % 3) * 2) + 2));
			if (isOptionSet(index, option))
			{
				attron(COLOR_PAIR(MULTIPLE_OPTIONS));
				printw(std::string(std::to_string(option + 1)).c_str());
				attroff(COLOR_PAIR(MULTIPLE_OPTIONS));
			}
			else
			{
				attron(COLOR_PAIR(EMPTY_SLOT));
				printw("-");
				attroff(COLOR_PAIR(EMPTY_SLOT));
			}
		}
	}
}

void	grid::findAvailableOptions(void)
{
	int	i;
	int	option;

	i = -1;
	while (++i < 81)
	{
		if (!isOptionFixed(i))
		{
			option = -1;
			while (++option < 9)
			{
				if (isOptionAvailable(option, i))
				{
					cells[i] += 1 << option;
				}
			}
		}
	}
}

void	grid::reduceAvailableOptions(void)
{
	int	i;
	int	option;

	i = -1;
	while (++i < 81)
	{
		if (!isOptionFixed(i))
		{
			option = -1;
			while (++option < 9)
			{
				if (isOptionSet(i, option))
				{
					if (!isOptionAvailable(option, i))
					{
						cells[i] -= 1 << option;
					}
				}
			}
		}
	}
}

bool	grid::isOptionSet(int index, int option)
{
	return ((cells[index] >> option) & 1);
}

bool	grid::isOptionFixed(int index)
{
	return (cells[index] == 1 ||
			cells[index] == 1 << 1 ||
			cells[index] == 1 << 2 ||
			cells[index] == 1 << 3 ||
			cells[index] == 1 << 4 ||
			cells[index] == 1 << 5 ||
			cells[index] == 1 << 6 ||
			cells[index] == 1 << 7 ||
			cells[index] == 1 << 8);
}

bool	grid::isOptionAvailable(int option, int index)
{
	return (checkRow(option, index) &&
			checkCol(option, index) &&
			checkSquare(option, index));
}

bool	grid::checkRow(int option, int index)
{
	int i;

	index -= (index % 9);
	i = -1;
	while (++i < 9)
	{
		if (isOptionFixed(index + i) &&
			cells[index + i] == 1 << option)
			return (false);
	}
	return (true);
}

bool	grid::checkCol(int option, int index)
{
	int i;

	index %= 9;
	i = -1;
	while (++i < 9)
	{
		if (isOptionFixed(index + (i * 9)) &&
			cells[index + (i * 9)] == 1 << option)
			return (false);
	}
	return (true);
}

bool	grid::checkSquare(int option, int index)
{
	int	i;

	index = getSquareCorner(index);
	i = -1;
	while (++i < 9)
	{
		if (isOptionFixed(index + (9 * (i / 3)) + (i % 3)) &&
			cells[index + (9 * (i / 3)) + (i % 3)] == 1 << option)
			return (false);
	}
	return (true);
}

int		grid::getSquareCorner(int index)
{
	if ((index >= 0 && index <= 8) ||
		(index >= 27 && index <= 35) ||
		(index >= 54 && index <= 62))
		return (index - (index % 3));
	if ((index >= 9 && index <= 17) ||
		(index >= 36 && index <= 44) ||
		(index >= 63 && index <= 71))
		return (index - (index % 3) - 9);
	return (index - (index % 3) - 18);
	
}
