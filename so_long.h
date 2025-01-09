/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:46:00 by hirwatan          #+#    #+#             */
/*   Updated: 2025/01/09 21:52:12 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <X11/Xlib.h>
# include <X11/extensions/XShm.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <unistd.h>

# define X_MAX 1920
# define Y_MAX 1200

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define Q_KEY 113
# define Z_KEY 122
# define LEFT_KEY 65361
# define UP_KEY 65362
# define RIGHT_KEY 65363
# define DOWN_KEY 65364
# define ESC_KEY 65307

typedef struct i_data
{
	void		*img;
	int			x;
	int			y;
	int			width;
	int			height;
}				t_img_data;

typedef struct s_map
{
	char		**map;
	int			height;
	int			width;
	int			total_c;
	int			count_p;
	int			count_e;
	int			collected;
	int			start_x;
	int			start_y;
}				t_map;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			move;
	t_map		*m;
	t_img_data	*buck_img;
	t_img_data	*chara_img;
	t_img_data	*wall_img;
	t_img_data	*coin_img;
	t_img_data	*exit_img;
}				t_setting;

typedef struct s_read
{
	char		buf[2];
	char		*line;
	int			ret;
	int			len;
	char		*new_line;
	int			i;
}				t_read;

typedef struct s_host_information
{
	int			move_count;
}				t_host_info;

t_setting		*setting_new(t_setting *sg);
t_setting		*all_img_coordinate_new(t_setting *sg);
void			setup_map_environment(t_setting *sg);
void			setting_delete(t_setting *sg);
int				img_delete(t_setting *sg);
void			put_all_xpm(t_setting *sg);
void			map_info_put(t_setting *sg);
int				check_collection(t_map *m);
int				check_rectangle(t_map *m);
void			save_mapsize(int fd, t_map *m);
void			map_new(t_map *m);
int				open_file(const char *filename);
int				reopen_file(const char *filename, int *fd);
int				allocate_memory(t_map *m);
void			load_map(t_map *m, int fd);
void			visited_error_free(int **visited, int i);
void			put_error_map_delete(t_map *m);
void			cleanup(t_map *m, int **visited);
void			free_visited(int **visited, int height);
int				check_valid_map(t_map *m);
int				check_errors_find_p(t_map *m);
int				**initialize_visited(t_map *m);
int				c_wall_error(t_map *m);
void			save_mapsize(int fd, t_map *m);
void			check_direction(int x, int y, int i, int coords[2]);
int				is_valid(t_map *m, int x, int y, int **visited);
int				backtrack(t_map *m, int x, int y, int **visited);
int				map_move(int keycode, t_setting *sg);
char			*ft_readline(int fd);
int				ft_strlen(const char *str);
#endif
