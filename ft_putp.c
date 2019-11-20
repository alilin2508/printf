/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:38:59 by alilin            #+#    #+#             */
/*   Updated: 2019/11/19 13:03:19 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putp(t_opt *f, va_list ap)
{
	long	va_arg;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	va_arg = va_arg(ap, long);
	len = ft_sizehexa(va_arg);
	if (va_arg == 0 && f->precision == 0)
		len = 0;
	if (f->precision != -1)
	{
		i = ft_putprep(f, len);
		i += ft_putprep2(f, len);
	}
	if (f->precision == -1 && f->width >= len)
		i = ft_putwidthp(f, len);
	if (f->precision == -1 && f->width < len)
		write(1, "0x", 2);
	if (len != 0)
		ft_putnbrx(va_arg);
	j = ft_putendp(f, len);
	return (i + j + len);
}
