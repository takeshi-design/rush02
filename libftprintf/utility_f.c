/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 06:42:57 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/25 07:52:23 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

static int	int_mes(long n)
{
	int		count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		count = count + 1;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str_cnv;
	int		len;
	long	num;

	num = n;
	len = int_mes(num);
	str_cnv = malloc(sizeof(char) * (len + 1));
	if (str_cnv == NULL)
		return (NULL);
	if (num < 0)
	{
		str_cnv[0] = '-';
		num = -num;
	}
	str_cnv[len--] = '\0';
	str_cnv[len--] = num % 10 + '0';
	num = num / 10;
	while (num > 0)
	{
		str_cnv[len--] = num % 10 + '0';
		num = num / 10;
	}
	return (str_cnv);
}

static unsigned int	unsignedint_mes(unsigned int n)
{
	int		count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa_n(unsigned int n)
{
	char			*str_cnv;
	unsigned int	len;

	len = unsignedint_mes(n);
	str_cnv = malloc(sizeof(char) * (len + 1));
	if (str_cnv == NULL)
		return (NULL);
	str_cnv[len--] = '\0';
	str_cnv[len--] = n % 10 + '0';
	n = n / 10;
	while (n > 0)
	{
		str_cnv[len--] = n % 10 + '0';
		n = n / 10;
	}
	return (str_cnv);
}
