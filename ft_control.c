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

#include "ft_printf.h"

int	x_control(unsigned long i, char c)
{
	unsigned int	count;

	count = 0;
	if (i == 0)
		return (ft_putchar('0'));
	if (i >= 16)
		count += x_control(i / 16, c);
	if (c == 'X')
		count += write(1, &"0123456789ABCDEF"[i % 16], 1);
	else
		count += write(1, &"0123456789abcdef"[i % 16], 1);
	return (count);
}

int	p_control(void *p, char c)
{
	unsigned long	i;
	int				count;

	(void)c;
	i = (unsigned long)p;
	if (!p)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	count += x_control(i, 'x');
	return (count);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
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
	long	len;

	len = 0;
	s = n;
	if (s < 0)
	{
		len += write(1, "-", 1);
		s = -s;
	}
	if (s > 9)
	{
		len += ft_putnbr(s / 10);
		total = (s % 10) + 48;
		len += ft_putchar(total);
	}
	else if (s <= 9)
		len += ft_putchar(s + '0');
	return (len);
}
int ft_unnbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_unnbr(n / 10);          // önce üst basamakları yaz
	count += ft_putchar((n % 10) + '0');      // sonra son basamağı yaz
	return (count);
}


int	ft_find(char c, va_list *ac)
{
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'c')
		return (ft_putchar(va_arg(*ac, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*ac, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*ac, int)));
	if (c == 'i')
		return (ft_putnbr(va_arg(*ac, int)));
	if (c == 'x' || c == 'X')
		return (x_control(va_arg(*ac, unsigned int), c));
	if (c == 'p')
		return (p_control(va_arg(*ac, void *), c));
	if(c == 'u')
		return (ft_unnbr(va_arg(*ac, unsigned int)));
	return (-1);
}
