/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_at_the_specifier2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 07:44:14 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/29 04:06:24 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_at_x(va_list *va_copy, int *count)
{
	unsigned int	hex_small;
	char			*hex_base;
	char			*cvt_str;
	char			*head;

	hex_base = "0123456789abcdef";
	hex_small = va_arg(*va_copy, unsigned int);
	cvt_str = sixteen_base(hex_small, hex_base);
	head = cvt_str;
	ft_putnbr_count(cvt_str, count);
	if (cvt_str)
	{
		free(head);
		head = NULL;
		cvt_str = NULL;
	}
}

void	put_at_x_big(va_list *va_copy, int *count)
{
	unsigned int	hex_big;
	char			*hex_base;
	char			*cvt_str;
	char			*head;

	hex_base = "0123456789ABCDEF";
	hex_big = va_arg(*va_copy, unsigned int);
	cvt_str = sixteen_base(hex_big, hex_base);
	head = cvt_str;
	ft_putnbr_count(cvt_str, count);
	if (cvt_str)
	{
		free(head);
		head = NULL;
		cvt_str = NULL;
	}
}

void	put_at_p(va_list *va_copy, int *count)
{
	void			*address;
	unsigned long	address_num;
	char			*cvt_pointer;
	char			*head;

	address = va_arg(*va_copy, void *);
	if (!address)
	{
		ft_putstr_count("(nil)", count);
		return ;
	}
	address_num = (unsigned long)address;
	cvt_pointer = sixteen_base(address_num, "0123456789abcdef");
	head = cvt_pointer;
	ft_putstr_count("0x", count);
	ft_putnbr_count(cvt_pointer, count);
	if (cvt_pointer)
	{
		free(head);
		head = NULL;
		cvt_pointer = NULL;
	}
}
