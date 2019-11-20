/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:36:57 by alilin            #+#    #+#             */
/*   Updated: 2019/11/19 15:18:44 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putpre(t_opt *f, int len, int va_arg)
{
	int i;

	i = 0;
	if (f->precision >= f->width || f->width == 0)
	{
		if (va_arg < 0)
			write(1, "-", 1);
		i = ft_putrepeat('0', f->precision - len);
	}
	else if (f->precision < f->width && f->left == 1)
	{
		if (va_arg < 0)
			write(1, "-", 1);
		i = ft_putrepeat('0', f->precision - len);
	}
	return (i);
}

int	ft_putpre2(t_opt *f, int len, int va_arg)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (f->precision < f->width && f->left == 0)
	{
		if (f->precision <= len)
		{
			i = ft_putrepeat(' ', f->width - len - (va_arg < 0));
			if (va_arg < 0)
				write(1, "-", 1);
		}
		else if (f->precision > len)
		{
			i = ft_putrepeat(' ', f->width - f->precision - (va_arg < 0));
			if (va_arg < 0)
				write(1, "-", 1);
			j = ft_putrepeat('0', f->width - len - i - (va_arg < 0));
		}
	}
	return (i + j);
}

int	ft_putwidth(t_opt *f, int len, int va_arg)
{
	int i;

	i = 0;
	if (f->left == 0 && f->zero == 0)
		i = ft_putrepeat(' ', f->width - len - (va_arg < 0));
	if (va_arg < 0)
		write(1, "-", 1);
	if (f->left == 0 && f->zero == 1)
		i = ft_putrepeat('0', f->width - len - (va_arg < 0));
	return (i);
}

int	ft_putend(t_opt *f, int len, int va_arg)
{
	int j;

	j = 0;
	if (f->precision != -1 && f->precision < f->width && f->left == 1)
	{
		if (f->precision >= len)
			j = ft_putrepeat(' ', f->width - f->precision - (va_arg < 0));
		else
			j = ft_putrepeat(' ', f->width - len - (va_arg < 0));
	}
	if (f->precision == -1 && f->width > len && f->left == 1)
		j = ft_putrepeat(' ', f->width - len - (va_arg < 0));
	if (va_arg < 0)
		j++;
	return (j);
}
