/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ui_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:26:51 by jamendoe          #+#    #+#             */
/*   Updated: 2023/01/05 19:03:26 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

int	ft_lenght_ui_number(unsigned int number)
{
	int	len_address;

	len_address = 0;
	while (number != 0)
	{
		number = number / 10;
		len_address++;
	}
	return (len_address);
}

void	ft_write_ui_number(unsigned int number)
{
	if (number > 9)
	{
		ft_write_ui_number(number / 10);
		ft_write_ui_number(number % 10);
	}
	else
	{
		number += 48;
		write(1, &number, 1);
	}			
}

int	ft_print_ui_number(unsigned int number)
{
	int	lenght;

	lenght = 0;
	if (number == 0)
	{
		number = number + 48;
		lenght += write(1, &number, 1);
	}
	else
	{
		ft_write_ui_number(number);
		lenght += ft_lenght_ui_number(number);
	}
	return (lenght);
}
