/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:27:39 by alilin            #+#    #+#             */
/*   Updated: 2019/11/19 15:43:05 by alilin           ###   ########.fr       */
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

int				g_len;
int				g_i;

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
int				ft_putu(t_opt *f, va_list ap);
int				ft_putx(t_opt *f, va_list ap);
int				ft_putx2(t_opt *f, va_list ap);
int				ft_putp(t_opt *f, va_list ap);
int				ft_putstuff(t_opt *f, va_list ap);
int				ft_sizeint(long n);
int				ft_sizehexa(long n);
int				ft_putrepeat(char c, int len);
int				ft_putnbr(long n, int *i);
void			ft_putnbrx(long n);
void			ft_putnbrx2(long n);
int				ft_putpre(t_opt *f, int len, int va_arg);
int				ft_putpre2(t_opt *f, int len, int va_arg);
int				ft_putwidth(t_opt *f, int len, int va_arg);
int				ft_putend(t_opt *f, int len, int va_arg);
int				ft_putpreu(t_opt *f, int len);
int				ft_putwidthu(t_opt *f, int len);
int				ft_putendu(t_opt *f, int len);
int				ft_putprep(t_opt *f, int len);
int				ft_putprep2(t_opt *f, int len);
int				ft_putwidthp(t_opt *f, int len);
int				ft_putendp(t_opt *f, int len);

#endif
