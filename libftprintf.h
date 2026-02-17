/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:16:19 by algungor          #+#    #+#             */
/*   Updated: 2026/02/17 06:42:35 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	x_control(unsigned long n);
int	p_control(void *p);
int	ft_find(char c, va_list *ac);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putnbr(int n);

#endif
