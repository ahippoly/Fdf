/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:02:22 by ahippoly          #+#    #+#             */
/*   Updated: 2019/02/05 16:49:28 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	oct_ini(t_oct *oct, t_pos pos1, t_pos pos2, int pos[2][2])
{
	pos[0][0] = pos1.x;
	pos[0][1] = pos2.x;
	pos[1][0] = pos1.y;
	pos[1][1] = pos2.y;
	oct->inc[0] = pos2.x - pos1.x > 0 ? 1 : -1;
	oct->inc[1] = pos2.y - pos1.y > 0 ? 1 : -1;
	oct->d[0] = (pos2.x - pos1.x) * 2 * oct->inc[0];
	oct->d[1] = (pos2.y - pos1.y) * 2 * oct->inc[1];
	oct->bool = oct->d[0] > oct->d[1] ? 1 : 0;
	oct->e = oct->d[1 - oct->bool] / 2;
	oct->ecart = (pos[1 - oct->bool][1] - pos[1 - oct->bool][0])
		* oct->inc[1 - oct->bool];
}

void	octant(t_pos pos1, t_pos pos2, t_ptr *p)
{
	t_oct	oct;
	int		pos[2][2];
	float	i;

	i = 0;
	oct_ini(&oct, pos1, pos2, pos);
	while (pos[1 - oct.bool][0] != pos[1 - oct.bool][1])
	{
		if (pos[0][0] < WIN_SIZE && pos[0][0] > 0 && pos[1][0] > 0
			&& pos[1][0] < WIN_SIZE)
		{
			p->img_data[2 + (pos[0][0] + pos[1][0] * WIN_SIZE) * 4] = (float)255
				* fabs((p->y1 + (p->y2 - p->y1) * (i / oct.ecart)) / p->y_max);
			p->img_data[1 + (pos[0][0] + pos[1][0] * WIN_SIZE) * 4] = (char)127;
		}
		if ((oct.e -= oct.d[oct.bool]) <= 0)
		{
			pos[oct.bool][0] += oct.inc[oct.bool];
			oct.e += oct.d[1 - oct.bool];
		}
		i++;
		pos[1 - oct.bool][0] += oct.inc[1 - oct.bool];
	}
}

int		calc_x(int x, int y, t_ptr *p)
{
	return (p->start_x
		+ ((y * sin(p->coef_z * M_PI_2) * cos(p->x_len * M_PI_2)
		+ x * (cos(p->coef_z * M_PI_2) * cos(p->x_len * M_PI_2))) * p->coef_x
		- (p->tab[y][x] * p->y_len * sin(M_PI_2 * p->x_len))) * p->zoom);
}

int		calc_y(int x, int y, t_ptr *p)
{
	return (p->start_y
	+ (cos(p->coef_z * M_PI_2) * cos(p->z_len * M_PI_2) * y
	- (sin(p->coef_z * M_PI_2) * cos(p->z_len * M_PI_2) * x)
	- x * sin(p->x_len * M_PI_2) * sin(p->z_len * M_PI_2)
		* cos(p->coef_z * M_PI_2)
	- y * sin(p->x_len * M_PI_2) * sin(p->z_len * M_PI_2)
		* sin(p->coef_z * M_PI_2)) * (p->coef_x * p->zoom)
	- ((p->tab[y][x] * p->y_len * sin(p->z_len * M_PI_2)
		* cos(p->x_len * M_PI_2))) * p->zoom);
}
