/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:24:12 by althorel          #+#    #+#             */
/*   Updated: 2025/05/19 14:49:17 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_letter(char c, va_list *ap, int *len)
{
	if (c == '%')
		ft_putchar('%', len);
	else if (c == 'c')
		ft_putchar(va_arg(*ap, int), len);
	else if (c == 'i')
		ft_putnbr(va_arg(*ap, int), len);
	else if (c == 's')
		ft_putstr(va_arg(*ap, char *), len);
	else if (c == 'd')
		ft_putnbr_long(va_arg(*ap, int), len);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(*ap, unsigned int), len);
	else if (c == 'p')
		ft_putnbr_void(va_arg(*ap, unsigned long), len);
	else if (c == 'x')
		ft_putnbr_lower(va_arg(*ap, unsigned int), len);
	else if (c == 'X')
		ft_putnbr_upper(va_arg(*ap, unsigned int), len);
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
/*
#include <limits.h>

int	main()

{
	int	i;
	
	i = ft_printf("Salut %c, %d, %s, %s, %i, %u, %%, %p, %p, %x, %X\n", 
	'v', 98, NULL, "kaka", -6, 89, "Prout", NULL, 78, 78);
	ft_printf("%d\n", i);
	ft_printf("Mon printf: %p, %p\n", LONG_MIN, LONG_MAX);
	printf(" Printf: %p %p \n", LONG_MIN, LONG_MAX);
	ft_printf("Mon printf 2: %p, %p\n", ULONG_MAX, -ULONG_MAX);
	printf(" Printf: %p %p \n", ULONG_MAX, -ULONG_MAX);
}
*/
