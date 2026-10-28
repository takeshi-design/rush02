/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_f2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 07:50:44 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/25 07:53:13 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	unsignedint_mes_hex(unsigned long n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

char	*sixteen_base(unsigned long n, char *hex_base)
{
	unsigned int	len;
	char			*str;

	len = unsignedint_mes_hex(n);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	str[len--] = hex_base[n % 16];
	n = n / 16;
	while (n > 0)
	{
		str[len--] = hex_base[n % 16];
		n = n / 16;
	}
	return (str);
}
