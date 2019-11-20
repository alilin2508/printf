/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:39:55 by alilin            #+#    #+#             */
/*   Updated: 2019/11/20 10:08:51 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putsfront(t_opt *f, int j, int len)
{
	if (f->left == 0 && f->zero == 0 &&
			(f->width > f->precision || f->width > len) &&
			(f->precision >= len || f->precision == -1))
	{
		while (j < (f->width - len))
		{
			write(1, " ", 1);
			j++;
		}
	}
	else if (f->left == 0 && f->zero == 0 &&
			(f->width > f->precision || f->width > len) &&
			f->precision < len && f->precision != -1)
	{
		while (j < (f->width - f->precision))
		{
			write(1, " ", 1);
			j++;
		}
	}
	return (j);
}

int	ft_putszero(t_opt *f, int j, int len)
{
	if (f->left == 0 && (f->width > f->precision || f->width > len) &&
			(f->precision >= len || f->precision == -1))
	{
		while (j < (f->width - len))
		{
			write(1, "0", 1);
			j++;
		}
	}
	else if (f->left == 0 && (f->width > f->precision || f->width > len) &&
			f->precision < len && f->precision != -1)
	{
		while (j < (f->width - f->precision))
		{
			write(1, "0", 1);
			j++;
		}
	}
	return (j);
}

int	ft_putswrite(t_opt *f, int i, char *va_arg)
{
	if (f->precision != -1)
	{
		while (i < f->precision && va_arg[i])
		{
			write(1, &va_arg[i], 1);
			i++;
		}
	}
	else
	{
		while (va_arg[i])
		{
			write(1, &va_arg[i], 1);
			i++;
		}
	}
	return (i);
}

int	ft_putsend(t_opt *f, int i, int len)
{
	if (f->left == 1 && (f->width > f->precision || f->width > len))
	{
		while (i < f->width)
		{
			write(1, " ", 1);
			i++;
		}
	}
	return (i);
}

int	ft_puts(t_opt *f, va_list ap)
{
	char	*va_arg;
	int		len;
	int		i;
	int		j;

	j = 0;
	i = 0;
	va_arg = va_arg(ap, char *);
	if (va_arg == NULL)
		va_arg = "(null)";
	len = ft_strlen(va_arg);
	if (f->zero == 0)
		j = ft_putsfront(f, j, len);
	else if (f->zero == 1)
		j = ft_putszero(f, j, len);
	i = ft_putswrite(f, i, va_arg);
	i = ft_putsend(f, i, len);
	return (i + j);
}
