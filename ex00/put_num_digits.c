/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num_digits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatkawag <tatkawag@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 16:15:20 by tatkawag          #+#    #+#             */
/*   Updated: 2026/09/13 20:35:17 by tatkawag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	put_num_one_digit(char *num, t_dict *dicts)
{
	char	str[2];

	str[0] = num[0];
	str[1] = '\0';
	if (lookup_in_dict(str, dicts) != NULL)
	{
		ft_putstr(lookup_in_dict(str, dicts));
		return (0);
	}
	return (-1);
}

int	put_num_two_to_one(char *num, t_dict *dicts)
{
	if (num[1] != '0')
	{
		if (put_num_one_digit(&num[1], dicts) == -1)
			return (-1);
	}
	return (0);
}

int	put_num_two_digits(char *num, t_dict *dicts)
{
	char	str[3];

	if (num[0] == '0')
		return (put_num_two_to_one(num, dicts));
	str[0] = num[0];
	str[1] = num[1];
	str[2] = '\0';
	if ((num[0] == '1' || num[1] == '0') && lookup_in_dict(str, dicts) != NULL)
	{
		ft_putstr(lookup_in_dict(str, dicts));
		return (0);
	}
	str[1] = '0';
	if (lookup_in_dict(str, dicts) != NULL)
		ft_putstr(lookup_in_dict(str, dicts));
	write(1, "-", 1);
	str[1] = num[1];
	if (lookup_in_dict(&str[1], dicts) != NULL)
	{
		ft_putstr(lookup_in_dict(&str[1], dicts));
		return (0);
	}
	return (-1);
}

int	put_num_three_digits(char *num, t_dict *dicts)
{
	char	str[4];

	str[0] = num[0];
	str[1] = num[1];
	str[2] = num[2];
	str[3] = '\0';
	if (num[0] != '0')
	{
		str[1] = '\0';
		if (lookup_in_dict(str, dicts) == NULL)
			return (-1);
		ft_putstr(lookup_in_dict(str, dicts));
		ft_putstr(" ");
		if (lookup_in_dict("100", dicts) == NULL)
			return (-1);
		ft_putstr(lookup_in_dict("100", dicts));
		if (!(num[1] == '0' && num[2] == '0'))
			ft_putstr(" and ");
	}
	if (put_num_two_digits(&num[1], dicts) == -1)
		return (-1);
	return (0);
}
