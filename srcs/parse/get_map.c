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

static void		get_nbrs(char *line, t_data *data)
{
	int			i;
	t_vec3i		v;
	char		*tmp_line;

	i = 0;
	tmp_line = line;
	while (i < data->ncol)
	{
		while (*tmp_line == ' ' && *tmp_line)
			tmp_line++;
		v.pos.x = i;
		v.pos.y = data->nrow;
		v.pos.z = (ft_atoi(tmp_line)) / 10.f;
		ft_vect_push_back(&data->vertices, &v);
		while (ft_isdigit(*tmp_line) || *tmp_line == '-')
			tmp_line++;
		i++;
	}
	free(line);
}

static int		check_line(char *line, t_data *data)
{
	int			i;

	i = 0;
	if (((int)ft_nb_words(line, ' ') != data->ncol))
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

void			get_file(char *av, t_data *data)
{
	int			fd;
	char		*line;
	int			ret;

	if ((fd = open(av, O_RDONLY)) == -1)
		error_open();
	while ((ret = get_next_line(fd, &line) > 0))
	{
		if (data->nrow == 0)
			data->ncol = ft_nb_words(line, ' ');
		data->nrow++;
		if ((ret = check_line(line, data)))
			error_file(ret);
		get_nbrs(line, data);
	}
	close(fd);
}