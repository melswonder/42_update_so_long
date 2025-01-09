/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:06:58 by hirwatan          #+#    #+#             */
/*   Updated: 2025/01/09 21:42:00 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key_event(int keycode, void *param)
{
	t_setting	*sg;
	static int	count_c = 0;

	sg = (t_setting *)param;
	if (keycode == ESC_KEY)
	{
		setting_delete(sg);
		exit(0);
	}
	if (0 != map_move(keycode, sg))
		printf("move_count = %d\n", sg->move);
	if (sg->m->map[sg->chara_img->x][sg->chara_img->y] == 'C')
	{
		sg->m->map[sg->chara_img->x][sg->chara_img->y] = '0';
		count_c++;
	}
	if (sg->m->total_c == count_c
		&& sg->m->map[sg->chara_img->x][sg->chara_img->y] == 'E')
	{
		setting_delete(sg);
		exit(0);
	}
	mlx_clear_window(sg->mlx, sg->mlx_win);
	put_all_xpm(sg);
	return (0);
}

int	map_move(int keycode, t_setting *sg)
{
	if (keycode == A_KEY || keycode == LEFT_KEY || keycode == Q_KEY)
	{
		if (sg->m->map[sg->chara_img->x][sg->chara_img->y - 1] != '1')
			return (sg->chara_img->y--, sg->move++, 1);
	}
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
	{
		if (sg->m->map[sg->chara_img->x][sg->chara_img->y + 1] != '1')
			return (sg->chara_img->y++, sg->move++, 1);
	}
	else if (keycode == W_KEY || keycode == UP_KEY || keycode == Z_KEY)
	{
		if (sg->m->map[sg->chara_img->x - 1][sg->chara_img->y] != '1')
			return (sg->chara_img->x--, sg->move++, 1);
	}
	else if (keycode == S_KEY || keycode == DOWN_KEY)
	{
		if (sg->m->map[sg->chara_img->x + 1][sg->chara_img->y] != '1')
			return (sg->chara_img->x++, sg->move++, 1);
	}
	return (0);
}

int	main(void)
{
	t_setting	*sg;
	int			ret;

	sg = (t_setting *)malloc(sizeof(t_setting));
	if (!sg)
		return (1);
	sg->m = NULL;
	sg->mlx = NULL;
	sg->mlx_win = NULL;
	sg->m = (t_map *)malloc(sizeof(t_map));
	if (!sg->m)
		return (free(sg), 1);
	ret = check_valid_map(sg->m);
	if (ret == 0)
		return (free(sg->m), free(sg), 0);
	sg = setting_new(sg);
	if (sg == NULL)
		return (0);
	setup_map_environment(sg);
	mlx_hook(sg->mlx_win, 2, 1L << 0, handle_key_event, sg);
	put_all_xpm(sg);
	mlx_loop(sg->mlx);
	setting_delete(sg);
	return (0);
}
