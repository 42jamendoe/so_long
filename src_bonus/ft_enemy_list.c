/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:00:10 by jamendoe          #+#    #+#             */
/*   Updated: 2023/03/14 21:00:14 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long_bonus.h"
#include "../includes/libft.h"

void	ft_put_enemy(t_game *game)
{
	t_enemy		*check_enemy;
	static int	counter_e = 0;
	int			speed;

	speed = ENEMY_SPEED;
	check_enemy = game->enemy_list;
	while (check_enemy)
	{
		ft_render_tile(game, check_enemy->place_e.x, \
			check_enemy->place_e.y, TILE_ENEMY);
		if (check_enemy->place_e.x == game->player.x && \
check_enemy->place_e.y == game->player.y)
			game->win_end = END_FAIL;
		check_enemy = check_enemy->next;
	}
	if (counter_e % speed == 0)
		ft_move_enemy(game);
	counter_e++;
}

void	ft_erase_enemy_list(t_game *game)
{
	t_enemy	*tmp;

	while (game->enemy_list->next)
	{
		tmp = game->enemy_list->next;
		free(game->enemy_list);
		game->enemy_list = tmp;
	}
	free(game->enemy_list);
}

void	ft_add_enemy(t_game *game, t_enemy *new)
{
	t_enemy	*addback;

	addback = game->enemy_list;
	if (!new)
		game->enemy_list->next = NULL;
	else if (!game->enemy_list)
		game->enemy_list = new;
	else
	{
		while (addback->next)
			addback = addback->next;
		addback->next = new;
	}
}

t_enemy	*create_enemy(int j, int i, int m)
{
	t_enemy	*new;

	new = (t_enemy *)malloc(sizeof(t_enemy));
	if (!new)
		return (NULL);
	new->place_e.x = j;
	new->place_e.y = i;
	new->id = m;
	new->next = NULL;
	return (new);
}

void	ft_enemy_list_init(t_game *game)
{
	int		i;
	int		j;
	int		m;
	t_enemy	*enemy_tmp;

	i = 0;
	j = 0;
	m = 0;
	while (i < game->size.y)
	{
		while (j < game->size.x)
		{
			if (game->map[i][j] == MAP_ENEMY)
			{
				enemy_tmp = create_enemy(j, i, m);
				ft_add_enemy(game, enemy_tmp);
				m++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
