/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:22:01 by alilin            #+#    #+#             */
/*   Updated: 2019/11/19 13:17:09 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		j;
	int		k;
	t_opt	f;

	g_i = 0;
	j = 0;
	g_len = 0;
	va_start(ap, format);
	while (format[g_i])
	{
		if (format[g_i] == '%')
		{
			k = 0;
			f.frmt = (char *)&format[++g_i];
			k = ft_setflag(&f, ap);
			g_i += k;
			g_len += (k + 1);
			j += ft_putstuff(&f, ap);
		}
		else
			ft_putchar(format[g_i++]);
	}
	va_end(ap);
	return (g_i + j - g_len);
}
