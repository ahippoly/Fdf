/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:08:55 by ahippoly          #+#    #+#             */
/*   Updated: 2019/02/18 05:47:05 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_window(t_ptr *param)
{
	int bpp;
	int size_line;
	int endian;
	int i;
	int end;

	mlx_destroy_image(param->mlx_ptr, param->img_ptr);
	param->img_ptr = mlx_new_image(param->mlx_ptr, WIN_SIZE, WIN_SIZE);
	param->img_data = mlx_get_data_addr(param->img_ptr, &bpp,
								&size_line, &endian);
}

int		redraw(t_ptr *param)
{
	clear_window(param);
	if (param->type % 2 == 0)
		disp_map(param);
	else
		disp_parallel(param);
	return (0);
}

void	draw1(t_pos i, t_ptr *ptr)
{
	t_pos pos1;
	t_pos pos2;

	ptr->y1 = ptr->tab[i.y][i.x];
	ptr->y2 = ptr->tab[i.y][i.x + 1];
	pos1.x = calc_x(i.x, i.y, ptr);
	pos1.y = calc_y(i.x, i.y, ptr);
	pos2.x = calc_x(i.x + 1, i.y, ptr);
	pos2.y = calc_y(i.x + 1, i.y, ptr);
	octant(pos1, pos2, ptr);
}

void	draw2(t_pos i, t_ptr *ptr)
{
	t_pos pos1;
	t_pos pos2;

	ptr->y1 = ptr->tab[i.y][i.x];
	ptr->y2 = ptr->tab[i.y + 1][i.x];
	pos1.x = calc_x(i.x, i.y, ptr);
	pos1.y = calc_y(i.x, i.y, ptr);
	pos2.x = calc_x(i.x, i.y + 1, ptr);
	pos2.y = calc_y(i.x, i.y + 1, ptr);
	octant(pos1, pos2, ptr);
}

void	disp_map(t_ptr *ptr)
{
	t_pos pos1;
	t_pos pos2;
	t_pos i;

	i.y = 0;
	while (i.y < ptr->nb_line)
	{
		i.x = 0;
		while (i.x < ptr->size_line)
		{
			if (i.x < ptr->size_line - 1)
				draw1(i, ptr);
			if (i.y < ptr->nb_line - 1)
				draw2(i, ptr);
			i.x++;
		}
		i.y++;
	}
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
}
