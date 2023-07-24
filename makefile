NAME = so_long
NAME_BONUS = so_long_bonus
LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCD = ./src

SRCD_BONUS = ./src_bonus

SRC = so_long.c \
	ft_validate_map.c \
	ft_exit.c \
	ft_game_properties.c \
 	ft_collectible_list.c \
	ft_mlx_init.c \
	ft_move.c \
	ft_render_images.c

OBJ = $(SRC:%.c=$(SRCD)/%.o)

SRC_BONUS = so_long.c \
			ft_validate_map.c \
			ft_exit.c \
			ft_game_properties.c \
			ft_collectible_list.c \
			ft_enemy_list.c \
			ft_mlx_init.c \
			ft_sprite.c \
			ft_move.c \
			ft_render_images.c \

OBJ_BONUS = $(SRC_BONUS:%.c=$(SRCD_BONUS)/%.o)

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -Lmlx -lmlx -lbsd -lXext -lX11 -lm -o $(NAME)

$(LIBFT):	
	$(MAKE) -C libft

$(MLX):	
	$(MAKE) -C mlx

$(SRCD)/%.o: $(SRCD)/%.c
	$(CC) $(CFLAGS) -Imlx -Iincludes -c $< -o $@

bonus: $(LIBFT) $(MLX) $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -Llibft -lft -Lmlx -lmlx -lbsd -lXext -lX11 -lm  -o $(NAME_BONUS)

$(SRCD_BONUS)/%.o: $(SRCD_BONUS)/%.c
	$(CC) $(CFLAGS) -Imlx -Iincludes -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(RM) $(LIBFT)

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus libft clean fclean re re_bonus
