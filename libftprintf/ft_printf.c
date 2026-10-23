/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 19:34:06 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/23 19:09:19 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"

//int	ft_printf(const char *format, ...)
//{
//	va_list	va;
//	va_list	va_cp;
//	int		count;

//	if (format == NULL)
//		return (-1);
//	va_start(va, format);
//	va_copy(va_cp, va);
//	count = 0;
//	//if (va_arg(va, int) != NULL || va_arg(va, void *) != NULL)
//	//	count++;
//	//if (!check_arg_cor(format, va_cp, count))
//	//	return (-1);
//	va_end(va);
//	put_str_printf(format, va_cp);
//	va_end(va_cp);
//	return ((int)strlen((char*)format));
//}

#include <stdio.h>
int	main()
{
	//char	c = '1';
	//printf("kknvdir%sa%c\n%", "hello", c);
	//printf("kknvdir%sa%c\n", "hello");
	//printf("kknvdir%sa%u\n", "hello", -15);
	printf("kknvdir%pa\n", "hello");
	//printf("kknvdir%sa%c\n%", "hello", c);
	//printf("kknvdir%sa%c\n%", "hello", c);
	return (0);
}