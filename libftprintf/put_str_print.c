/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 06:52:22 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/29 04:35:31 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_specifier(const char *format, va_list *va_cp, int *count)
{
	format++;
	if (*format == '%')
		ft_putchar_count('%', count);
	if (*format == 'c')
		put_at_c(va_cp, count);
	if (*format == 's')
		put_at_s(va_cp, count);
	if (*format == 'd')
		put_at_d(va_cp, count);
	if (*format == 'u')
		put_at_u(va_cp, count);
	if (*format == 'i')
		put_at_i(va_cp, count);
	if (*format == 'x')
		put_at_x(va_cp, count);
	if (*format == 'X')
		put_at_x_big(va_cp, count);
	if (*format == 'p')
		put_at_p(va_cp, count);
}

int	can_insert_char(char next_c)
{
	if (next_c == '%')
		return (1);
	if (next_c == 'c')
		return (1);
	if (next_c == 's')
		return (1);
	if (next_c == 'd')
		return (1);
	if (next_c == 'u')
		return (1);
	if (next_c == 'i')
		return (1);
	if (next_c == 'x')
		return (1);
	if (next_c == 'X')
		return (1);
	if (next_c == 'p')
		return (1);
	return (0);
}

int	put_str_printf(const char *format, va_list *va_cp)
{
	int	count;

	count = 0;
	while (*format)
	{
		if (*format == '%' && can_insert_char(*(format + 1)))
		{
			check_specifier(format, va_cp, &count);
			format = format + 2;
		}
		else
		{
			ft_putchar_count(*format, &count);
			format++;
		}
		if (count == -1)
			return (count);
		
	}
	return (count);
}
