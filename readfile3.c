/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:49:39 by ahippoly          #+#    #+#             */
/*   Updated: 2019/02/26 14:03:28 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*read_map(char *filename)
{
	int		fd;
	int		ret;
	char	*map;
	char	buff[BUFF_SIZE + 1];

	if ((fd = open(filename, O_RDONLY)) == -1)
		errorcase();
	if (!(map = (char*)malloc(sizeof(char))))
		errorcase();
	map[0] = '\0';
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = 0;
		if (!(map = ft_strjoinfree(map, buff, 1)))
			errorcase();
	}
	if (ret == -1)
		errorcase();
	return (map);
}

void	count_size(char *map, int *height, int *length)
{
	int length_tmp;
	int i;

	i = 0;
	*length = 2147483647;
	*height = 0;
	while (map[i])
	{
		length_tmp = 0;
		while (map[i] != '\n' && map[i])
		{
			while (map[i] == ' ')
				i++;
			while (map[i] != ' ' && map[i] && map[i] != '\n')
				i++;
			length_tmp++;
			while (map[i] == ' ')
				i++;
		}
		if (length_tmp < *length)
			*length = length_tmp;
		(*height)++;
		map[i] == '\n' ? i++ : i;
	}
}

int		**alloc_tab(int height, int length)
{
	int i;
	int **tab;

	i = 0;
	if (!(tab = (int**)malloc(sizeof(int*) * height)))
		errorcase();
	while (i < height)
		if (!(tab[i++] = (int*)malloc(sizeof(int) * length)))
			errorcase();
	return (tab);
}

char	*ft_atoi2(char *str, int *ret)
{
	int nb;
	int neg;

	nb = 0;
	neg = 1;
	if (*str == '+')
		str++;
	else if (*str == '-')
		str++ && (neg = -1);
	while (*str >= '0' && *str <= '9')
		nb = (nb * 10) + (*(str++) - '0');
	while (*str != ' ' && *str && *str != '\n')
		str++;
	while (*str == ' ')
		str++;
	*ret = nb * neg;
	return (str);
}

void	fill_map(char *map, int **tab, t_ptr *p)
{
	int i;
	int neg;
	int x;
	int y;

	i = 0;
	neg = 1;
	y = 0;
	while (*map)
	{
		x = 0;
		while (*map == ' ')
			map++;
		while (*map != '\n' && *map)
		{
			map = ft_atoi2(map, &tab[y][x]);
			if (tab[y][x] > p->y_max)
				p->y_max = tab[y][x];
			x++;
		}
		y++;
		if (*map == '\n')
			map++;
	}
}
