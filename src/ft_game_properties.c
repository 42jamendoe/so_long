/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_properties.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:00:10 by jamendoe          #+#    #+#             */
/*   Updated: 2023/03/14 21:00:14 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"
#include "../includes/libft.h"

void	ft_player_init(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < game->size.y)
	{
		while (j < game->size.x)
		{
			if (game->map[i][j] == MAP_PLAYER)
			{
				game->player.x = j;
				game->player.y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_init_vars(t_game *game)
{
	game->collectible_list = NULL;
	ft_player_init(game);
	ft_collectible_list_init(game);
	game->moves = 0;
	game->path_map_ok = 0;
	game->win_end = 0;
	game->tile_size = TILE_SIZE;
}

int	ft_count_collectibles(char *read_map)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (read_map[i] != '\0')
	{
		if (read_map[i] == MAP_COLLECTIBLE)
			number += 1;
		i++;
	}
	return (number);
}

int	ft_size_x(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		i++;
	return (i);
}

int	ft_size_y(char *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			count++;
		i++;
	}
	return (count);
}
