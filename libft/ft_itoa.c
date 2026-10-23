/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:30:21 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/15 17:23:23 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	int_mes(int n)
{
	int		count;
	long	l;

	l = n;
	count = 1;
	if (l < 0)
	{
		count = count + 1;
		l = -l;
	}
	while (l >= 10)
	{
		l = l / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str_cnv;
	int		len;
	int		i;	

	len = int_mes(n);
	str_cnv = malloc(sizeof(char) * (len + 1));
	if (str_cnv == NULL)
		return (NULL);
	if (n < 0)
	{
		str_cnv[0] = '-';
		n = -n;
	}
	str_cnv[len--] = '\0';
	str_cnv[len--] = n % 10 + '0';
	i = i / 10;
	while (n > 0)
	{
		str_cnv[len--] = n % 10 + '0';
		n = n / 10;
	}
	return (str_cnv);
}
