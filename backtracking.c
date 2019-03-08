/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scao <scao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:30:13 by scao              #+#    #+#             */
/*   Updated: 2019/03/08 07:58:50 by scao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**emptymap(int const size)
{
	char		**map;
	int			i;
	int			j;

	if (!(map = (char **)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	map[size] = NULL;
	i = -1;
	while (++i < size)
	{
		if (!(map[i] = (char *)ft_memalloc(sizeof(char) * (size + 1))))
			return (NULL);
		map[i][size] = '\0';
	}
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (j < size)
			map[i][j++] = '.';
	}
	return (map);
}

void			rmshape(char **m, char index, int size)
{
	int			i;
	int			j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (m[i][j] == ('A' + index))
				m[i][j] = '.';
			j++;
		}
		i++;
	}
}

int				tryshape(char *sp, char **m, int mc)
{
	int			i;
	int			f;
	int			s;

	f = 0;
	s = ft_strlen(m[0]);
	while (sp[f] == '.')
		f++;
	i = 0;
	while (i < 16)
	{
		if (sp[i] != '.')
			if (mc / s + i / 4 - f / 4 >= s
				|| mc % s + i % 4 - f % 4 >= s
				|| m[mc / s + i / 4 - f / 4][mc % s + i % 4 - f % 4] != '.')
				return (0);
		i++;
	}
	i = -1;
	while (sp[++i])
		if (sp[i] != '.')
			m[mc / s + i / 4 - f / 4][mc % s + i % 4 - f % 4] = sp[i];
	return (1);
}

int				trymap(char **shapes, char **map, int spindex, int spcount)
{
	int			mapcoor;
	int			mapsize;

	mapsize = ft_strlen(map[0]);
	mapcoor = 0;
	while (mapcoor < mapsize * mapsize)
	{
		if (tryshape(shapes[spindex], map, mapcoor) == 1)
		{
			if (spindex == spcount - 1
				|| trymap(shapes, map, spindex + 1, spcount))
				return (1);
			rmshape(map, spindex, mapsize);
		}
		mapcoor++;
	}
	return (0);
}

void			solve(char **shapes, int spcount)
{
	char		**map;
	int			mapsize;
	int			i;

	mapsize = 2;
	while (mapsize * mapsize < spcount * 4)
		mapsize++;
	while (1)
	{
		map = emptymap(mapsize);
		if (trymap(shapes, map, 0, spcount))
			break ;
		delsplit(&map);
		mapsize++;
	}
	i = 0;
	while (map[i])
		ft_putendl(map[i++]);
	delsplit(&map);
}
