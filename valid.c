/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scao <scao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:38:30 by scao              #+#    #+#             */
/*   Updated: 2019/03/06 19:25:13 by scao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				is_input_valid(char *buff)
{
	int			i;
	char		*block;

	i = 0;
	if (!(block = ft_strnew(20)))
		return (0);
	while (i <= 26)
	{
		if (!(ft_strncpy(block, &(buff[i * 21]), 20)))
			return (0);
		if (!checkmap(block) || !checkshape(block))
		{
			free(block);
			return (0);
		}
		i++;
		if (buff[i * 20 + (i - 1)] == '\0')
			break ;
	}
	free(block);
	return (1);
}

char			**make2darray(char *buff, int *count, char **newarray)
{
	t_hello		ind;

	if (!(newarray = (char**)malloc(27 * sizeof(char*))))
		return (NULL);
	newarray[26] = NULL;
	ind.i = 0;
	while (ind.i < 26)
		if (!(newarray[ind.i++] = ft_strnew(16)))
			return (NULL);
	ind.i = -1;
	ind.j = 0;
	while (buff[++ind.i])
	{
		if (buff[ind.i] != '\n')
		{
			if (buff[ind.i] == '.')
				newarray[ind.j / 16][ind.j % 16] = '.';
			else
				newarray[ind.j / 16][ind.j % 16] = 'A' + ((ind.j / 16));
			ind.j++;
		}
		check_j(ind.j);
	}
	*count = ind.j / 16;
	return (newarray);
}
