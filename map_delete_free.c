/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_delete_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:33:31 by hirwatan          #+#    #+#             */
/*   Updated: 2025/01/09 20:45:37 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	visited_error_free(int **visited, int i)
{
	int	j;

	j = 0;
	write(1, "Error\n", 6);
	while (j < i)
	{
		free(visited[j]);
		j++;
	}
	free(visited);
}

void	put_error_map_delete(t_map *m)
{
	int	i;

	write(1, "Error\n", 6);
	if (m->map)
	{
		i = 0;
		while (i < m->height)
		{
			free(m->map[i]);
			i++;
		}
		free(m->map);
	}
}

void	cleanup(t_map *m, int **visited)
{
	int	i;

	i = 0;
	while (i < m->height)
	{
		free(visited[i]);
		free(m->map[i]);
		i++;
	}
	free(visited);
	free(m->map);
}

void	free_visited(int **visited, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}
