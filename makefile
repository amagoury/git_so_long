# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 16:19:15 by aishamagour       #+#    #+#              #
#    Updated: 2024/04/21 16:28:35 by amagoury         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCS		=	parsing.c \
				parsing2.c \
				valid_pass.c \
				so_long.c \
				GNL/get_next_line_bonus.c \
				moves.c \
				end_game.c \
				GNL/get_next_line_utils_bonus.c \
				make_img.c \
				rendering.c

OBJS 		=	$(SRCS:.c=.o)

CC 			= cc

CFLAGS	= -Wall -Werror -Wextra -Iminilibx -IGNL -Iprintf -fsanitize=address -g3

LIBFT = libft/libft.a

PRINTF = printf/libftprintf.a

MLX 	= minilibx/libmlx.a

MLX_FLAGS = -Lminilibx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(LIBFT):	
	$(MAKE) -C libft

$(MLX):
	$(MAKE) -C minilibx

$(PRINTF):
	$(MAKE) -C printf

	
$(NAME) : $(OBJS) $(LIBFT) $(PRINTF) $(MLX)
	$(CC)	$(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME) $(LIBFT) $(MLX) $(PRINTF)

%.o: %.c
	$(CC)	-c $(CFLAGS) $< -o $@

clean :
	$(MAKE) -C libft clean
	$(MAKE) -C printf clean
	rm -f $(OBJS)
		
fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C printf fclean
	$(MAKE) -C minilibx clean
	rm -rf $(NAME)

re:	fclean all
 
.PHONY: all clean fclean re