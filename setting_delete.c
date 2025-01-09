/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:47:39 by hirwatan          #+#    #+#             */
/*   Updated: 2025/01/09 21:25:38 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setting_delete(t_setting *sg)
{
	int	i;

	if (sg->m && sg->m->map)
	{
		i = 0;
		while (i < sg->m->height)
			free(sg->m->map[i++]);
		free(sg->m->map);
		free(sg->m);
	}
	if (img_delete(sg))
	{
		mlx_destroy_window(sg->mlx, sg->mlx_win);
		mlx_destroy_display(sg->mlx);
		free(sg->mlx);
		free(sg);
	}
}

int	img_delete(t_setting *sg)
{
	if (!sg)
		return (0);
    if (sg->buck_img && sg->buck_img->img)
        mlx_destroy_image(sg->mlx, sg->buck_img->img);
    free(sg->buck_img);
    if (sg->chara_img && sg->chara_img->img)
        mlx_destroy_image(sg->mlx, sg->chara_img->img);
    free(sg->chara_img);
	if(sg->wall_img && sg->wall_img->img)
	mlx_destroy_image(sg->mlx, sg->wall_img->img);
	free(sg->wall_img);
	if(sg->coin_img && sg->coin_img->img)
	mlx_destroy_image(sg->mlx, sg->coin_img->img);
	free(sg->coin_img);
	if(sg->exit_img && sg->exit_img->img)	
	mlx_destroy_image(sg->mlx, sg->exit_img->img);
	free(sg->exit_img);
	return (1);
}
