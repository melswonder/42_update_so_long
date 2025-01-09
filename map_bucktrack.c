/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bucktrack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:35:47 by hirwatan          #+#    #+#             */
/*   Updated: 2025/01/09 20:45:01 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_direction(int x, int y, int i, int coords[2])
{
	if (i == 0)
	{
		coords[0] = x;
		coords[1] = y + 1;
	}
	else if (i == 1)
	{
		coords[0] = x + 1;
		coords[1] = y;
	}
	else if (i == 2)
	{
		coords[0] = x;
		coords[1] = y - 1;
	}
	else
	{
		coords[0] = x - 1;
		coords[1] = y;
	}
}

int	is_valid(t_map *m, int x, int y, int **visited)
{
	if (x >= 0 && x < m->width && y >= 0 && y < m->height)
	{
		if (m->map[y][x] != '1' && visited[y][x] == 0)
			return (1);
	}
	return (0);
}

int	backtrack(t_map *m, int x, int y, int **visited)
{
	int i;
	int coords[2];

	if (m->map[y][x] == 'C')
	{
		if (c_wall_error(m))
			return (0);
		m->collected++;
	}
	if (m->map[y][x] == 'E' && m->collected == m->total_c)
		return (1);
	visited[y][x] = 1;
	i = 0;
	while (i < 4)
	{
		check_direction(x, y, i, coords);
		if (is_valid(m, coords[0], coords[1], visited))
		{
			if (backtrack(m, coords[0], coords[1], visited) == 1)
				return (1);
		}
		i++;
	}
	visited[y][x] = 0;
	return (0);
}
