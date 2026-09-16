/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatkawag <tatkawag@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 19:58:41 by tatkawag          #+#    #+#             */
/*   Updated: 2026/09/13 20:20:11 by tatkawag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	index;

	index = 0;
	while (s1[index] || s2[index])
	{
		if (s1[index] - s2[index] > 0)
			return (1);
		else if (s1[index] - s2[index] < 0)
			return (-1);
		index++;
	}
	return (0);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while ((s1[index] || s2[index]) && index < n)
	{
		if (s1[index] - s2[index] > 0)
			return (1);
		else if (s1[index] - s2[index] < 0)
			return (-1);
		index++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putstr_error(char *str)
{
	while (*str != '\0')
	{
		write(2, str, 1);
		str++;
	}
}
