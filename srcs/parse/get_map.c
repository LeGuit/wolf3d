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

static void				read_map_info(int fd, t_data *d)
{
	char				*line;

	get_next_line(fd, &line);
	d->nrow = ft_atoi(line);
	d->ncol = ft_atoi(ft_strchr(line, ' '));
	free(line);
}

static void				get_nbrs(char *line, t_data *d, int currow)
{
	int					i;
	char				*tmp_line;

	i = 0;
	tmp_line = line;
	while (i < d->ncol)
	{
		while (*tmp_line == ' ' && *tmp_line)
			tmp_line++;
		d->map[currow][i] = (ft_atoi(tmp_line));
		while (ft_isdigit(*tmp_line))
			tmp_line++;
		i++;
	}
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

void					malloc_map(t_data *d, int nrow, int ncol)
{
	int					it;

	d->map = (int **)malloc(sizeof(int *) * nrow);
	if (!d->map)
		error_malloc();
	it = 0;
	while (it < nrow)
	{
		d->map[it] = (int *)malloc(sizeof(int) * ncol);
		if (!d->map[it])
			error_malloc();
		it++;
	}
}

void					get_map(char *av, t_data *d)
{
	int					fd;
	char				*line;
	int					ret;
	int					currow;

	if ((fd = open(av, O_RDONLY)) == -1)
		rand_map(av, d);
	else
	{
		read_map_info(fd, d);
		malloc_map(d, d->nrow, d->ncol);
		currow = 0;
		while ((ret = get_next_line(fd, &line) > 0))
		{
			if ((ret = check_line(line, d)))
				error_file(ret);
			get_nbrs(line, d, currow);
			free(line);
			currow++;
		}
		if (currow != d->nrow)
			error_file(2);
		close(fd);
	}
}
