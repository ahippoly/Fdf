/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:15:27 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/10 01:17:19 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_event(int button, int x, int y, t_ptr *p)
{
	t_pos pos1;
	t_pos pos2;

	if (button == 1)
	{
		p->pos1.x = x;
		p->pos1.y = y;
	}
	else if (button == 2)
	{
		p->pos2.x = x;
		p->pos2.y = y;
	}
	if (p->pos2.x && p->pos2.y && p->pos1.x && p->pos1.y)
	{
		octant(p->pos1, p->pos2, p);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
		p->pos1.x = 0;
		p->pos1.y = 0;
		p->pos2.x = 0;
		p->pos2.y = 0;
	}
	return (0);
}

int		key_event(int key, t_ptr *param)
{
	int i;

	i = 0;
	param->key = key;
	printf("key = %i\n", key);
	if (key == 19)
	{
		param->z_len = 0;
		param->x_len = 0;
		param->coef_z = 0;
	}
	else if (key == 8)
		clear_window(param);
	else if (param->key == 18)
		param->zoom = 1;
	else if (param->key == 20)
		param->type++;
	return (0);
}

void	anim2(t_ptr *param)
{
	if (param->key == KEY_A)
		param->coef_z += 0.008;
	else if (param->key == KEY_E)
		param->coef_z -= 0.008;
	else if (param->key == KEY_V)
		param->y_len -= 0.1;
	else if (param->key == KEY_B)
		param->y_len += 0.1;
	else if (param->key == KEY_W)
		param->zoom -= 0.01;
	else if (param->key == KEY_X)
		param->zoom += 0.01;
	else if (param->key == KEY_RIGHT)
		param->x_len -= 0.01;
	else if (param->key == KEY_LEFT)
		param->x_len += 0.01;
}

int		anim(t_ptr *param)
{
	if (param->key != -1)
	{
		if (param->key == KEY_UP)
			param->z_len += 0.01;
		else if (param->key == KEY_DOWN)
			param->z_len -= 0.01;
		else if (param->key == KEY_Z)
			param->start_y -= 3;
		else if (param->key == KEY_Q)
			param->start_x -= 3;
		else if (param->key == KEY_S)
			param->start_y += 3;
		else if (param->key == KEY_D)
			param->start_x += 3;
		else
			anim2(param);
		redraw(param);
	}
	return (0);
}

int		key_release(int key, t_ptr *param)
{
	printf("key = %i\n", key);
	if ((key >= 83 && key <= 88) || key == KEY_ESCAPE)
	{
		if (key == KEY_ESCAPE)
			exit(0);
		else if (param->key == 83)
			param->coef_z -= 0.5;
		else if (param->key == 85)
			param->coef_z += 0.5;
		else if (param->key == 84)
			param->z_len -= 0.5;
		else if (param->key == 87)
			param->z_len += 0.5;
		else if (param->key == 86)
			param->x_len -= 0.5;
		else if (param->key == 88)
			param->x_len += 0.5;
	}
	else
		param->key = -1;
	return (0);
}
