/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:10:35 by althorel          #+#    #+#             */
/*   Updated: 2025/07/09 11:51:10 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_letter(char c, va_list *ap, int *len)
{
	if (c == 'c')
		ft_putchar(va_arg(*ap, int), len);
	else if (c == 'i')
		ft_putnbr(va_arg(*ap, int), len);
	else if (c == 's')
		ft_putstr(va_arg(*ap, char *), len);
	else if (c == 'd')
		ft_putnbr_long(va_arg(*ap, int), len);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(*ap, unsigned int), len);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	char	*p;
	int		len;

	len = 0;
	i = 0;
	p = (char *)format;
	va_start (ap, format);
	if (!format)
		return (-1);
	while (p[i])
	{
		if (p[i] != '%')
			ft_putchar(p[i], &len);
		else
		{
			ft_check_letter(p[i + 1], &ap, &len);
			i++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
