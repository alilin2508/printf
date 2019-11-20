/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:14:52 by alilin            #+#    #+#             */
/*   Updated: 2019/11/19 15:43:15 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_putnbrx(long n)
{
	long	nb;
	char	*base;

	nb = n;
	if (!(base = malloc(sizeof(char) * 16)))
		return ;
	base = "0123456789abcdef";
	if (nb < 0)
		nb = nb * -1;
	if (nb % 16 != nb)
		ft_putnbrx(nb / 16);
	ft_putchar(base[nb % 16]);
}

void	ft_putnbrx2(long n)
{
	long	nb;
	char	*base;

	nb = n;
	if (!(base = malloc(sizeof(char) * 16)))
		return ;
	base = "0123456789ABCDEF";
	if (nb < 0)
		nb = nb * -1;
	if (nb % 16 != nb)
		ft_putnbrx2(nb / 16);
	ft_putchar(base[nb % 16]);
}
