/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 06:52:22 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/23 13:47:29 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_specifier(const char *format, va_list *va_cp)
{
	format++;
	if (*format == '%')
		write(1, "%", 1);
	if (*format == 'c')
		put_at_c(*va_cp);
	if (*format == 's')
		put_at_s(*va_cp);
	if (*format == 'd')
		put_at_d(*va_cp);
	if (*format == 'u')
		put_at_u(*va_cp);
	if (*format == 'i')
		put_at_i(*va_cp);
	if (*format == 'x')
		put_at_x(*va_cp);
	if (*format == 'X')
		put_at_X(*va_cp);
	if (*format == 'p')
		put_at_p(*va_cp);
}

int	can_insert_char(char next_c)
{
	if (next_c = '%')
		return (1);
	if (next_c = 'c')
		return (1);
	if (next_c = 's')
		return (1);
	if (next_c = 'd')
		return (1);
	if (next_c = 'u')
		return (1);
	if (next_c = 'i')
		return (1);
	if (next_c = 'x')
		return (1);
	if (next_c = 'X')
		return (1);
	if (next_c = 'p')
		return (1);
	return (0);
}

void	put_str_print(const char *format, va_list va_cp)
{
	while (*format)
	{
		if (*format == '%')
		{
			if (can_insert_char(*(format + 1)))  /*次の文字を限定して条件付して*/
			{
				check_specifier(format, &va_cp);
				format = format + 2;
			}
		}
		else
		{
			write(1, format, 1);
			format++;
		}
	}
}
