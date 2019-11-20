/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:48:39 by alilin            #+#    #+#             */
/*   Updated: 2019/11/19 15:23:38 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putprep(t_opt *f, int len)
{
	int i;

	i = 0;
	if (f->precision >= f->width || f->width == 0)
	{
		write(1, "0x", 2);
		i = ft_putrepeat('0', f->precision - len);
	}
	else if (f->precision < f->width && f->left == 1)
	{
		write(1, "0x", 2);
		i = ft_putrepeat('0', f->precision - len);
	}
	return (i);
}

int	ft_putprep2(t_opt *f, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (f->precision < f->width && f->left == 0)
	{
		if (f->precision <= len)
		{
			i = ft_putrepeat(' ', f->width - len - 2);
			write(1, "0x", 2);
		}
		else if (f->precision > len)
		{
			i = ft_putrepeat(' ', f->width - f->precision - 2);
			write(1, "0x", 2);
			j = ft_putrepeat('0', f->width - len - i - 2);
		}
	}
	return (i + j);
}

int	ft_putwidthp(t_opt *f, int len)
{
	int i;

	i = 0;
	if (f->left == 0 && f->zero == 0)
		i = ft_putrepeat(' ', f->width - len - 2);
	write(1, "0x", 2);
	if (f->left == 0 && f->zero == 1)
		i = ft_putrepeat('0', f->width - len - 2);
	return (i);
}

int	ft_putendp(t_opt *f, int len)
{
	int j;

	j = 0;
	if (f->precision != -1 && f->precision < f->width && f->left == 1)
	{
		if (f->precision >= len)
			j = ft_putrepeat(' ', f->width - f->precision - 2);
		else
			j = ft_putrepeat(' ', f->width - len - 2);
	}
	if (f->precision == -1 && f->width > len && f->left == 1)
		j = ft_putrepeat(' ', f->width - len - 2);
	j += 2;
	return (j);
}
