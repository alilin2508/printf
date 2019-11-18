/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:38:21 by alilin            #+#    #+#             */
/*   Updated: 2019/11/14 15:08:44 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putc(t_opt *f, va_list ap)
{
	int		va_arg;
	int		i;

	i = 0;
	va_arg = va_arg(ap, int);
	if (f->width > 1 && f->left == 0)
		while (i < f->width - 1)
		{
			write(1, " ", 1);
			i++;
		}
	write(1, &va_arg, 1);
	if (f->left == 1 && f->width > 1)
		while (i < f->width - 1)
		{
			write(1, " ", 1);
			i++;
		}
	return (i + 1);
}
