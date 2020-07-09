/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:46:54 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/10 00:46:15 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibX/mlx.h"
#include "fdf.h"
#include <math.h>

void	coef_calculation(t_ptr *ptr)
{
	float coef_x;
	float scale;

	if (ptr->nb_line < ptr->size_line * 2)
	{
		scale = 2 - ((float)ptr->nb_line / (float)ptr->size_line);
		coef_x = ((float)WIN_SIZE / (((float)ptr->size_line - 1) * 2)) * scale;
	}
	else
	{
		scale = 2 - ((float)ptr->size_line / (float)ptr->nb_line);
		coef_x = (((float)WIN_SIZE / (((float)ptr->nb_line - 1) * 2)) * scale);
	}
	ptr->coef_x = coef_x;
	ptr->scale = scale;
}

int		foretdeif(char *map_string, int *i)
{
	int color;

	color = 0;
	while (map_string[++*i] != 0)
	{
		if (map_string[*i] >= 'A' && map_string[*i] <= 'F')
			color = color * 16 + (map_string[*i] - 55);
		else if (map_string[*i] >= 'a' && map_string[*i] <= 'f')
			color = color * 16 + (map_string[*i] - 55);
		else if (map_string[*i] >= '0' && map_string[*i] <= '9')
			color = color * 16 + (map_string[*i] - 48);
		else
			break ;
	}
	return (color);
}

int		load_color(int **color, char *map_string, int line, int number)
{
	int i;

	i = 0;
	if (map_string[i] == ',')
	{
		if (map_string[++i] == '0')
			if (map_string[++i] == 'x')
				color[line][number] = foretdeif(map_string, &i);
			else
				color[line][number] = 0;
		else
			while (map_string[i] >= '0' && map_string[i] <= '9')
				color[line][number] = color[line][number] * 10
					+ (map_string[i++] - 48);
		while (map_string[i] != ' ' && map_string[i] != '\n' && map_string[i])
			i++;
	}
	else
		color[line][number] = -1;
	while (map_string[i] == ' ')
		i++;
	return (i);
}

void	var_ini(t_ptr *ptr)
{
	int bpp;
	int sl;
	int endian;

	ptr->pos1.x = 0;
	ptr->pos1.y = 0;
	ptr->pos2.x = 0;
	ptr->pos2.y = 0;
	ptr->y_max = 0;
	ptr->nb_line = 0;
	ptr->winx = WIN_SIZE;
	ptr->winy = WIN_SIZE;
	ptr->key = -1;
	ptr->start_x = 0;
	ptr->start_y = WIN_SIZE / 2;
	ptr->z_len = 0.5;
	ptr->x_len = 0;
	ptr->coef_z = 0.5;
	ptr->y_len = 10;
	ptr->zoom = 1;
	ptr->type = 0;
	ptr->img_ptr = mlx_new_image(ptr->mlx_ptr, WIN_SIZE, WIN_SIZE);
	ptr->img_data = mlx_get_data_addr(ptr->img_ptr, &bpp, &sl, &endian);
}

int		main(int ac, char **av)
{
	t_ptr	ptr;
	int		i;
	int		current_line;
	char	*map_string;

	i = 0;
	ptr.mlx_ptr = mlx_init();
	var_ini(&ptr);
	ptr.tab = readfile(av[1], &ptr);
	command_window(&ptr);
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, WIN_SIZE,
							WIN_SIZE, "FDF");
	coef_calculation(&ptr);
	disp_map(&ptr);
	mlx_do_key_autorepeaton(ptr.mlx_ptr);
	mlx_mouse_hook(ptr.win_ptr, mouse_event, &ptr);
	mlx_hook(ptr.win_ptr, 2, 1, key_event, &ptr);
	mlx_hook(ptr.win_ptr, 3, 2, key_release, &ptr);
	mlx_loop_hook(ptr.mlx_ptr, anim, &ptr);
	mlx_loop(ptr.mlx_ptr);
}
