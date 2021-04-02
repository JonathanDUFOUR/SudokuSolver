/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 03:26:48 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/02 23:54:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class grid
{
private:
	short	cells[81];
public:
			grid(char const **values);
	void	setCell(int index, int value);
	short	getCell(int index);
	void	print(void);
	void	printCellOptions(int i, int j);
	void	printBorders(void);
	bool	isOptionSet(int i, int j, int poss);
};
