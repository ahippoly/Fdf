/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 04:41:58 by ahippoly          #+#    #+#             */
/*   Updated: 2019/02/18 05:53:05 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		calc_x2(int x, int y, t_ptr *p)
{
	return (p->start_x
			+ (x * p->coef_x
			+ (p->tab[y][x] * p->y_len)) * p->zoom);
}

int		calc_y2(int x, int y, t_ptr *p)
{
	return (p->start_y
			+ (y * p->coef_x
			- p->tab[y][x] * p->y_len) * p->zoom);
}

void	draw3(t_pos i, t_ptr *ptr)
{
	t_pos pos1;
	t_pos pos2;

	ptr->y1 = ptr->tab[i.y][i.x];
	ptr->y2 = ptr->tab[i.y][i.x + 1];
	pos1.x = calc_x2(i.x, i.y, ptr);
	pos1.y = calc_y2(i.x, i.y, ptr);
	pos2.x = calc_x2(i.x + 1, i.y, ptr);
	pos2.y = calc_y2(i.x + 1, i.y, ptr);
	octant(pos1, pos2, ptr);
}

void	draw4(t_pos i, t_ptr *ptr)
{
	t_pos pos1;
	t_pos pos2;

	ptr->y1 = ptr->tab[i.y][i.x];
	ptr->y2 = ptr->tab[i.y + 1][i.x];
	pos1.x = calc_x2(i.x, i.y, ptr);
	pos1.y = calc_y2(i.x, i.y, ptr);
	pos2.x = calc_x2(i.x, i.y + 1, ptr);
	pos2.y = calc_y2(i.x, i.y + 1, ptr);
	octant(pos1, pos2, ptr);
}

void	disp_parallel(t_ptr *ptr)
{
	t_pos i;

	i.y = 0;
	while (i.y < ptr->nb_line)
	{
		i.x = 0;
		while (i.x < ptr->size_line)
		{
			if (i.x < ptr->size_line - 1)
				draw3(i, ptr);
			if (i.y < ptr->nb_line - 1)
				draw4(i, ptr);
			i.x++;
		}
		i.y++;
	}
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
}
