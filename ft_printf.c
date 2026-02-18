/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:15:24 by algungor          #+#    #+#             */
/*   Updated: 2026/02/17 06:42:18 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		check;
	int		count;
	va_list	ac;

	i = 0;
	count = 0;
	check = 0;
	va_start(ac, format);
	if (format[i] == '\0')
		return (-1);
	while (format[i])
	{
		check = 0;
		if (format[i] != '%')
		{
			count += ft_putchar(format[i]);
			i++;
		}
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			check = ft_find(format[i], &ac);
			i++;
		}
		count += check;
	}
	va_end(ac);
	return (count);
}
