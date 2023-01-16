# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 01:57:12 by sschanga          #+#    #+#              #
#    Updated: 2023/01/14 01:57:13 by sschanga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS=	ft_decimal_hexafunction.c\
		ft_printf.c\

OBJS=$(SRCS:.c=.o)

CC = cc
CFLAG = -Wall -Wextra -Werror

all: $(NAME)

bonus: all

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)
	
%.o : %.c
	@$(CC) $(CFLAG) -c $^ -o $@ 
clean:
	@rm -f $(OBJS)

norm:
	@norminette *.c *.h

fclean: clean
	@rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
