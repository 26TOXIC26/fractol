# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 22:38:46 by amousaid          #+#    #+#              #
#    Updated: 2024/03/23 01:04:13 by amousaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
BONUS = fractol_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
RM = rm -rf
MLX_PATH = ./minilibx
MLX_NAME = ./minilibx/libmlx.a
MLX_CMD = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

LIBFT = ./libft/libft.a
FRACTOL_SRC = ./src/fractol.c\
				./src/mandelbrot.c\
				./src/julia.c\
				./src/burning_ship.c\
				./src/call_mandelbrot_ship.c\
				./src/zoom.c\
				./src/hook.c\
				./src/check.c\
				./src/error.c
OBJ = $(FRACTOL_SRC:.c=.o)

all: $(NAME)
bonus: $(BONUS)

$(LIBFT):
		$(MAKE) --no-print-directory -C ./libft
		
$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_CMD) -o $(NAME)
		@echo "✅-------✅IS MAKE✅-------✅"

$(BONUS): $(LIBFT) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_CMD) -o $(BONUS)
		@echo "✅------✅BONUS IS MAKE✅------✅"
clean:
	$(MAKE) clean --no-print-directory -C ./libft
	$(RM) $(OBJ)
	@echo "🧹--------🧹IS CLEAN🧹--------🧹"

fclean: clean
	$(MAKE) fclean --no-print-directory -C ./libft
	$(RM) $(NAME)
	$(RM) $(BONUS)
	@echo "🧹-----🧹IS FULL CLEAN🧹-----🧹"

re: fclean all

.SILENT: