/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:22:01 by alilin            #+#    #+#             */
/*   Updated: 2019/11/15 13:58:14 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	t_opt	f;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			f.frmt = (char *)&format[++i];
			i += ft_setflag(&f, ap);
			ft_putd(&f, ap);
		}
		else
		{
			ft_putchar(format[i]);
			i++;
		}
	}
	va_end(ap);
	return (0);
}
