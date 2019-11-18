/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:39:30 by alilin            #+#    #+#             */
/*   Updated: 2019/11/18 11:00:43 by alilin           ###   ########.fr       */
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
		if (f->precision >= f->width || f->width == 0)
		{
			if (va_arg < 0)
				write(1, "-", 1);
			while (i < f->precision - len)
			{
				write(1, "0", 1);
				i++;
			}
		}
		else if (f->precision < f->width && f->left == 0)
		{
			if (f->precision <= len)
			{
				while (i < f->width - len - (va_arg < 0))
				{
					write(1, " ", 1);
					i++;
				}
			}
			else if (f->precision > len)
			{
				while (i < f->width - f->precision - (va_arg < 0))
				{
					write(1, " ", 1);
					i++;
				}
				if (va_arg < 0)
					write(1, "-", 1);
				while (j < f->width - len - i - (va_arg < 0))
				{
					write(1, "0", 1);
					j++;
				}
			}
		}
		else if (f->precision < f->width && f->left == 1)
		{
			if (va_arg < 0)
				write(1, "-", 1);
			while (i < f->precision - len)
			{
				write(1, "0", 1);
				i++;
			}
		}
	}
	if (f->precision == -1 && f->width >= len)
	{
		if (f->left == 0 && f->zero == 0)
		{
			while (i < f->width - len - (va_arg < 0))
			{
				write(1, " ", 1);
				i++;
			}
		}
		if (va_arg < 0)
			write(1, "-", 1);
		if (f->left == 0 && f->zero == 1)
		{
			while (i < f->width - len - (va_arg < 0))
			{
				write(1, "0", 1);
				i++;
			}
		}
	}
	if (f->precision == -1 && f->width == 0)
		write(1, "-", 1);
	if (len != 0) 
		ft_putnbr(va_arg, &i);
	if (f->precision != -1 && f->precision < f->width && f->left == 1)
	{
		while (j < f->width - f->precision - (va_arg < 0))
		{
			write(1, " ", 1);
			j++;
		}
	}
	if (f->precision == -1 && f->width > len && f->left == 1)
	{
		while (j < f->width - len - (va_arg < 0))
		{
			write(1, " ", 1);
			j++;
		}
	}
	if (va_arg < 0)
		j++;
	return (i + j);
}
