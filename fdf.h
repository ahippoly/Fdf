/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:05:53 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/10 01:04:55 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_SIZE 1000
# define X_LEN 24
# define Y_LEN 10
# define Z_LEN 2
# define NB_EVENT 5
# define BUFF_SIZE 500


# define KEY_Z 122
# define KEY_S 115
# define KEY_D 100
# define KEY_Q 113

# define KEY_V 118
# define KEY_B 98

# define KEY_W 119
# define KEY_X 120

# define KEY_A 97
# define KEY_E 101
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361

# define KEY_ESCAPE 65307

# define ABS(Value) Value < 0 ? -Value : Value

# include "./libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "minilibX/mlx.h"
# include <math.h>

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_ptr
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data;
	int			winx;
	int			winy;
	int			start_x;
	int			start_y;
	char		refresh;
	float		coef_x;
	float		coef_z;
	float		scale;
	float		x_len;
	float		z_len;
	float		y_len;
	float		zoom;
	int			nb_line;
	int			size_line;
	int			**tab;
	int			i;
	int			key;
	float		y1;
	float		y2;
	float		y_max;
	int			**color;
	t_pos		pos1;
	t_pos		pos2;
	int			type;
}				t_ptr;

typedef struct	s_oct
{
	int			inc[2];
	int			d[2];
	int			e;
	int			bool;
	int			ecart;
}				t_oct;

int				mouse_event(int button, int x, int y, t_ptr *param);
int				key_event(int key, t_ptr *param);
int				anim(t_ptr *param);
int				key_release(int key, t_ptr *param);

void			clear_window(t_ptr *param);
int				redraw(t_ptr *param);
void			disp_map(t_ptr *ptr);
void			disp_parallel(t_ptr *ptr);

void			octant(t_pos pos1, t_pos pos2, t_ptr *param);
int				calc_x(int x, int y, t_ptr *p);
int				calc_y(int x, int y, t_ptr *p);

int				*add_in_tab(int *tab, int new, int size);
int				count_size_line(char *str);
void			read_file(char *map_string, int size_line, t_ptr *ptr);
void			allocate_tab_and_color(char *map_string, t_ptr *ptr);

int				load_color(int **color, char *map_string, int line, int number);
void			errorcase(void);

void			set_var(int *neg, int *tab, int *color);
int				load_number(char *map_string, int *tab, int i);

void			command_window(t_ptr *ptr);

int				**readfile(char *filename, t_ptr *p);
char			*read_map(char *filename);
void			count_size(char *map, int *height, int *length);
int				**alloc_tab(int height, int length);
char			*ft_atoi2(char *str, int *ret);
void			fill_map(char *map, int **tab, t_ptr *p);

#endif
