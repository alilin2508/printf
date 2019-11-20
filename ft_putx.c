/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:13:56 by alilin            #+#    #+#             */
/*   Updated: 2019/11/19 15:43:01 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putx(t_opt *f, va_list ap)
{
	unsigned int		va_arg;
	int					i;
	int					j;
	int					len;

	i = 0;
	j = 0;
	va_arg = va_arg(ap, unsigned int);
	len = ft_sizehexa(va_arg);
	if (va_arg == 0 && f->precision == 0)
		len = 0;
	if (f->precision != -1)
		i = ft_putpreu(f, len);
	if (f->precision == -1 && f->width >= len)
		i = ft_putwidthu(f, len);
	if (len != 0)
		ft_putnbrx(va_arg);
	j = ft_putendu(f, len);
	return (i + j + len);
}

int		ft_putx2(t_opt *f, va_list ap)
{
	unsigned int		va_arg;
	int					i;
	int					j;
	int					len;

	i = 0;
	j = 0;
	va_arg = va_arg(ap, unsigned int);
	len = ft_sizehexa(va_arg);
	if (va_arg == 0 && f->precision == 0)
		len = 0;
	if (f->precision != -1)
		i = ft_putpreu(f, len);
	if (f->precision == -1 && f->width >= len)
		i = ft_putwidthu(f, len);
	if (len != 0)
		ft_putnbrx2(va_arg);
	j = ft_putendu(f, len);
	return (i + j + len);
}
