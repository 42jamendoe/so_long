/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numberhex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:26:51 by jamendoe          #+#    #+#             */
/*   Updated: 2023/01/05 19:03:26 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

int	ft_lenght_numberhex(unsigned int number)
{
	int	len_address;

	len_address = 0;
	while (number != 0)
	{
		number = number / 16;
		len_address++;
	}
	return (len_address);
}

void	ft_write_numberhex(unsigned int number, char letter)
{
	if (number >= 16)
	{
		ft_write_numberhex(number / 16, letter);
		ft_write_numberhex(number % 16, letter);
	}
	else
	{
		if (number <= 9)
		{
			number += 48;
			write(1, &number, 1);
		}
		else
		{
			if (letter == 'x')
				number += 87;
			else
				number += 55;
			write(1, &number, 1);
		}			
	}
}

int	ft_print_numberhex(unsigned int number, char letter)
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
		ft_write_numberhex(number, letter);
		lenght += ft_lenght_numberhex(number);
	}
	return (lenght);
}
