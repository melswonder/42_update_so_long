/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:24:05 by hirwatan          #+#    #+#             */
/*   Updated: 2025/01/09 20:34:17 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	save_mapsize(int fd, t_map *m)
{
	char	*line;

	line = ft_readline(fd);
	while (line != NULL)
	{
		if (m->height == 0)
			m->width = ft_strlen(line);
		m->height++;
		free(line);
		line = ft_readline(fd);
	}
}

int c_wall_error(t_map *m)
{
	int x;
	int y;
	y = 0;
	x = 0;
	while (y < m->height)
	{
		x = 0;
		while (x < m->width)
		{
			if(m->map[y][x] == 'C')
			{
				if(m->map[y - 1][x] == '1')
					if(m->map[y + 1][x] == '1')
						if(m->map[y][x - 1] == '1')
							if(m->map[y][x + 1] == '1')
								return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	**initialize_visited(t_map *m)
{
	int	**visited;
	int	i;

	visited = (int **)malloc(sizeof(int *) * m->height);
	if (!visited)
		return (write(1, "Error\n", 6), NULL);
	i = 0;
	while (i < m->height)
	{
		visited[i] = (int *)malloc(sizeof(int) * m->width);
		if (!visited[i])
		{
			visited_error_free(visited, i);
			return (NULL);
		}
		memset(visited[i], 0, sizeof(int) * m->width);
		i++;
	}
	return (visited);
}

int	check_errors_find_p(t_map *m)
{
	int	y;
	int	x;

	if (!check_rectangle(m) || !check_collection(m))
		return (0);
	y = 0;
	while (y < m->height)
	{
		x = 0;
		while (x < m->width)
		{
			if (m->map[y][x] == 'P')
			{
				m->start_y = y;
				m->start_x = x;
				m->map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	check_valid_map(t_map *m)
{
	int	fd;
	int	**visited;
	int	reachable;

	fd = open_file("maps/date");
	if (fd < 0)
		return (0);
	map_new(m);
	save_mapsize(fd, m);
	if (!allocate_memory(m))
		return (close(fd), 0);
	if (!reopen_file("maps/date", &fd))
		return (free(m->map), 0);
	load_map(m, fd);
	close(fd);
	visited = initialize_visited(m);
	if (check_errors_find_p(m) == 0 || !visited)
		return (put_error_map_delete(m), 0);
	m->collected = 0;
	reachable = backtrack(m, m->start_x, m->start_y, visited);
	if (!reachable || m->collected != m->total_c)
		return (write(1, "Error\n", 6), cleanup(m, visited), 0);
	free_visited(visited,m->height);
	return (1);
}
