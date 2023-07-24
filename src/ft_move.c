/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:00:10 by jamendoe          #+#    #+#             */
/*   Updated: 2023/03/14 21:00:14 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"
#include "../includes/libft.h"

int	ft_check_next_step(t_game *game)
{
	t_collectible	*tmp_c;

	tmp_c = game->collectible_list;
	if (game->map[game->player.y][game->player.x] == MAP_COLLECTIBLE)
	{	
		while (tmp_c)
		{
			if (tmp_c->show == COLLECTIBLE_ON && game->player.x == \
			tmp_c->place_c.x && game->player.y == tmp_c->place_c.y)
			{
				tmp_c->show = COLLECTIBLE_OFF;
				game->collectibles_number -= 1;
				return (0);
			}
			else
				tmp_c = tmp_c->next;
		}
	}
	if (game->map[game->player.y][game->player.x] == MAP_EXIT)
		return (2);
	return (0);
}

void	ft_move_up(t_game *game)
{
	int	test;

	game->player.y -= 1;
	game->moves += 1;
	if (game->map[game->player.y][game->player.x] == MAP_WALL)
	{
		game->player.y += 1;
		game->moves -= 1;
		return ;
	}
	test = ft_check_next_step(game);
	if (test == 2)
	{
		if (game->collectibles_number == 0)
			game->win_end = END_GAME;
	}
	if (game->win_end < END_GAME)
		ft_printf("Number of moves: %d\n", game->moves);
	ft_render_images(game);
}

void	ft_move_left(t_game *game)
{
	int	test;

	game->player.x -= 1;
	game->moves += 1;
	if (game->map[game->player.y][game->player.x] == MAP_WALL)
	{
		game->player.x += 1;
		game->moves -= 1;
		return ;
	}
	test = ft_check_next_step(game);
	if (test == 2)
	{
		if (game->collectibles_number == 0)
			game->win_end = END_GAME;
	}
	if (game->win_end < END_GAME)
		ft_printf("Number of moves: %d\n", game->moves);
	ft_render_images(game);
}

void	ft_move_down(t_game *game)
{
	int	test;

	game->player.y += 1;
	game->moves += 1;
	if (game->map[game->player.y][game->player.x] == MAP_WALL)
	{
		game->player.y -= 1;
		game->moves -= 1;
		return ;
	}
	test = ft_check_next_step(game);
	if (test == 2)
	{
		if (game->collectibles_number == 0)
			game->win_end = END_GAME;
	}
	if (game->win_end < END_GAME)
		ft_printf("Number of moves: %d\n", game->moves);
	ft_render_images(game);
}

void	ft_move_right(t_game *game)
{
	int	test;

	game->player.x += 1;
	game->moves += 1;
	if (game->map[game->player.y][game->player.x] == MAP_WALL)
	{
		game->player.x -= 1;
		game->moves -= 1;
		return ;
	}
	test = ft_check_next_step(game);
	if (test == 2)
	{
		if (game->collectibles_number == 0)
			game->win_end = END_GAME;
	}
	if (game->win_end < END_GAME)
		ft_printf("Number of moves: %d\n", game->moves);
	ft_render_images(game);
}
