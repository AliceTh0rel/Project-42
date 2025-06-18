/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:51:05 by althorel          #+#    #+#             */
/*   Updated: 2025/05/19 12:25:41 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_lower(unsigned int n, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		ft_putnbr_lower(n / 16, len);
	ft_putchar(base[n % 16], len);
}

void	ft_putnbr_void(unsigned long ptr, int *len)
{
	if (ptr == 0)
	{	
		ft_putstr("(nil)", len);
		return ;
	}
	else
	{
		ft_putstr("0x", len);
		ft_putnbr_lowervoid(ptr, len);
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

void	ft_putnbr_upper(unsigned int n, int *len)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n >= 16)
		ft_putnbr_upper(n / 16, len);
	ft_putchar(base[n % 16], len);
}
