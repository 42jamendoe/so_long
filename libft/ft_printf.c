/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:26:51 by jamendoe          #+#    #+#             */
/*   Updated: 2023/01/05 19:03:26 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

int	ft_print_var(va_list var, const char letter)
{
	int	charnmb;

	charnmb = 0;
	if (letter == 'c')
		charnmb += ft_pf_putchar(va_arg(var, int));
	else if (letter == 's')
		charnmb += ft_pf_putstr(va_arg(var, char *));
	else if (letter == 'p')
		charnmb += ft_print_pointer(va_arg(var, unsigned long long));
	else if (letter == 'd' || letter == 'i')
		charnmb += ft_pf_putnbr(va_arg(var, int));
	else if (letter == 'u')
		charnmb += ft_print_ui_number(va_arg(var, unsigned int));
	else if (letter == 'x' || letter == 'X')
		charnmb += ft_print_numberhex(va_arg(var, unsigned int), letter);
	else if (letter == '%')
		charnmb += ft_pf_putchar('%');
	return (charnmb);
}

int	ft_printf(const char *output, ...)
{
	int		i;
	va_list	var;
	int		alpha;

	i = 0;
	alpha = 0;
	va_start(var, output);
	while (output[i] != '\0')
	{
		if (output[i] == '%')
		{
			alpha += ft_print_var(var, output[i + 1]);
			i++;
		}
		else
			alpha += ft_pf_putchar(output[i]);
		i++;
	}
	va_end(var);
	return (alpha);
}
