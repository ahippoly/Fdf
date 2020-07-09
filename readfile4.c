/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:01:19 by ahippoly          #+#    #+#             */
/*   Updated: 2019/02/26 14:18:13 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**readfile(char *filename, t_ptr *p)
{
	char	*map;
	int		height;
	int		length;
	int		**tab;

	map = read_map(filename);
	count_size(map, &height, &length);
	tab = alloc_tab(height, length);
	fill_map(map, tab, p);
	p->size_line = length;
	p->nb_line = height;
	return (tab);
}
