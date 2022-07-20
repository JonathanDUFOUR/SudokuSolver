/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:01:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/05 01:58:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.hpp"
#include <ncurses.h>

int	main(int ac, char const **av)
{
	int		ret;

	initscr();
	if (has_colors() == FALSE)
	{
		endwin();
		std::cout << "Your terminal does not support color" << std::endl;
		return (0);
	}
	setup();
	ret = checkInput(ac, av);
	if (ret == SUCCESS)
		ret = solve(av + 1);
	if (ret != SUCCESS)
		errMsg(ret);
	endwin();
	return (ret);
}
