# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/23 02:36:56 by wfreulon          #+#    #+#              #
#    Updated: 2023/04/23 03:06:51 by wfreulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = fract_ol.c
LIBFT = ./Libft/libft.a
MLX = ./mlx/libmlx.a ./mlx/libmlx_Linux.a
HEADERFILES = -I fract_ol.h Libft/libft.h
OBJFILES = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g3
CC = gcc

$(NAME): $(OBJFILES)
	make -C Libft
	$(CC) $(CFLAGS) $(OBJFILES) ${LIBFT} -o $(NAME) ${MLX}

all: $(NAME)

#%.o: %.c $(HEADERFILES)
#	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	make clean -C Libft
	rm -f $(OBJFILES) $(OBJBONUS)

fclean:
	make fclean -C Libft
	rm -f $(NAME) $(NAME_B) $(OBJBONUS) $(OBJFILES) ${LIBFT} 

re: fclean all
	
.PHONY: clean fclean all re