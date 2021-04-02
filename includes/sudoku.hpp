/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:01:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/02 23:47:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "class/grid.hpp"

# define ALLOWED_CHARS ".123456789"

enum	e_retCodes
{
	ERROR = -1,
	SUCCESS,
	WRONG_AC,
	WRONG_AV,
	IMPOSSIBLE
};

enum	e_colors
{
	STRONG_BORDER = 1,
	LIGHT_BORDER,
	EMPTY_SLOT,
	OPTION_SLOT
};

void	setup(void);
int		errMsg(int errCode);
int		checkInput(int ac, char const **av);
int		strchr(char const c, char const *s);
int		solve(char const **values);
void	pause(void);
