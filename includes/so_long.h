/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaqf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:00:55 by jmaqf             #+#    #+#             */
/*   Updated: 2023/04/14 21:01:00 by jmaqf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# define GAME_TITLE "42 Porto - so long - jamendoe"

# define MAP 0
# define MAP_PATH 1
# define TILE_SIZE 32
# define COLLECTIBLE_OFF 0
# define COLLECTIBLE_ON 1

# define ERROR_CHARACTERS 1
# define ERROR_ELEMENTS 2
# define ERROR_WALLS 3
# define ERROR_RECTANGULAR 4
# define ERROR_EXIT_PATH 5

# define PATH_COLLECTIBLE "./textures/collectible.xpm"
# define PATH_PLAYER "./textures/player.xpm"
# define PATH_FLOOR "./textures/floor.xpm"
# define PATH_EXIT "./textures/exit.xpm"
# define PATH_WALL "./textures/wall.xpm"

# define TILE_SIZE 32
# define TILE_WALL 1
# define TILE_FLOOR 2
# define TILE_EXIT 3
# define TILE_PLAYER 4
# define TILE_COLLECTIBLE 5

# define MAP_FLOOR '0'
# define MAP_WALL '1'
# define MAP_COLLECTIBLE 'C'
# define MAP_EXIT 'E'
# define MAP_PLAYER 'P'

# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100
# define ESCAPE 65307

# define END_GAME 1
# define END_SUCCESS 2
# define MSG_SUCCESS "CONGRATULATIONS YOU REACH THE EXIT!!!"
# define MSG_EXIT "Press ESC or close the window to exit!"
# define END_BOARD_WIDTH 320
# define END_BOARD_HEIGHT 64
# define END_FIX_X_SUCCESS 32
# define END_FIX_Y_SUCCESS 24
# define END_FIX_X_FAIL 28
# define END_FIX_Y_FAIL 48
# define END_LEN_X 20

# include <mlx.h>

typedef struct s_coord{
	int	x;
	int	y;
}	t_coord;

typedef struct s_img{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_tiles{
	t_img	bg;
	t_img	floor;
	t_img	collectible;
	t_img	player;
	t_img	exit;
	t_img	wall;
}	t_tiles;

typedef struct s_collectible{
	t_coord					place_c;
	int						show;
	struct s_collectible	*next;
}	t_collectible;

typedef struct s_game{
	void			*mlx;
	void			*window;
	char			**map;
	char			**map_path;
	t_coord			size;
	t_coord			player;
	int				collectibles_number;
	int				moves;
	int				path_map_ok;
	int				tile_size;
	int				win_end;
	t_collectible	*collectible_list;
	t_tiles			tile;
}	t_game;

void			ft_validate_map_ext(char *path);
void			ft_validate_map(char *path, t_game *game);
char			*ft_read_map_file(char *path);
char			*ft_join(int *file);
void			ft_map_characters(char *read_map);
void			ft_exit_invalid_map(char *read_map, int msg);
void			ft_map_minimum_elements(char *read_map);
void			ft_map_walls(char *read_map, t_game *game);
int				ft_size_x(char *map);
int				ft_size_y(char *map);
void			ft_map_rectangular(char *read_map);
int				ft_count_collectibles(char *read_map);
void			ft_init_vars(t_game *game);
void			ft_player_init(t_game *game);
void			ft_collectible_list_init(t_game *game);
t_collectible	*create_collectible(int j, int i);
void			ft_add_collectible(t_game *game, t_collectible *new);
void			ft_validate_map_path(t_game *game, int x, int y);
void			ft_erase_maps(t_game *game, int map);
void			ft_mlx_init(t_game *game);
void			ft_link_images(t_game *game);
void			ft_link_addr(t_game *game);
void			ft_create_image(t_game *game, t_img *sprite, int m);
int				ft_key_handler(int key_code, t_game *game);
void			ft_move_up(t_game *game);
int				ft_check_next_step(t_game *game);
void			ft_move_left(t_game *game);
void			ft_move_down(t_game *game);
void			ft_move_right(t_game *game);
int				ft_close_window(t_game *game);
void			ft_erase_collectible_list(t_game *game);
void			ft_erase_sprite_images(t_game *game);
int				ft_update_anim(t_game *game);
void			ft_render_images(t_game *game);
void			ft_bg_build(t_game *game);
void			ft_render_tile(t_game *game, int j, int i, int tile);
unsigned int	ft_tile_type(t_game *game, int n, int tile);
void			ft_put_collectible(t_game *game, int tile);
void			ft_put_moves(t_game *game);
void			ft_end_game(t_game *game);
void			ft_move_enemy(t_game *game);

#endif
