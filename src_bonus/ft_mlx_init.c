/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:00:10 by jamendoe          #+#    #+#             */
/*   Updated: 2023/03/14 21:00:14 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long_bonus.h"
#include "../includes/libft.h"

int	ft_update_anim(t_game *game)
{
	t_sprite	*current;
	static int	counter = 0;
	int			div;

	if (game->win_end < 2)
	{		
		div = counter % SPRITE_NUMBER;
		current = game->variations;
		while (current)
		{
			if (current->id == div)
				game->current_collectible = current;
			current = current->next;
		}
		ft_render_images(game);
		counter++;
	}
	if (game->win_end == END_GAME)
		game->win_end++;
	return (0);
}

int	ft_key_handler(int key_code, t_game *game)
{
	if (key_code == UP)
		ft_move_up(game);
	if (key_code == LEFT)
		ft_move_left(game);
	if (key_code == DOWN)
		ft_move_down(game);
	if (key_code == RIGHT)
		ft_move_right(game);
	if (key_code == ESCAPE)
		ft_close_window(game);
	return (0);
}

void	ft_link_addr(t_game *game)
{
	game->tile.bg.addr = mlx_get_data_addr(game->tile.bg.ptr, \
&game->tile.bg.bits_per_pixel, &game->tile.bg.size_line, &game->tile.bg.endian);
	game->tile.collectible.addr = mlx_get_data_addr(game->tile.collectible.ptr, \
&game->tile.collectible.bits_per_pixel, &game->tile.collectible.size_line, \
&game->tile.collectible.endian);
	game->tile.enemy.addr = mlx_get_data_addr(game->tile.enemy.ptr, \
&game->tile.enemy.bits_per_pixel, &game->tile.enemy.size_line, \
&game->tile.enemy.endian);
	game->tile.player.addr = mlx_get_data_addr(game->tile.player.ptr, \
&game->tile.player.bits_per_pixel, &game->tile.player.size_line, \
&game->tile.player.endian);
	game->tile.floor.addr = mlx_get_data_addr(game->tile.floor.ptr, \
&game->tile.floor.bits_per_pixel, &game->tile.floor.size_line, \
&game->tile.floor.endian);
	game->tile.exit.addr = mlx_get_data_addr(game->tile.exit.ptr, \
&game->tile.exit.bits_per_pixel, &game->tile.exit.size_line, \
&game->tile.exit.endian);
	game->tile.wall.addr = mlx_get_data_addr(game->tile.wall.ptr, \
&game->tile.wall.bits_per_pixel, &game->tile.wall.size_line, \
&game->tile.wall.endian);
	if (!game->tile.bg.addr || !game->tile.collectible.addr || \
	!game->tile.enemy.addr || !game->tile.player.addr || \
	!game->tile.floor.addr || !game->tile.exit.addr || !game->tile.wall.addr)
		exit(EXIT_FAILURE);
}

void	ft_link_images(t_game *game)
{
	game->tile.bg.ptr = mlx_new_image(game->mlx, \
	game->tile_size * game->size.x, game->tile_size * game->size.y);
	game->tile.collectible.ptr = mlx_xpm_file_to_image(game->mlx, \
PATH_COLLECTIBLE, &game->tile.collectible.width, \
&game->tile.collectible.height);
	game->tile.player.ptr = mlx_xpm_file_to_image(game->mlx, \
PATH_PLAYER, &game->tile.player.width, &game->tile.player.height);
	game->tile.floor.ptr = mlx_xpm_file_to_image(game->mlx, \
PATH_FLOOR, &game->tile.floor.width, &game->tile.floor.height);
	game->tile.exit.ptr = mlx_xpm_file_to_image(game->mlx, \
PATH_EXIT, &game->tile.exit.width, &game->tile.exit.height);
	game->tile.wall.ptr = mlx_xpm_file_to_image(game->mlx, \
PATH_WALL, &game->tile.wall.width, &game->tile.wall.height);
	game->tile.enemy.ptr = mlx_xpm_file_to_image(game->mlx, \
PATH_ENEMY, &game->tile.enemy.width, &game->tile.enemy.height);
	if (!game->tile.enemy.ptr || !game->tile.collectible.ptr || \
!game->tile.collectible.ptr || !game->tile.player.ptr || \
!game->tile.floor.ptr || !game->tile.exit.ptr)
		exit(EXIT_FAILURE);
}

void	ft_mlx_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!(game->mlx))
	{
		free(game->mlx);
		exit(EXIT_FAILURE);
	}
	game->window = mlx_new_window (game->mlx, game->size.x * game->tile_size, \
	game->size.y * game->tile_size + BOARD_SIZE, GAME_TITLE);
	if (!game->window)
	{
		free(game->mlx);
		free(game->window);
		exit(EXIT_FAILURE);
	}
	ft_link_images(game);
	ft_link_addr(game);
	ft_images_from_sprite(game);
	mlx_key_hook(game->window, ft_key_handler, game);
	mlx_hook(game->window, 17, 1L << 0, ft_close_window, game);
	mlx_loop_hook (game->mlx, ft_update_anim, game);
	mlx_loop (game->mlx);
}
