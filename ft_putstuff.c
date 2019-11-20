/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:23:15 by alilin            #+#    #+#             */
/*   Updated: 2019/11/19 15:42:40 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstuff(t_opt *f, va_list ap)
{
	int	i;

	i = 0;
	if (f->conv == 'c' || f->conv == '%')
		i = ft_putc(f, ap);
	else if (f->conv == 's')
		i = ft_puts(f, ap);
	else if (f->conv == 'd' || f->conv == 'i')
		i = ft_putd(f, ap);
	else if (f->conv == 'u')
		i = ft_putu(f, ap);
	else if (f->conv == 'x')
		i = ft_putx(f, ap);
	else if (f->conv == 'X')
		i = ft_putx2(f, ap);
	else if (f->conv == 'p')
		i = ft_putp(f, ap);
	return (i);
}
