/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 15:12:36 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/30 15:12:44 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <fcntl.h>

static void				print_map(t_data *d)
{
	int					i;
	int					j;

	i = 0;
	while (i < d->ncol)
	{
		j = 0;
		while (j < d->ncol)
		{
			ft_printf("%d ", d->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

static void				get_nbrs(char *line, t_data *d)
{
	int					i;
	char				*tmp_line;

	i = 0;
	tmp_line = line;
	while (i < d->ncol)
	{
		while (*tmp_line == ' ' && *tmp_line)
			tmp_line++;
		d->map[d->nrow][i] = (ft_atoi(tmp_line));
		while (ft_isdigit(*tmp_line))
			tmp_line++;
		i++;
	}
	free(line);
}

static int				check_line(char *line, t_data *d)
{
	int					i;

	i = 0;
	if (((int)ft_nb_words(line, ' ') != d->ncol))
		return (2);
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\n' || line[i] == '-')
			i++;
		else if (!ft_isdigit(line[i]))
			return (1);
		i++;
	}
	return (0);
}

static void				malloc_map(t_data *d, int ncol)
{
	int					it;

	d->map = (int **)malloc(sizeof(int *) * ncol);
	if (!d->map)
		error_malloc();
	it = 0;
	while (it < ncol)
	{
		d->map[it] = (int *)malloc(sizeof(int) * ncol);
		if (!d->map[it])
			error_malloc();
		it++;
	}
	d->flag = 1;
}

void					get_map(char *av, t_data *d)
{
	int					fd;
	char				*line;
	int					ret;

	if ((fd = open(av, O_RDONLY)) == -1)
		error_open();
	while ((ret = get_next_line(fd, &line) > 0))
	{
		if (d->nrow == 0)
			d->ncol = ft_nb_words(line, ' ');
		if (d->flag == 0)
			malloc_map(d, d->ncol);
		if ((ret = check_line(line, d)))
			error_file(ret);
		get_nbrs(line, d);
		d->nrow++;
	}
	close(fd);
	print_map(d);
}
