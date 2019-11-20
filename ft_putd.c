/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:39:30 by alilin            #+#    #+#             */
/*   Updated: 2019/11/18 15:03:02 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putd(t_opt *f, va_list ap)
{
	int		va_arg;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	va_arg = va_arg(ap, int);
	len = ft_sizeint(va_arg);
	if (va_arg == 0 && f->precision == 0)
		len = 0;
	if (f->precision != -1)
	{
		i = ft_putpre(f, len, va_arg);
		i += ft_putpre2(f, len, va_arg);
	}
	if (f->precision == -1 && f->width >= len)
		i = ft_putwidth(f, len, va_arg);
	if (f->precision == -1 && f->width < len && va_arg < 0)
		write(1, "-", 1);
	if (len != 0)
		ft_putnbr(va_arg, &i);
	j = ft_putend(f, len, va_arg);
	return (i + j);
}
