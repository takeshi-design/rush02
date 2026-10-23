/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_at_the_specifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 08:27:59 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/23 20:01:17 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_at_c(va_list *va_copy)
{
	char	c;

	c = va_arg(*va_copy, char);
	write(1, &c, 1);
}

void	put_at_s(va_list *va_copy)
{
	char	*str;

	str = va_arg(*va_copy, char*);
	while (*str++)
		write(1, str, 1);
}

void	put_at_d(va_list *va_copy)
{
	int		k;
	char	*cvt_str;

	k = va_arg(*va_copy, int);
	cvt_str = ft_itoa(k);
	while (*cvt_str++)
		write(1, cvt_str, 1);
}

void	put_at_u(va_list *va_copy)
{
	unsigned int	n;
	char			*cvt_str_n;

	n = va_arg(*va_copy, unsigned int);
	cvt_str_n  = itoa_n(n);
	while (*cvt_str_n++)
		write(1, cvt_str_n, 1);
}

void	put_at_i(va_list *va_copy)
{
	int		i;
	char	*cvt_str;

	i = va_arg(*va_copy, int);
	cvt_str = ft_itoa(i);
	while (*cvt_str++)
		write(1, cvt_str, 1);
}

void	put_at_x(va_list *va_copy)
{
	unsigned int	hex_small;
	char			*hex_base;
	char			*cvt_str;

	hex_base = "0123456789abcdef";
	hex_small = va_arg(*va_copy, unsigned int);
	cvt_str = sixteen_base(hex_small, hex_base);
	while (*cvt_str)
		write(1, cvt_str, 1);
}

void	put_at_x(va_list *va_copy)
{
	unsigned int	hex_big;
	char			*hex_base;
	char			*cvt_str;

	hex_base = "0123456789ABCDEF";
	hex_big = va_arg(*va_copy, unsigned int);
	cvt_str = sixteen_base(hex_big, hex_base);
	while (*cvt_str)
		write(1, cvt_str, 1);
}

void	put_at_p(va_list *va_copy)
{
	void	*address;
	long	*address_num;
	char	*cvt_pointer;

	address = va_arg(*va_copy, void*);
	address_num = (long)address;
	
}