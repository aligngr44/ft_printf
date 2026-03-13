/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:15:24 by algungor          #+#    #+#             */
/*   Updated: 2026/03/13 22:12:44 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		return (ft_x_control(va_arg(*ac, unsigned int), c));
	if (c == 'p')
		return (ft_p_control(va_arg(*ac, void *), c));
	if (c == 'u')
		return (ft_unnbr(va_arg(*ac, unsigned int)));
	return (-1);
}

static int	ft_percent(const char *format, int *i, va_list *ac)
{
	int	check;

	(*i)++;
	if (format[*i] == '\0')
		return (-1);
	check = ft_find(format[*i], ac);
	(*i)++;
	return (check);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		check;
	int		count;
	va_list	ac;

	i = 0;
	count = 0;
	va_start(ac, format);
	if (format[i] == '\0')
		return (-1);
	while (format[i])
	{
		check = 0;
		if (format[i] != '%')
			count += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			check = ft_percent(format, &i, &ac);
			if (check == -1)
				return (-1);
		}
		count += check;
	}
	va_end(ac);
	return (count);
}
