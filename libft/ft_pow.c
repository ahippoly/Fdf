/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:56:45 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/21 20:09:49 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pow(int nb, int pow)
{
	int nb2;

	nb2 = nb;
	if (pow == 0)
		return (1);
	while (pow > 0)
		nb *= nb2;
	return (nb);
}
