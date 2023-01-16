# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 20:24:38 by sschanga          #+#    #+#              #
#    Updated: 2022/10/01 23:56:13 by sschanga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
BONUS       = libftprintf_bonus.a

SRCS		= ft_printf.c \
			ft_get_str.c \
			ft_get_int.c \
			ft_get_len.c \
			ft_get_hex.c \
			ft_libft_str.c \
			ft_libft_nbr.c

BONUS_SRC	= ft_printf_bonus.c \
			ft_get_str_bonus.c \
			ft_get_int_bonus.c \
			ft_get_len_bonus.c \
			ft_get_hex_bonus.c \
			ft_libft_str_bonus.c \
			ft_libft_nbr_bonus.c

OBJS		= $(SRCS:%.c=%.o)

BONUS_OBJS	= $(BONUS_SRC:%.c=%.o)

FLAGS		= -Wall -Werror -Wextra -g

all: $(NAME)

%.o: %.c
	cc $(FLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(BONUS_OBJS) $(OBJS)
	ar rc $(BONUS) $(BONUS_OBJS)

git:
	git add .
	git commit -m "Update!"
	git push

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus fclean clean re
