/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:26:51 by jamendoe          #+#    #+#             */
/*   Updated: 2023/01/05 19:03:26 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

int	ft_lenght_address(uintptr_t pointer)
{
	int	len_address;

	len_address = 0;
	while (pointer != 0)
	{
		pointer = pointer / 16;
		len_address++;
	}
	return (len_address);
}

void	ft_write_pointer(uintptr_t pointer)
{
	if (pointer >= 16)
	{
		ft_write_pointer(pointer / 16);
		ft_write_pointer(pointer % 16);
	}
	else
	{
		if (pointer <= 9)
		{
			pointer += 48;
			write(1, &pointer, 1);
		}
		else
		{
			pointer += 87;
			write(1, &pointer, 1);
		}			
	}
}

int	ft_print_pointer(unsigned long long pointer)
{
	int	lenght;

	lenght = 0;
	lenght += write(1, "0x", 2);
	if (pointer == 0)
	{
		lenght += write(1, "0", 1);
		return (lenght);
	}
	else
		ft_write_pointer(pointer);
	lenght += ft_lenght_address(pointer);
	return (lenght);
}
