/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:00:10 by jamendoe          #+#    #+#             */
/*   Updated: 2023/03/14 21:00:14 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long_bonus.h"
#include "../includes/libft.h"

void	ft_move_enemy(t_game *game)
{
	t_enemy	*enemy_tmp;

	enemy_tmp = game->enemy_list;
	while (enemy_tmp)
	{
		if ((enemy_tmp->id % 4 == 0) && \
game->map[enemy_tmp->place_e.y + 1][enemy_tmp->place_e.x] != MAP_WALL)
			enemy_tmp->place_e.y = enemy_tmp->place_e.y + 1;
		else if (enemy_tmp->id % 4 == 2 && \
game->map[enemy_tmp->place_e.y - 1][enemy_tmp->place_e.x] != MAP_WALL)
			enemy_tmp->place_e.y = enemy_tmp->place_e.y - 1;
		else if (enemy_tmp->id % 4 == 1 && \
game->map[enemy_tmp->place_e.y][enemy_tmp->place_e.x + 1] != MAP_WALL)
			enemy_tmp->place_e.x = enemy_tmp->place_e.x + 1;
		else if (enemy_tmp->id % 4 == 3 && \
game->map[enemy_tmp->place_e.y][enemy_tmp->place_e.x - 1] != MAP_WALL)
			enemy_tmp->place_e.x = enemy_tmp->place_e.x - 1;
		else
			enemy_tmp->id = enemy_tmp->id + 2;
		enemy_tmp->id++;
		enemy_tmp = enemy_tmp->next;
	}
}

unsigned int	ft_tile_type(t_game *game, int n, int tile)
{
	unsigned int	pixel;

	if (tile == TILE_FLOOR)
		pixel = *((unsigned int *)&game->tile.floor.addr[n]);
	if (tile == TILE_WALL)
		pixel = *((unsigned int *)&game->tile.wall.addr[n]);
	if (tile == TILE_EXIT)
		pixel = *((unsigned int *)&game->tile.exit.addr[n]);
	if (tile == TILE_PLAYER)
		pixel = *((unsigned int *)&game->tile.player.addr[n]);
	if (tile == TILE_COLLECTIBLE)
		pixel = *((unsigned int *)&game->current_collectible->anim.addr[n]);
	if (tile == TILE_ENEMY)
		pixel = *((unsigned int *)&game->tile.enemy.addr[n]);
	return (pixel);
}

void	ft_render_tile(t_game *game, int j, int i, int tile)
{
	int				x;
	int				y;
	int				c;
	int				d;
	unsigned int	pixel;

	x = 0;
	y = 0;
	while (y < game->tile_size)
	{
		while (x < game->tile_size)
		{
			c = ((i * game->tile_size) + y) * game->tile.bg.size_line + \
	((j * game->tile_size) + x) * sizeof(int);
			d = x * sizeof(int) + y * game->tile_size * sizeof(int);
			pixel = ft_tile_type(game, d, tile);
			if (pixel != 0XFF000000)
				*(unsigned int *)(&game->tile.bg.addr[c]) = pixel;
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_bg_build(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->size.y)
	{
		while (j < game->size.x)
		{
			if (game->map[i][j] == MAP_FLOOR || \
	game->map[i][j] == MAP_PLAYER || game->map[i][j] == MAP_EXIT || \
	game->map[i][j] == MAP_COLLECTIBLE || game->map[i][j] == MAP_ENEMY)
				ft_render_tile(game, j, i, TILE_FLOOR);
			if (game->map[i][j] == MAP_WALL)
				ft_render_tile(game, j, i, TILE_WALL);
			if (game->map[i][j] == MAP_EXIT)
				ft_render_tile(game, j, i, TILE_EXIT);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_render_images(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	ft_bg_build(game);
	ft_render_tile(game, game->player.x, game->player.y, TILE_PLAYER);
	ft_put_collectible(game, TILE_COLLECTIBLE);
	ft_put_enemy(game);
	ft_put_moves(game);
	mlx_put_image_to_window(game->mlx, game->window, game->tile.bg.ptr, 0, 0);
	if (game->win_end == END_GAME & game->collectibles_number == 0)
	{
		ft_end_game(game, END_SUCCESS);
		ft_printf("Number of moves: %d\n", game->moves);
		ft_printf(MSG_SUCCESS);
	}
	if (game->win_end == END_FAIL)
	{
		ft_end_game(game, END_FAIL);
		ft_printf(MSG_FAIL);
	}
}
