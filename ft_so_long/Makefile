# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 18:56:55 by sschanga          #+#    #+#              #
#    Updated: 2022/11/05 00:07:26 by sschanga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH	= bonus mandatory

NAME = so_long
BONUS_NAME = so_long_bonus

cc = cc

SRCS = so_long.c \
		images.c \
		keypress.c \
		map.c \
		check_map.c \
		check_path.c \
		enemy.c \
		libft.c \
		libft_itoa.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c
		
BONUS_SRC = so_long_bonus.c \
		images_bonus.c \
		keypress_bonus.c \
		map_bonus.c \
		check_map_bonus.c \
		check_path_bonus.c \
		enemy_bonus.c \
		libft_bonus.c \
		libft_itoa_bonus.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

IFLAGS	=	-I ./get_next_line/

OBJS		=	$(SRCS:.c=.o)

BONUS_OBJS	=	$(BONUS_SRC:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

.%o: %.c
	$(cc) $(IFLAGS) -c $< -o $@

$(BONUS_NAME): $(BONUS_OBJS)
	$(cc)  $(IFLAG) $^ -Lmlx -lmlx -framework OpenGL -framework Appkit -o $@

$(NAME): $(OBJS)
	$(cc) $(IFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework Appkit -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus fclean clean re
