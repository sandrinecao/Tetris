/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scao <scao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:43:42 by scao              #+#    #+#             */
/*   Updated: 2019/03/08 08:23:53 by scao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_hello
{
	int			i;
	int			j;
}				t_hello;

void			solve(char **shapes, int shapecount);
int				checkshape(char *block);
int				checkmap(char *block);
int				is_input_valid(char *buff);
char			**make2darray(char *buff, int *count, char **newarray);
void			ft_error(void);
void			check_j(int j);
void			ft_usage(void);
void			delsplit(char ***split);

#endif
