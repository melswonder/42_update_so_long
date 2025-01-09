/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:24:42 by hirwatan          #+#    #+#             */
/*   Updated: 2025/01/09 20:31:33 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_new(t_map *m)
{
	if (m == NULL)
	{
		free(m);
		return ;
	}
	m->map = NULL;
	m->height = 0;
	m->width = 0;
	m->total_c = 0;
	m->count_p = 0;
	m->count_e = 0;
	m->collected = 0;
	m->start_x = 0;
	m->start_y = 0;
}

int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
	}
	return (fd);
}

int	reopen_file(const char *filename, int *fd)
{
	close(*fd);
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	allocate_memory(t_map *m)
{
	int	i;

	i = 0;
	m->map = (char **)malloc(sizeof(char *) * m->height);
	if (!m->map)
		return (write(1, "Error\n", 6), 0);
	while (i < m->height)
	{
		m->map[i] = NULL;
		i++;
	}
	return (1);
}

void	load_map(t_map *m, int fd)
{
	char	*line;
	int		row;

	row = 0;
	line = ft_readline(fd);
	while (line != NULL)
	{
		if (row >= m->height)
		{
			free(line);
			break ;
		}
		m->map[row] = line;
		row++;
		line = ft_readline(fd);
	}
}
