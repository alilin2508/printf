/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:44:47 by alilin            #+#    #+#             */
/*   Updated: 2019/11/19 15:23:35 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putpreu(t_opt *f, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (f->precision >= f->width || f->width == 0)
		i = ft_putrepeat('0', f->precision - len);
	else if (f->precision < f->width && f->left == 0)
	{
		if (f->precision <= len)
			i = ft_putrepeat(' ', f->width - len);
		else if (f->precision > len)
		{
			i = ft_putrepeat(' ', f->width - f->precision);
			j = ft_putrepeat('0', f->width - len - i);
		}
	}
	else if (f->precision < f->width && f->left == 1)
		i = ft_putrepeat('0', f->precision - len);
	return (i + j);
}

int	ft_putwidthu(t_opt *f, int len)
{
	int i;

	i = 0;
	if (f->left == 0 && f->zero == 0)
		i = ft_putrepeat(' ', f->width - len);
	if (f->left == 0 && f->zero == 1)
		i = ft_putrepeat('0', f->width - len);
	return (i);
}

int	ft_putendu(t_opt *f, int len)
{
	int j;

	j = 0;
	if (f->precision != -1 && f->precision < f->width && f->left == 1)
	{
		if (f->precision >= len)
			j = ft_putrepeat(' ', f->width - f->precision);
		else
			j = ft_putrepeat(' ', f->width - len);
	}
	if (f->precision == -1 && f->width > len && f->left == 1)
		j = ft_putrepeat(' ', f->width - len);
	return (j);
}
