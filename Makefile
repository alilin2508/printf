# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alilin <alilin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 11:28:38 by alilin            #+#    #+#              #
#    Updated: 2019/11/15 14:12:38 by alilin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_printf.c\
			  ft_setflag.c\
			  ft_puts.c\
			  ft_putc.c\
			  ft_putd.c\
			  ft_sizeint.c\
			  ft_putrepeat.c

OBJS = *.o

INCLS = ./includes/ft_putchar.c\
		./includes/ft_atoi.c\
		./includes/ft_isalpha.c\
		./includes/ft_isdigit.c\
		./includes/ft_substr.c\
		./includes/ft_strlen.c\
		./includes/ft_putnbr.c

all:		$(NAME)

$(NAME):
			gcc -Wall -Wextra -Werror -c $(SRCS) $(INCLS)
			ar rc $(NAME) $(OBJS)

run:		re
			gcc main.c -L. -lftprintf && ./a.out

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
