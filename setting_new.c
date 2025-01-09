/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:46:04 by hirwatan          #+#    #+#             */
/*   Updated: 2025/01/09 20:49:03 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_map_environment(t_setting *sg)
{
	if (!sg || !sg->m)
		return ;
	sg->chara_img->y = sg->m->start_x;
	sg->chara_img->x = sg->m->start_y;
}

void	coordinate_img(t_setting *sg)
{
	sg->chara_img->x = 0;
	sg->chara_img->y = 0;
	sg->wall_img->x = 0;
	sg->wall_img->y = 0;
	sg->coin_img->x = 0;
	sg->coin_img->y = 0;
	sg->exit_img->x = 0;
	sg->exit_img->y = 0;
	sg->move = 0;
}
t_setting	*all_img_coordinate_new(t_setting *sg)
{
	sg->chara_img = malloc(sizeof(t_img_data));
	sg->wall_img = malloc(sizeof(t_img_data));
	sg->coin_img = malloc(sizeof(t_img_data));
	sg->exit_img = malloc(sizeof(t_img_data));
	coordinate_img(sg);
	sg->buck_img->img = mlx_xpm_file_to_image(sg->mlx, "xpm/buck.xpm",
			&sg->buck_img->x, &sg->buck_img->y);
	sg->chara_img->img = mlx_xpm_file_to_image(sg->mlx,
			"xpm/main_character.xpm", &sg->chara_img->width,
			&sg->chara_img->height);
	if (!sg->chara_img->img || !sg->buck_img->img)
		return(setting_delete(sg),NULL);
	sg->wall_img->img = mlx_xpm_file_to_image(sg->mlx, "xpm/wall.xpm",
			&sg->wall_img->width, &sg->wall_img->height);
	if (!sg->wall_img->img)
		return(setting_delete(sg),NULL);
	sg->coin_img->img = mlx_xpm_file_to_image(sg->mlx, "xpm/coin.xpm",
			&sg->coin_img->width, &sg->coin_img->height);
	if (!sg->coin_img->img)
		return(setting_delete(sg),NULL);
	sg->exit_img->img = mlx_xpm_file_to_image(sg->mlx, "xpm/exit.xpm",
			&sg->exit_img->width, &sg->exit_img->height);
	if (!sg->exit_img->img)
		return(setting_delete(sg),NULL);
	return (sg);
}

t_setting	*setting_new(t_setting *sg)
{
	sg->mlx = mlx_init();
	if(!sg->mlx)
	{
		free(sg);
		return(NULL);
	}
	sg->mlx_win = mlx_new_window(sg->mlx, X_MAX, Y_MAX, "SO_LONG");
	if(!sg->mlx_win)
	{
		mlx_destroy_display(sg->mlx);
		free(sg->mlx);
		free(sg);
		return(NULL);
	}
	sg->buck_img = malloc(sizeof(t_img_data));
	sg = all_img_coordinate_new(sg);
	if(sg == NULL)
	{
		free(sg);
		return (NULL);
	}
	return (sg);
}
