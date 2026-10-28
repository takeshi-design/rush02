/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 19:34:06 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/25 07:12:00 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	va;
	va_list	va_cp;
	int		count;

	if (format == NULL)
		return (-1);
	va_start(va, format);
	va_copy(va_cp, va);
	va_end(va);
	count = put_str_printf(format, &va_cp);
	va_end(va_cp);
	return (count);
}
