/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scao <scao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:37:37 by scao              #+#    #+#             */
/*   Updated: 2019/03/06 19:46:49 by scao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		checkshape(char *block)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (block[i] == '#')
		{
			if (i >= 1 && block[i - 1] == '#')
				count++;
			if (i < 19 && block[i + 1] == '#')
				count++;
			if (i >= 5 && block[i - 5] == '#')
				count++;
			if (i < 15 && block[i + 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int		checkmap(char *block)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (!(block[i * 5 + j] == '.' || block[i * 5 + j] == '#'))
				return (0);
			if (block[i * 5 + j] == '#')
				count++;
			j++;
		}
		if (block[i * 5 + j] != '\n')
			return (0);
		j = 0;
		i++;
	}
	if (count != 4)
		return (0);
	return (1);
}
