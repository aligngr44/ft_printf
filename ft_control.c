/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:19:05 by algungor          #+#    #+#             */
/*   Updated: 2026/02/17 06:52:28 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	x_control(unsigned long i)
{
	unsigned int	x;

	x = 0;
	if (i == 0)
		return (0);
	x = x_control(i / 16);
	write(1, &"0123456789abcdef"[i % 16], 1);
	return (x + 1);
}
int	p_control(void *p)
{
	unsigned long	i;

	i = (unsigned long)p;
	if (i)
		write(1, "0x", 2);
	return (x_control(i) + 2);
}
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
int	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}
int	ft_putnbr(int n)
{
	long	total;
	long	s;

	s = n;
	if (s < 0)
	{
		write(1, "-", 1);
		s = -s;
	}
	if (s > 9)
	{
		ft_putnbr(s / 10);
		total = (s % 10) + 48;
		ft_putchar(total);
	}
	else if (s <= 9)
		ft_putchar(s + '0');
	return (s);
}

int	ft_find(char c, va_list *ac)
{
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'c')
		return (ft_putchar(va_arg(*ac, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*ac, char *)));
	if (c == 'd')
		return (ft_putnbr(va_arg(*ac, int)));
	if (c == 'i')
		return (ft_putnbr(va_arg(*ac, int)));
	if (c == 'x')
		return (x_control(va_arg(*ac, unsigned int)));
	if (c == 'p')
		return (p_control(va_arg(*ac, void *)));
	return (-1);
}
