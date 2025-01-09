/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:23:03 by hirwatan          #+#    #+#             */
/*   Updated: 2025/01/09 20:23:51 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_info_put(t_setting *sg)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= sg->m->height - 1)
	{
		x = 0;
		while (x <= sg->m->width - 1)
		{
			if (sg->m->map[y][x] == '1')
				mlx_put_image_to_window(sg->mlx, sg->mlx_win, sg->wall_img->img,
					x * 64, y * 64);
			if (sg->m->map[y][x] == 'C')
				mlx_put_image_to_window(sg->mlx, sg->mlx_win, sg->coin_img->img,
					x * 64, y * 64);
			if (sg->m->map[y][x] == 'E')
				mlx_put_image_to_window(sg->mlx, sg->mlx_win, sg->exit_img->img,
					x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	put_all_xpm(t_setting *sg)
{
	mlx_put_image_to_window(sg->mlx, sg->mlx_win, sg->buck_img->img, 0, 0);
	map_info_put(sg);
	mlx_put_image_to_window(sg->mlx, sg->mlx_win, sg->chara_img->img,
		sg->chara_img->y * 64, sg->chara_img->x * 64);
}

