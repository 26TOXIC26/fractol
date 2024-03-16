# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pc <pc@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 22:38:46 by amousaid          #+#    #+#              #
#    Updated: 2024/03/16 07:41:22 by pc               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
MLX_NAME = ./minilibx/libmlx.a
MLX_CMD = -lXext -lX11 -lm

LIBFT = ./libft/libft.a
FRACTOL_SRC = ./mandatory/fractol.c\
# OBJ = $(FRACTOL_SRC:.c=.o)

all: $(NAME)

$(LIBFT):
		$(MAKE) --no-print-directory -C ./libft
		
$(NAME): $(LIBFT) $(FRACTOL_SRC)
		$(CC) $(CFLAGS) $(FRACTOL_SRC) $(LIBFT) $(MLX_CMD) -o fractol
		@echo "make!!"
clean:
	$(MAKE) clean --no-print-directory -C ./libft
	$(RM) $(OBJ)
	@echo "🧹IS CLEAN🧹"

fclean: clean
	$(MAKE) fclean --no-print-directory -C ./libft
	$(RM) $(NAME)
	@echo "🧹IS FULL CLEAN🧹"

re: fclean all

.SILENT: