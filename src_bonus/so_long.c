/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:00:10 by jamendoe          #+#    #+#             */
/*   Updated: 2023/03/14 21:00:14 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long_bonus.h"
#include "../includes/libft.h"

char	*ft_join(int *file)
{
	char	*tmp;
	char	*line;
	char	*map;
	int		reset;

	map = ft_strdup("");
	reset = 0;
	while (reset == 0)
	{
		line = get_next_line(*file);
		if (!line)
			reset = 1;
		else
		{
			tmp = ft_strdup(map);
			free(map);
			map = ft_strjoin(tmp, line);
			free(tmp);
		}
		free(line);
	}
	return (map);
}

char	*ft_read_map_file(char *path)
{
	int		file;
	char	*read_map;

	file = open(path, O_RDONLY);
	if (file < 1)
		exit(EXIT_FAILURE);
	read_map = ft_join(&file);
	return (read_map);
}

void	ft_validate_map(char *path, t_game *game)
{
	char	*read_map;
	int		i;

	i = 0;
	read_map = ft_read_map_file(path);
	ft_map_characters(read_map);
	ft_map_minimum_elements(read_map);
	ft_map_rectangular(read_map);
	ft_map_walls(read_map, game);
	game->map = ft_split(read_map, '\n');
	game->map_path = ft_split(read_map, '\n');
	game->collectibles_number = ft_count_collectibles(read_map);
	free(read_map);
}

void	ft_validate_map_ext(char *path)
{
	int	i;

	i = ft_strlen(path) - 4;
	if (path[i] != '.' || path[i + 1] != 'b' || path[i + 2] != 'e' || \
path[i + 3] != 'r')
	{
		ft_printf("Error\nThe map is invalid! it must be <name>.ber\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		ft_validate_map_ext(argv[1]);
		ft_validate_map(argv[1], &game);
		ft_init_vars(&game);
		ft_validate_map_path(&game, game.player.x, game.player.y);
		if (game.path_map_ok == 0)
			ft_exit_invalid_map(NULL, ERROR_EXIT_PATH);
		ft_erase_maps(&game, MAP_PATH);
		ft_mlx_init(&game);
		return (0);
	}
	ft_printf("Error\nCommand must be: ./so_long_bonus <path_to_map>!\n");
	exit(EXIT_FAILURE);
}
