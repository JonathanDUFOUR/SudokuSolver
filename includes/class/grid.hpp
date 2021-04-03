/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 03:26:48 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/03 15:57:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class grid
{
private:
	short	cells[81];
public:
			grid();
			grid(char const **values);
	void	setCell(int index, short value);
	void	unsetCell(int index);
	void	addOption(int index, int option);
	void	removeOption(int index, int option);
	short	getCell(int index);
	void	print(void);
	void	printCellOptions(int index);
	void	printBorders(void);
	void	findAvailableOptions(void);
	void	reduceAvailableOptions(void);
	bool	isOptionFixed(int index);
	bool	isOptionSet(int index, int option);
	bool	isOptionAvailable(int index, int option);
	bool	checkRow(int index, int option);
	bool	checkCol(int index, int option);
	bool	checkSquare(int index, int option);
	int		getSquareCorner(int index);
};
