# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 02:00:45 by sschanga          #+#    #+#              #
#    Updated: 2023/01/14 02:00:46 by sschanga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PRINTF		= 	/printf/printf.a 

SRCS=	ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c\
		get_next_line_utils_bonus.c\
		get_next_line_bonus.c\

OBJS=$(SRCS:.c=.o)

CC = cc
CFLAG = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME) : $(OBJS)
	@make -C ./printf
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAG) -c $^ -o $@
clean:
	rm -f $(OBJS)
	@make clean -C ./printf

fclean: clean
	rm -f $(NAME)
	@make fclean -C ./printf

re: fclean all
.PHONY: all clean fclean re
