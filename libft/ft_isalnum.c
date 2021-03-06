/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:11:14 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/19 16:45:25 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((48 <= c && c <= 57) || (96 < c && c < 123) || ('A' <= c && c <= 'Z'))
		return (1);
	return (0);
}
