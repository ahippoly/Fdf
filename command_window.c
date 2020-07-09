/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:02:05 by ahippoly          #+#    #+#             */
/*   Updated: 2019/02/26 14:20:26 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	part2(void *win, t_ptr *ptr)
{
	mlx_string_put(ptr->mlx_ptr, win, 63, 111, 0xff0000, "_________");
	mlx_string_put(ptr->mlx_ptr, win, 68, 111, 0xff0000, "________");
	mlx_string_put(ptr->mlx_ptr, win, 63, 110, 0xffffff, "Draw line");
	mlx_string_put(ptr->mlx_ptr, win, 13, 134, 0x00ff00,
			"Right Click / Left Click");
	mlx_string_put(ptr->mlx_ptr, win, 320, 111, 0xff0000, "___________");
	mlx_string_put(ptr->mlx_ptr, win, 325, 111, 0xff0000, "__________");
	mlx_string_put(ptr->mlx_ptr, win, 320, 110, 0xffffff, "Rotate +0.5");
	mlx_string_put(ptr->mlx_ptr, win, 300, 130, 0x00ff00, "Numpad  5");
	mlx_string_put(ptr->mlx_ptr, win, 300, 150, 0x00ff00, "      1 2 3");
	mlx_string_put(ptr->mlx_ptr, win, 20, 181, 0xff0000, "____");
	mlx_string_put(ptr->mlx_ptr, win, 25, 181, 0xff0000, "___");
	mlx_string_put(ptr->mlx_ptr, win, 20, 180, 0xffffff, "Quit");
	mlx_string_put(ptr->mlx_ptr, win, 22, 200, 0x00ff00, "Esc");
	mlx_string_put(ptr->mlx_ptr, win, 100, 181, 0xff0000, "___________");
	mlx_string_put(ptr->mlx_ptr, win, 105, 181, 0xff0000, "__________");
	mlx_string_put(ptr->mlx_ptr, win, 100, 180, 0xffffff, "Clear lines");
	mlx_string_put(ptr->mlx_ptr, win, 113, 200, 0x00ff00, "Any key");
}

void	part3(void *win, t_ptr *ptr)
{
	mlx_string_put(ptr->mlx_ptr, win, 300, 181, 0xff0000, "______________");
	mlx_string_put(ptr->mlx_ptr, win, 305, 181, 0xff0000, "_____________");
	mlx_string_put(ptr->mlx_ptr, win, 300, 180, 0xffffff, "Reset Rotation");
	mlx_string_put(ptr->mlx_ptr, win, 360, 200, 0x00ff00, "2");
}

void	command_window(t_ptr *ptr)
{
	void *win;

	win = mlx_new_window(ptr->mlx_ptr, 500, 500, "tableau de bord");
	mlx_string_put(ptr->mlx_ptr, win, 13, 21, 0xff0000, "____");
	mlx_string_put(ptr->mlx_ptr, win, 20, 21, 0xff0000, "___");
	mlx_string_put(ptr->mlx_ptr, win, 13, 20, 0xffffff, "Move");
	mlx_string_put(ptr->mlx_ptr, win, 10, 50, 0x00ff00, "  W");
	mlx_string_put(ptr->mlx_ptr, win, 10, 70, 0x00ff00, "A S D");
	mlx_string_put(ptr->mlx_ptr, win, 95, 21, 0xff0000, "______");
	mlx_string_put(ptr->mlx_ptr, win, 100, 21, 0xff0000, "_____");
	mlx_string_put(ptr->mlx_ptr, win, 95, 20, 0xffffff, "Rotate");
	mlx_string_put(ptr->mlx_ptr, win, 90, 52, 0x00ff00, " Q ^ E");
	mlx_string_put(ptr->mlx_ptr, win, 90, 70, 0x00ff00, "<- v ->");
	mlx_string_put(ptr->mlx_ptr, win, 190, 21, 0xff0000, "____");
	mlx_string_put(ptr->mlx_ptr, win, 195, 21, 0xff0000, "___");
	mlx_string_put(ptr->mlx_ptr, win, 190, 20, 0xffffff, "Zoom");
	mlx_string_put(ptr->mlx_ptr, win, 185, 52, 0x00ff00, "-Z +X");
	mlx_string_put(ptr->mlx_ptr, win, 270, 21, 0xff0000, "_____________");
	mlx_string_put(ptr->mlx_ptr, win, 275, 21, 0xff0000, "____________");
	mlx_string_put(ptr->mlx_ptr, win, 270, 20, 0xffffff, "Change Height");
	mlx_string_put(ptr->mlx_ptr, win, 280, 50, 0x00ff00, "   -V +B");
	part2(win, ptr);
	part3(win, ptr);
}
