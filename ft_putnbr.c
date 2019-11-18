/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:11:18 by alilin            #+#    #+#             */
/*   Updated: 2019/11/15 15:04:51 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_putnbr(int n, int *i)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, i);
		ft_putnbr(nb % 10, i);
	}
	else
	{
		ft_putchar(nb + '0');
		(*i)++;
	}
	return (*i);
}
