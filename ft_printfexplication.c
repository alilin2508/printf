/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:50:54 by alilin            #+#    #+#             */
/*   Updated: 2019/10/17 16:56:14 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	while (*format)
	{

	}

}



va_list		ap;

va_start(ap, format);

va_arg(ap, char);
va_arg(ap, char *);
va_arg(ap, int);

va_end(ap);

%[0-][width][.precision][conv]

42

%05.2s
