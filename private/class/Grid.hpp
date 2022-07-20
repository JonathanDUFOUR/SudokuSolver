/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 03:26:48 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/06 22:03:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Grid
{
private:
	short	cells[81];
public:
			Grid();
			Grid(char const **values);

	void	setCell(int index, short value);
	void	unsetCell(int index);
	void	addOption(int index, int option);
	void	removeOption(int index, int option);

	short	getCell(int index);

	void	print(void);
	void	printCellOptions(int index);
	void	printBorders(void);

	int		findAvailableOptions(void);
	int		reduceAvailableOptions(void);
	int		backtrack(int index);

	bool	isOptionFixed(int index);
	bool	isOptionSet(int index, int option);
	bool	isOptionAvailable(int index, int option);
	bool	checkRow(int index, int option);
	bool	checkCol(int index, int option);
	bool	checkSquare(int index, int option);
	int		getSquareCorner(int index);
};
