/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:02:03 by althorel          #+#    #+#             */
/*   Updated: 2025/05/19 12:28:46 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putnbr_long(long int n, int *len);
void	ft_putnbr_unsigned(unsigned int n, int *len);
void	ft_putnbr_lower(unsigned int n, int *len);
void	ft_putnbr_upper(unsigned int n, int *len);
void	ft_putnbr_void(unsigned long ptr, int *len);
void	ft_putnbr_lowervoid(unsigned long n, int *len);

#endif