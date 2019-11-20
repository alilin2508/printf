/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:38:21 by alilin            #+#    #+#             */
/*   Updated: 2019/11/20 10:07:58 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putfront(t_opt *f)
{
	int		i;

	i = 0;
	if (f->width > 1 && f->left == 0 && f->zero == 0)
		while (i < f->width - 1)
		{
			write(1, " ", 1);
			i++;
		}
	else if (f->width > 1 && f->left == 0 && f->zero == 1)
		while (i < f->width - 1)
		{
			write(1, "0", 1);
			i++;
		}
	return (i);
}

int		ft_putc(t_opt *f, va_list ap)
{
	int		va_arg;
	int		i;

	i = 0;
	if (f->conv == '%')
		va_arg = '%';
	if (f->conv != '%')
		va_arg = va_arg(ap, int);
	i = ft_putfront(f);
	write(1, &va_arg, 1);
	if (f->left == 1 && f->width > 1)
	{
		while (i < f->width - 1)
		{
			write(1, " ", 1);
			i++;
		}
	}
	return (i + 1);
}
