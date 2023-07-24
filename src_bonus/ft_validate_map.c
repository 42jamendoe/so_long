/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:00:10 by jamendoe          #+#    #+#             */
/*   Updated: 2023/03/14 21:00:14 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long_bonus.h"
#include "../includes/libft.h"

void	ft_validate_map_path(t_game *game, int x, int y)
{	
	if (x >= game->size.x || x < 0 || y >= game->size.y || y < 0 || \
game->map_path[y][x] == MAP_WALL)
		return ;
	else
	{
		if (game->map_path[y][x] != MAP_EXIT)
		{
			game->map_path[y][x] = MAP_WALL;
			ft_validate_map_path(game, x, y - 1);
			ft_validate_map_path(game, x, y + 1);
			ft_validate_map_path(game, x - 1, y);
			ft_validate_map_path(game, x + 1, y);
		}
		else
			game->path_map_ok = 1;
	}
}

void	ft_map_rectangular(char *read_map)
{
	int	i;
	int	j;
	int	validate;

	i = 0;
	j = 0;
	validate = 0;
	while (read_map[validate] != '\n' && read_map[validate] != '\0')
		validate ++;
	while (read_map[i] != '\0')
	{
		while (read_map[i] != '\n')
		{
			i++;
			j++;
		}
		if (validate != j)
			ft_exit_invalid_map(read_map, ERROR_RECTANGULAR);
		if (read_map[i] == '\0')
			i = validate - 1;
		i++;
		j = 0;
	}
}

void	ft_map_walls(char *read_map, t_game *game)
{
	int	i;

	i = 0;
	game->size.x = ft_size_x(read_map);
	game->size.y = ft_size_y(read_map);
	while (read_map[i] != '\0')
	{
		while (read_map[i] != '\n')
		{
			if (read_map[i] != MAP_WALL)
				ft_exit_invalid_map(read_map, ERROR_WALLS);
			if ((i >= game->size.x + 1) && (i < (game->size.y - 1) \
	* (game->size.x + 1)))
			{
				i = i + game->size.x - 1;
				if (read_map[i] != MAP_WALL)
					ft_exit_invalid_map(read_map, ERROR_WALLS);
			}
			i++;
		}
		i++;
	}
}

void	ft_map_minimum_elements(char *read_map)
{
	int	i;
	int	starting_position;
	int	collectible;
	int	exit;

	i = 0;
	starting_position = 0;
	collectible = 0;
	exit = 0;
	while (read_map[i] != '\0')
	{
		if (read_map[i] == MAP_EXIT)
			exit++;
		if (read_map[i] == MAP_COLLECTIBLE)
			collectible++;
		if (read_map[i] == MAP_PLAYER)
			starting_position++;
		i++;
	}
	if (starting_position != 1 || collectible < 1 || exit != 1)
		ft_exit_invalid_map(read_map, ERROR_ELEMENTS);
}

void	ft_map_characters(char *read_map)
{
	int	i;

	i = 0;
	while (read_map[i] != '\0')
	{
		if (read_map[i] != MAP_FLOOR && read_map[i] != MAP_WALL && \
		read_map[i] != MAP_COLLECTIBLE && read_map[i] != MAP_EXIT && \
		read_map[i] != MAP_PLAYER && read_map[i] != MAP_ENEMY && \
		read_map[i] != '\n')
			ft_exit_invalid_map(read_map, ERROR_CHARACTERS);
		i++;
	}
}
