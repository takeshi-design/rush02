/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_at_the_specifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 08:27:59 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/29 04:04:13 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_at_c(va_list *va_copy, int *count)
{
	int	c;

	c = va_arg(*va_copy, int);
	ft_putchar_count(c, count);
}

void	put_at_s(va_list *va_copy, int *count)
{
	char	*str;

	str = va_arg(*va_copy, char *);
	if (!str)
	{
		ft_putstr_count("(null)", count);
		return ;
	}
	ft_putstr_count(str, count);
}

void	put_at_d(va_list *va_copy, int *count)
{
	int		k;
	char	*head;
	char	*cvt_str;

	k = va_arg(*va_copy, int);
	cvt_str = ft_itoa(k);
	head = cvt_str;
	ft_putnbr_count(cvt_str, count);
	if (cvt_str)
	{
		free(head);
		head = NULL;
		cvt_str = NULL;
	}
}

void	put_at_u(va_list *va_copy, int *count)
{
	unsigned int	n;
	char			*head;
	char			*cvt_str_n;

	n = va_arg(*va_copy, unsigned int);
	cvt_str_n = ft_itoa_n(n);
	head = cvt_str_n;
	ft_putnbr_count(cvt_str_n, count);
	if (cvt_str_n)
	{
		free(head);
		head = NULL;
		cvt_str_n = NULL;
	}
}

void	put_at_i(va_list *va_copy, int *count)
{
	int		i;
	char	*head;
	char	*cvt_str;

	i = va_arg(*va_copy, int);
	cvt_str = ft_itoa(i);
	head = cvt_str;
	ft_putnbr_count(cvt_str, count);
	if (cvt_str)
	{
		free(head);
		head = NULL;
		cvt_str = NULL;
	}
}
