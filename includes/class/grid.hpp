/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 03:26:48 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/03 04:10:00 by jodufour         ###   ########.fr       */
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
	void	findAvailableOptions(void);
	bool	isOptionFixed(int index);
	bool	isOptionAvailable(int option, int index);
	bool	checkRow(int option, int index);
	bool	checkCol(int option, int index);
	bool	checkSquare(int option, int index);
	int		getSquareCorner(int index);
	bool	isOptionSet(int i, int j, int poss);
};
