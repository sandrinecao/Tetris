/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scao <scao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:19:46 by scao              #+#    #+#             */
/*   Updated: 2019/03/08 08:00:53 by scao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			delsplit(char ***split)
{
	int			i;
	char		**tmp;

	i = 0;
	tmp = *split;
	while (tmp[i])
	{
		free(tmp[i]);
		tmp[i] = NULL;
		i++;
	}
	free(tmp);
	tmp = NULL;
}

int				fillit(int fd, int ret)
{
	int			count;
	char		buff[547];
	char		**map2solve;
	char		**newarray;

	newarray = NULL;
	ft_bzero(&(buff[0]), 547);
	count = 0;
	{
		ret = read(fd, buff, 546);
		buff[ret + 1] = 0;
		if (is_input_valid(buff))
		{
			if (!(map2solve = make2darray(buff, &count, newarray)))
				return (1);
			solve(map2solve, count);
			delsplit(&map2solve);
		}
		else
			ft_error();
	}
	return (0);
}

int				main(int ac, char **av)
{
	int			fd;
	int			ret;

	ret = 0;
	if (ac != 2 || !av[0])
		ft_usage();
	if ((fd = open(av[1], O_RDONLY)) >= 0)
		return (fillit(fd, ret));
	else
		ft_error();
	return (0);
}
