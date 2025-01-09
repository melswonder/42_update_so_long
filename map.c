/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:26:12 by hirwatan          #+#    #+#             */
/*   Updated: 2025/01/09 22:17:47 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_readline(int fd)
{
	int		buf_size;
	char	*buf;
	int		i;
	int		bytes;

	buf_size = 128;
	buf = malloc(buf_size);
	if (!buf)
		return (NULL);
	i = 0;
	char c = 0;
	while ((bytes = read(fd, &c, 1)) > 0)
	{
		if (c == '\n')
			break ;
		buf[i++] = c;
		if (i == buf_size - 1)
		{
			buf_size *= 2;
			buf = realloc(buf, buf_size);
			if (!buf)
				return (NULL);
		}
	}
	if (i == 0 && bytes <= 0)
		return (free(buf), NULL);
	buf[i] = '\0';
	return (buf);
}

int	check_rectangle(t_map *m)
{
	int	y;
	int	x;

	y = 0;
	while (y < m->height)
	{
		if (ft_strlen(m->map[y]) != m->width)
			return (0);
		y++;
	}
	x = 0;
	while (x < m->width)
	{
		if (m->map[0][x] != '1' || m->map[m->height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < m->height)
	{
		if (m->map[y][0] != '1' || m->map[y][m->width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_collection(t_map *m)
{
	int	y;
	int	x;

	y = 0;
	while (y < m->height)
	{
		x = 0;
		while (x < m->width)
		{
			if (m->map[y][x] == 'P')
				m->count_p++;
			else if (m->map[y][x] == 'C')
				m->total_c++;
			else if (m->map[y][x] == 'E')
				m->count_e++;
			else if (m->map[y][x] != '0' && m->map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	if (m->count_p != 1 || m->total_c < 1 || m->count_e != 1)
		return (0);
	return (1);
}
