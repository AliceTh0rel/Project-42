/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:20:30 by althorel          #+#    #+#             */
/*   Updated: 2025/08/18 14:38:50 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putchar(char c, int *len)
{
	write (1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *s, int *len)
{
	if (!s)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (*s)
	{
		ft_putchar(*s, len);
		s++;
	}
}

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', len);
		n *= -1;
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0', len);
	else
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
}

void	ft_putnbr_long(long int n, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', len);
		n *= -1;
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0', len);
	else
	{
		ft_putnbr_long(n / 10, len);
		ft_putnbr_long(n % 10, len);
	}
}

void	ft_putnbr_unsigned(unsigned int n, int *len)
{
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0', len);
	else
	{
		ft_putnbr_unsigned(n / 10, len);
		ft_putnbr_unsigned(n % 10, len);
	}
}
