/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:27:39 by alilin            #+#    #+#             */
/*   Updated: 2019/11/15 14:38:54 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_opt
{
	int		left;
	int		zero;
	int		width;
	int		precision;
	char	conv;
	char	*frmt;
}				t_opt;

int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
void			ft_putchar(char c);
size_t			ft_strlen(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_setflag(t_opt *f, va_list ap);
int				ft_printf(const char *format, ...);
int				ft_puts(t_opt *f, va_list ap);
int				ft_putc(t_opt *f, va_list ap);
int				ft_putd(t_opt *f, va_list ap);
int				ft_sizeint(int n);
int				ft_putrepeat(int i, char c, int len);
int				ft_putnbr(int n, int *i);

#endif
