/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:51:17 by alilin            #+#    #+#             */
/*   Updated: 2019/11/18 11:04:11 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_reset(t_opt *f)
{
	f->left = 0;
	f->zero = 0;
	f->width = 0;
	f->precision = -1;
	f->conv = '\0';
}

int		ft_width(t_opt *f, int i, va_list ap)
{
	int		j;
	int		va_arg;
	char	*str;

	j = 0;
	if (f->frmt[i] == '*')
	{
		va_arg = va_arg(ap, int);
		if (va_arg < 0)
		{
			f->left = 1;
			va_arg *= -1;
		}
		f->width = va_arg;
		j = 1;
	}
	else
	{
		while (ft_isdigit(f->frmt[i + j]) == 1 && f->frmt[i + j])
			j++;
		str = ft_substr(f->frmt, i, j);
		f->width = ft_atoi((const char *)str);
		free(str);
	}
	return (j - 1);
}

int		ft_precision(t_opt *f, int i, va_list ap)
{
	int		j;
	int		va_arg;
	char	*str;

	j = 0;
	if (f->frmt[i] == '*')
	{
		va_arg = va_arg(ap, int);
		if (va_arg < 0)
			f->precision = -1;
		else
			f->precision = va_arg;
		j = 1;
	}
	else
	{
		while (ft_isdigit(f->frmt[i + j]) == 1 && f->frmt[i + j])
			j++;
		str = ft_substr(f->frmt, i, j);
		f->precision = ft_atoi(str);
		free(str);
	}
	return (j);
}

int		ft_setflag(t_opt *f, va_list ap)
{
	int	i;

	i = 0;
	ft_reset(f);
	while ((f->frmt[i] == '0' || f->frmt[i] == '-' || f->frmt[i] == '.' ||
			ft_isdigit(f->frmt[i]) == 1 || f->frmt[i] == '*') && f->frmt[i])
	{
		if (f->frmt[i] == '0')
			f->zero = 1;
		else if (f->frmt[i] == '-')
			f->left = 1;
		else if ((ft_isdigit(f->frmt[i]) == 1 && f->frmt[i] != 0 &&
				f->frmt[i - 1] != '.') || (f->frmt[i] == '*' &&
					f->frmt[i - 1] != '.'))
			i += ft_width(f, i, ap);
		else if (f->frmt[i] == '.')
			i += ft_precision(f, i + 1, ap);
		i++;
	}
	if (ft_isalpha(f->frmt[i]) == 1 || f->frmt[i] == '%')
		f->conv = f->frmt[i];
	return (i + 1);
}
