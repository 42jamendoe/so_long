/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:00:10 by jamendoe          #+#    #+#             */
/*   Updated: 2023/03/14 21:00:14 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"
#include "../includes/libft.h"

void	ft_put_collectible(t_game *game, int tile)
{
	t_collectible	*check_collectible;

	check_collectible = game->collectible_list;
	while (check_collectible)
	{
		if (check_collectible->show == COLLECTIBLE_ON)
			ft_render_tile(game, check_collectible->place_c.x, \
			check_collectible->place_c.y, tile);
		check_collectible = check_collectible->next;
	}
}

void	ft_erase_collectible_list(t_game *game)
{
	t_collectible	*tmp;

	while (game->collectible_list->next)
	{
		tmp = game->collectible_list->next;
		free(game->collectible_list);
		game->collectible_list = tmp;
	}
	free(game->collectible_list);
}

void	ft_add_collectible(t_game *game, t_collectible *new)
{
	t_collectible	*addback;

	addback = game->collectible_list;
	if (!new)
		game->collectible_list = NULL;
	else if (!game->collectible_list)
		game->collectible_list = new;
	else
	{
		while (addback->next)
			addback = addback->next;
		addback->next = new;
	}
}

t_collectible	*create_collectible(int j, int i)
{
	t_collectible	*new;

	new = (t_collectible *)malloc(sizeof(t_collectible));
	if (!new)
		return (NULL);
	new->place_c.x = j;
	new->place_c.y = i;
	new->show = COLLECTIBLE_ON;
	new->next = NULL;
	return (new);
}

void	ft_collectible_list_init(t_game *game)
{
	int				i;
	int				j;
	t_collectible	*collectible_tmp;

	i = 0;
	j = 0;
	while (i < game->size.y)
	{
		while (j < game->size.x)
		{
			if (game->map[i][j] == MAP_COLLECTIBLE)
			{
				collectible_tmp = create_collectible(j, i);
				ft_add_collectible(game, collectible_tmp);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
