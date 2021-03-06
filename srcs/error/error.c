/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:48:56 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/29 16:48:57 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void					error_input(void)
{
	ft_putendl_fd("./wolf3d: Wrong input", 2);
	ft_putendl_fd("usage: ./wolf3d 'map' OR 'size != 0'", 2);
	exit(0);
}

void					error_open(void)
{
	ft_putendl_fd("./wolf3d: open fail!", 2);
	exit(0);
}

void					error_file(int error)
{
	if (error == 2)
		ft_putendl_fd("./wolf3d: nbcol/nrow are not the same!", 2);
	else if (error == 1)
		ft_putendl_fd("./wolf3d: wrong char in the file!", 2);
	else if (error == 3)
		ft_putendl_fd("./wolf3d: No starting space available!", 2);
	else if (error == 3)
		ft_putendl_fd("./wolf3d: File is not valid!", 2);
	exit(0);
}

void					error_malloc(void)
{
	ft_putendl_fd("./wolf3d: malloc error", 2);
	exit(0);
}
