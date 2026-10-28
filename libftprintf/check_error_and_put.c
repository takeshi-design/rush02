/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_and_put.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchijiwa <tchijiwa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 02:01:25 by tchijiwa          #+#    #+#             */
/*   Updated: 2026/10/29 03:54:40 by tchijiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_count(char c, int *count)
{
	if (*count == -1)
		return ;
	if (write(1, &c, 1) == -1)
	{
		*count = -1;
		return ;
	}
	(*count)++;
}

void	ft_putstr_count(char *str, int *count)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar_count(str[i], count);
		if (*count == -1)
			return ;
		i++;
	}
}

void	ft_putnbr_count(char *str, int *count)
{
	if (!str)
	{
		*count = -1;
		return ;
	}
	ft_putstr_count(str, count);
}
