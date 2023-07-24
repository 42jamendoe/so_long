/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:23:44 by jamendoe          #+#    #+#             */
/*   Updated: 2022/11/12 18:23:49 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

int	ft_lenght_number(int number)
{
	int	len_number;

	len_number = 0;
	if (number < 0)
	{
		number *= -1;
		len_number++;
	}
	while (number != 0)
	{
		number = number / 10;
		len_number++;
	}
	return (len_number);
}

void	ft_write_number(int n)
{
	if (n == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		ft_pf_putnbr(147483648);
	}
	else if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
		ft_pf_putnbr(n);
	}
	else if (n > 9)
	{
		ft_pf_putnbr(n / 10);
		ft_pf_putnbr(n % 10);
	}
	else
	{
		n = n + 48;
		write(1, &n, 1);
	}
}

int	ft_pf_putnbr(int n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_write_number(n);
	return (ft_lenght_number(n));
}
