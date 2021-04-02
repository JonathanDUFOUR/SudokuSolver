/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:02:38 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/03 00:09:03 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include <string>
#include "sudoku.hpp"

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

void	grid::setCell(int index, int value)
{
	cells[index] = 1 << (value - 1);
}

short	grid::getCell(int index)
{
	return (cells[index]);
}

void	grid::print(void)
{
	int	i;
	int	j;

	printBorders();
	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
		{
			printCellOptions(i, j);
		}
	}
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

void	grid::printCellOptions(int i, int j)
{
	int	poss;

	poss = -1;
	while (++poss < 9)
	{
		move(((i * 4) + (poss / 3) + 1), ((j * 8) + ((poss % 3) * 2) + 2));
		if (isOptionSet(i, j, poss))
		{
			printw(std::string(std::to_string(poss + 1)).c_str());
		}
		else
		{
			printw("-");
		}
	}
}

bool	grid::isOptionSet(int i, int j, int poss)
{
	return ((cells[i * 9 + j] >> poss) & 1);
}
