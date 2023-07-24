/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:00:10 by jamendoe          #+#    #+#             */
/*   Updated: 2023/03/14 21:00:14 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long_bonus.h"
#include "../includes/libft.h"

void	ft_erase_sprite_images(t_game *game)
{
	t_sprite	*tmp;

	while (game->variations->next)
	{
		tmp = game->variations->next;
		free (game->variations);
		game->variations = tmp;
	}
	free (game->variations);
}

void	ft_add_sprite_member(t_sprite **lst, t_sprite *new)
{
	t_sprite	*addback;

	addback = (*lst);
	if (!new)
		(*lst) = NULL;
	else if (!(*lst))
		(*lst) = new;
	else
	{
		while (addback->next)
			addback = addback->next;
		addback->next = new;
	}
}

t_sprite	*ft_new_sprite_member(t_img *sprite, int m)
{
	t_sprite	*new;

	new = (t_sprite *)malloc(sizeof(t_sprite));
	if (!new)
		exit (EXIT_FAILURE);
	new->anim.ptr = sprite->ptr;
	new->anim.addr = sprite->addr;
	new->anim.bits_per_pixel = sprite->bits_per_pixel;
	new->anim.size_line = sprite->size_line;
	new->anim.endian = sprite->endian;
	new->anim.width = sprite->width;
	new->anim.height = sprite->height;
	new->id = m;
	new->next = NULL;
	return (new);
}

void	ft_create_image(t_game *game, t_img *sprite, int m)
{
	int	i;
	int	j;	
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (y < game->tile_size)
	{
		while (x < game->tile_size)
		{
			i = (x * sizeof(int)) + \
			(y * game->tile.collectible.size_line) + m * sprite->size_line;
			j = (x * sizeof(int)) + (y * sprite->size_line);
			*(unsigned int *)(&sprite->addr[j]) = \
*((unsigned int*)&game->tile.collectible.addr[i]);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_images_from_sprite(t_game *game)
{
	t_sprite	*tmp;
	t_img		sprite;
	int			m;

	m = 0;
	while (m < SPRITE_NUMBER)
	{
		sprite.ptr = mlx_new_image(game->mlx, \
game->tile_size, game->tile_size);
		sprite.addr = mlx_get_data_addr(sprite.ptr, \
&sprite.bits_per_pixel, &sprite.size_line, &sprite.endian);
		ft_create_image(game, &sprite, m);
		tmp = ft_new_sprite_member(&sprite, m);
		ft_add_sprite_member(&game->variations, tmp);
		m++;
	}
}
