# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 18:56:55 by sschanga          #+#    #+#              #
#    Updated: 2022/12/01 20:23:22 by sschanga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

cc = cc

SRCS = pipex.c \
		set_pipe.c \
		libft.c \
		libft_split.c

OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

.%o: %.c
	$(cc) -c $< -o $@ 

$(NAME): $(OBJS)
	$(cc) $^ -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus fclean clean re