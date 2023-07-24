/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:00:10 by jamendoe          #+#    #+#             */
/*   Updated: 2023/03/14 21:00:14 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long_bonus.h"
#include "../includes/libft.h"

void	ft_put_moves(t_game *game)
{
	char	*moves_number;

	moves_number = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->window, FIX_TEXT_BOARD, \
game->size.y * game->tile_size + FIX_TEXT_BOARD, 0X00FFFFFF, TEXT_BOARD);
	mlx_string_put(game->mlx, game->window, FIX_MOVES_BOARD, \
game->size.y * game->tile_size + FIX_TEXT_BOARD, 0X00FFFFFF, moves_number);
	free(moves_number);
}

int	ft_close_window(t_game *game)
{
	ft_erase_collectible_list(game);
	ft_erase_enemy_list(game);
	ft_erase_sprite_images(game);
	ft_erase_maps(game, MAP);
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_end_game(t_game *game, int type)
{
	void	*end;
	char	*msg;
	int		posx;
	int		posy;
	int		color;

	posx = game->size.x * game->tile_size / 2 - 160;
	posy = game->size.y * game->tile_size / 2 - 32;
	if (type == END_SUCCESS)
	{
		color = 0X0000FF00;
		msg = MSG_SUCCESS;
	}
	else
	{
		color = 0X00FF0000;
		msg = MSG_FAIL;
	}
	end = mlx_new_image(game->mlx, END_BOARD_WIDTH, END_BOARD_HEIGHT);
	mlx_put_image_to_window(game->mlx, game->window, end, posx, posy);
	mlx_string_put(game->mlx, game->window, \
posx + END_FIX_X_SUCCESS, posy + END_FIX_Y_SUCCESS, color, msg);
	mlx_string_put(game->mlx, game->window, \
posx + END_FIX_X_FAIL, posy + END_FIX_Y_FAIL, 0X00FFFFFF, MSG_EXIT);
}

void	ft_erase_maps(t_game *game, int map)
{
	int	i;

	i = 0;
	if (map == MAP)
	{
		while (i < game->size.y)
		{
			free((void *)game->map[i]);
			i++;
		}
		free(game->map);
	}
	if (map == MAP_PATH)
	{
		while (i < game->size.y)
		{
			free((void *)game->map_path[i]);
			i++;
		}
		free(game->map_path);
	}
}

void	ft_exit_invalid_map(char *read_map, int msg)
{
	char	*error_msg;

	if (msg == ERROR_CHARACTERS)
		error_msg = "Error\nThe map can be composed of only these 5 \
	characters: 0, 1, C, E, P and F!";
	if (msg == ERROR_ELEMENTS)
		error_msg = "Error\nThe map is invalid! It must contain 1 exit, \
	at least 1 collectible, and 1 starting position to be valid!";
	if (msg == ERROR_WALLS)
		error_msg = "Error\nThe map must be closed/surrounded by walls!";
	if (msg == ERROR_RECTANGULAR)
		error_msg = "Error\nThe map is invalid! It's not rectangular!";
	if (msg == ERROR_EXIT_PATH)
		error_msg = "Error\nThe map has no valid path to exit!";
	ft_printf("%s\n", error_msg);
	if (read_map)
		free (read_map);
	exit(EXIT_FAILURE);
}
