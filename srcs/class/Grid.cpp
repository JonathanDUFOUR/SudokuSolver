/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:02:38 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/14 09:16:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include <string>
#include "sudoku.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Grid::Grid(void)
{
	int	i;

	i = -1;
	while (++i < 81)
		unsetCell(i);
}

Grid::Grid(char const **values)
{
	int	i;

	i = -1;
	while (++i < 81)
	{
		unsetCell(i);
		if (values[i / 9][i % 9] >='1' && values[i / 9][i % 9] <= '9')
			addOption(i, (values[i / 9][i % 9] - '0' - 1));
	}
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

short	Grid::getCell(int index)
{
	return (cells[index]);
}

void	Grid::setCell(int index, short value)
{
	cells[index] = value;
}

void	Grid::unsetCell(int index)
{
	cells[index] = 0;
}

void	Grid::addOption(int index, int option)
{
	cells[index] += 1 << option;
}

void	Grid::removeOption(int index, int option)
{
	cells[index] -= (1 << option);
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

void	Grid::print(void)
{
	int	i;

	printBorders();
	i = -1;
	while (++i < 81)
		printCellOptions(i);
	pause();
}

void	Grid::printBorders(void)
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

void	Grid::printCellOptions(int index)
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

int		Grid::findAvailableOptions(void)
{
	int		i;
	int		option;
	bool	impossible;

	i = -1;
	while (++i < 81)
	{
		if (!isOptionFixed(i))
		{
			unsetCell(i);
			impossible = true;
			option = -1;
			while (++option < 9)
			{
				if (isOptionAvailable(i, option))
				{
					impossible = false;
					addOption(i, option);
				}
			}
			if (impossible)
				return (IMPOSSIBLE);
		}
	}
	return (SUCCESS);
}

int		Grid::reduceAvailableOptions(void)
{
	int	option;
	int	set;
	int removed;
	int	i;

	i = -1;
	while (++i < 81)
	{
		if (!isOptionFixed(i))
		{
			set = 0;
			removed = 0;
			option = -1;
			while (++option < 9)
			{
				if (isOptionSet(i, option))
				{
					++set;
					if (!isOptionAvailable(i, option))
					{
						++removed;
						removeOption(i, option);
					}
				}
			}
			if (set == removed)
				return (IMPOSSIBLE);
		}
	}
	return (SUCCESS);
}

int		Grid::backtrack(int index)
{
	short	cellCpy;
	int		option;
	int		ret;

	this->print();
	while (isOptionFixed(index) && index < 81)
		++index;
	if (index < 81)
	{
		cellCpy = cells[index];
		option = -1;
		while (++option < 9)
		{
			if (isOptionSet(index, option) && isOptionAvailable(index, option))
			{
				unsetCell(index);
				addOption(index, option);
				ret = backtrack(index + 1);
				if (ret == IMPOSSIBLE)
				{
					cells[index] = cellCpy;
				}
				else
				{
					return (SUCCESS);
				}
			}
		}
		return (IMPOSSIBLE);
	}
	return (SUCCESS);
}

bool	Grid::isOptionSet(int index, int option)
{
	return ((cells[index] >> option) & 1);
}

bool	Grid::isOptionFixed(int index)
{
	return (cells[index] == 1 << 0 ||
			cells[index] == 1 << 1 ||
			cells[index] == 1 << 2 ||
			cells[index] == 1 << 3 ||
			cells[index] == 1 << 4 ||
			cells[index] == 1 << 5 ||
			cells[index] == 1 << 6 ||
			cells[index] == 1 << 7 ||
			cells[index] == 1 << 8);
}

bool	Grid::isOptionAvailable(int index, int option)
{
	return (checkRow(index, option) &&
			checkCol(index, option) &&
			checkSquare(index, option));
}

bool	Grid::checkRow(int index, int option)
{
	int	idx;
	int i;
	
	i = -1;
	while (++i < 9)
	{
		idx = index - (index % 9) + i;
		if (idx != index &&
			isOptionFixed(idx) &&
			isOptionSet(idx, option))
		{
			return (false);
		}
	}
	return (true);
}

bool	Grid::checkCol(int index, int option)
{
	int	idx;
	int i;

	i = -1;
	while (++i < 9)
	{
		idx = (index % 9) + (i * 9);
		if (idx != index &&
			isOptionFixed(idx) &&
			isOptionSet(idx, option))
		{
			return (false);
		}
	}
	return (true);
}

bool	Grid::checkSquare(int index, int option)
{
	int	idx;
	int corner;
	int	i;

	corner = getSquareCorner(index);
	i = -1;
	while (++i < 9)
	{
		idx = corner + (9 * (i / 3)) + (i % 3);
		if (idx != index &&
			isOptionFixed(idx) &&
			isOptionSet(idx, option))
		{
			return (false);
		}
	}
	return (true);
}

int		Grid::getSquareCorner(int index)
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
