# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 22:38:46 by amousaid          #+#    #+#              #
#    Updated: 2024/03/20 04:44:34 by amousaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
RM = rm -rf
MLX_PATH = ./minilibx
MLX_NAME = ./minilibx/libmlx.a
MLX_CMD = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

LIBFT = ./libft/libft.a
FRACTOL_SRC = ./mandatory/fractol.c\
				./mandatory/mandelbrot.c\
				./mandatory/zoom.c\
				./mandatory/hook.c\

OBJ = $(FRACTOL_SRC:.c=.o)

all: $(NAME)

$(LIBFT):
		$(MAKE) --no-print-directory -C ./libft
		
$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_CMD) -o $(NAME)
		@echo "[IS MAKE]"
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