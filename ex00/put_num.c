/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatkawag <tatkawag@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 15:02:17 by tatkawag          #+#    #+#             */
/*   Updated: 2026/09/13 20:28:15 by tatkawag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*lookup_in_dict(char *num, t_dict *dicts)
{
	int	dicts_idx;

	dicts_idx = 0;
	while (dicts[dicts_idx].num != NULL)
	{
		if (ft_strcmp(num, dicts[dicts_idx].num) == 0)
			return (dicts[dicts_idx].str);
		dicts_idx++;
	}
	return (NULL);
}

int	put_between_digits(char *num, int put_len, t_dict *dicts)
{
	ft_putstr(" ");
	if (put_big_num(ft_strlen(num) - put_len, dicts) == -1)
		return (-1);
	if (!is_rest_zero(num, put_len))
	{
		if (continue_zero(num, put_len))
			ft_putstr(" and ");
		else
			ft_putstr(",");
	}
	return (0);
}

int	put_num_block(char *num, int put_len, t_dict *dicts)
{
	if (put_len == 1)
	{
		if (put_num_one_digit(num, dicts) == -1)
			return (-1);
	}
	else if (put_len == 2)
	{
		if (put_num_two_digits(num, dicts) == -1)
			return (-1);
	}
	else if (put_len == 3)
	{
		if (put_num_three_digits(num, dicts) == -1)
			return (-1);
	}
	if (ft_strlen(num) != put_len && !(put_len == 3 && ft_strncmp(num, "000",
				3) == 0))
	{
		if (put_between_digits(num, put_len, dicts) == -1)
			return (-1);
	}
	return (0);
}

void	put_same_num(char *num, t_dict *dicts)
{
	if (is_similar_to_hundred(num, dicts))
	{
		ft_putstr(lookup_in_dict("1", dicts));
		ft_putstr(" ");
	}
	ft_putstr(lookup_in_dict(num, dicts));
	ft_putstr("\n");
}

int	put_num(char *num, t_dict *dicts)
{
	int	num_idx;
	int	put_len;

	ignore_extra_zero(&num);
	if (lookup_in_dict(num, dicts) != NULL)
	{
		put_same_num(num, dicts);
		return (0);
	}
	num_idx = 0;
	while (num[num_idx])
	{
		if (num_idx == 0 && ft_strlen(num) % 3 != 0)
			put_len = ft_strlen(num) % 3;
		else
			put_len = 3;
		if (put_num_block(&num[num_idx], put_len, dicts) == -1)
			return (-1);
		num_idx += put_len;
	}
	ft_putstr("\n");
	return (0);
}
